#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QTimer>
#include <QThread>

MainWindow::MainWindow(QWidget* parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);
    numTracks = 0;
    currentProject = "../Projects/Default/"; //Path to current project.


    //Connect buttons
    QObject::connect(ui->addTrack, SIGNAL(clicked()), this, SLOT(addTrack()));
    QObject::connect(ui->loadProjectButton, SIGNAL(clicked()), this, SLOT(loadProject()));
    QObject::connect(ui->deleteProjectButton, SIGNAL(clicked()), this, SLOT(deleteProject()));
    QObject::connect(ui->newProjectButton, SIGNAL(clicked()), this, SLOT(addProject()));
    QObject::connect(ui->playButton, SIGNAL(clicked()), this, SLOT(playAll()));
    QObject::connect(ui->stopPlay, SIGNAL(clicked()), this, SLOT(stopAll()));

    timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(sliderEvent()));
    timer->start(5);

    //Creates a default directory if one does not exist.
    std::string path = "../Projects/Default";
    QDir direct;
    direct.mkpath(QString::fromStdString(path));

    //If the user decides not to load a project upon start-up when prompted, the default project is loaded.
    loadProject();
    if(!loaded){

        currentProject = "../Projects/Default/";
        ui->projectNameLabel->setText("Default");

        //Clears track and trackfiles vectors while closing all fopened files.
        for(auto & trackFile : trackFiles){
            fclose(trackFile->file);
        }
        for(int i = 0; i < tracks.size(); i++){
            delete tracks[i];
            delete trackFiles[i];
        }
        trackFiles.clear();
        tracks.clear();
        std::string directoryPath = currentProject;

        //Adds a track to represent each raw file in the directory.
        int fileCount = 0;
        for (const auto& entry : std::filesystem::directory_iterator(directoryPath)) {
            if (entry.is_regular_file()) {
                fileCount++;
            }
        }
        numTracks = 0;
        for(int i = 0; i < fileCount; i++){
            addTrack();
        }
        sync();
    }



}

MainWindow::~MainWindow() {

    delete ui;
}

//Updates volume sliders
void MainWindow::sliderEvent(){
    for(int i = 0; i < currentPlaybacks.size(); i++){
        currentPlaybacks[i]->audioOutput()->setVolume(tracks[i]->volume->value()/100.0);
    }
}

//Adds a new track, including its GUI representation, corresponding .raw file, and File pointer (which goes in
//trackFiles vector). Connects its buttons to their appropriate functions.
void MainWindow::addTrack(){
    stopAll();
    TrackGUI *addT = new TrackGUI("Track " + QString::number(numTracks + 1), numTracks);
    ui->verticalLayout->insertLayout(numTracks, addT->track);
    numTracks++;

    addT->trackNumber = tracks.size();
    tracks.push_back(addT);

    TrackFile* file = new TrackFile;
    file->file = fopen((currentProject.c_str() + addT->audioFileName).c_str(), "ab");
    file->fileName = (currentProject.c_str() + addT->audioFileName).c_str();
    trackFiles.push_back(file);

    QObject::connect(addT->deleteTrack, SIGNAL(clicked()), this, SLOT(removeTrack()));
    QObject::connect(addT->recordTrack, SIGNAL(clicked()), this, SLOT(recordTrack()));
    QObject::connect(addT->playTrack, SIGNAL(clicked()), this, SLOT(playTrack()));
    QObject::connect(addT->mute, SIGNAL(clicked()), this, SLOT(muteTrack()));

    sync();
}

//Ensures GUI elements, vectors, and filenames are updated after every action.
void MainWindow::sync(){
    //Ensures the trackFiles, tracks, and actual files are all synced up correctly.
    //Each file must be closed, renamed, and reopened.
    for(int i = 0; i < tracks.size(); i++){
        //Close the file under old name
        fflush(trackFiles[i]->file);
        fclose(trackFiles[i]->file);
        tracks[i]->trackNumber = i;
        tracks[i]->deleteTrack->setProperty("trackNumber", i);
        tracks[i]->mute->setProperty("trackNumber", i);
        tracks[i]->label->setText("Track " + QString::number(i + 1));
        tracks[i]->audioFileName = "Track " + QString::number(i + 1).toStdString() + ".m4a";
        rename(trackFiles[i]->fileName.c_str(), (currentProject + tracks[i]->audioFileName).c_str());
        trackFiles[i]->fileName = (currentProject + tracks[i]->audioFileName).c_str();
        trackFiles[i]->file = fopen(trackFiles[i]->fileName.c_str(), "ab");
    }
    //Hides and shows addTrack button respective to whether or not the maximum number of tracks has been reached.
    if(numTracks == maxTrack) {
        ui->addTrack->hide();
    }else {
        if (ui->addTrack->isHidden()) {
            ui->addTrack->show();
        }
    }
}

void MainWindow::muteTrack(){

    QPushButton *buttonSender = qobject_cast<QPushButton *>(sender());
    int trackNumber = buttonSender->property("trackNumber").toInt();
    int playBack = -1;
    timer->stop();
    for(int i = 0; i < currentPlaybacks.size(); i++){
        if(currentPlaybacks[i]->property("trackN") == trackNumber){
            playBack = i;
            break;
        }
    }

    if(playBack == -1){
        return;
    }
    if(currentPlaybacks[playBack]->audioOutput()->isMuted() == true){
        currentPlaybacks[playBack]->audioOutput()->setMuted(false);
        tracks[trackNumber]->mute->setText("Mute");
    }else {
        currentPlaybacks[playBack]->audioOutput()->setMuted(true);
        tracks[trackNumber]->mute->setText("Unmute");
    }
    timer->start();

}

void MainWindow::removeTrack(){
    stopAll();
    QPushButton *buttonSender = qobject_cast<QPushButton *>(sender());
    int trackNumber = buttonSender->property("trackNumber").toInt();

    //Close the file associated with the track, remove it, delete associated file pointers and track information from vectors.
    //Clear those entries from the vectors and then sync.
    fclose(trackFiles[trackNumber]->file);
    remove(trackFiles[trackNumber]->fileName.c_str());
    delete tracks[trackNumber];
    tracks.erase(tracks.begin() + trackNumber);
    delete trackFiles[trackNumber];
    trackFiles.erase(trackFiles.begin() + trackNumber);
    numTracks--;
    sync();
    Reload();
}

void MainWindow::playTrack(){

    QPushButton *buttonSender = qobject_cast<QPushButton *>(sender());
    int trackNumber = buttonSender->property("trackNumber").toInt();

    for(int i = 0; i < currentPlaybacks.size(); i++){
        if(currentPlaybacks[i]->property("trackN") == trackNumber){
            tracks[i]->playTrack->setText("Play");
            emit currentPlaybacks[i]->mediaStatusChanged(QMediaPlayer::EndOfMedia);
            return;
        }
    }

    int fd = fileno(trackFiles[trackNumber]->file);
    float volume = (tracks[trackNumber])->volume->value() / 100.0;
    QFile file;
    file.open(fd, QIODevice::ReadOnly);
    QMediaPlayer *player = new QMediaPlayer;
    QAudioOutput *audioOutput = new QAudioOutput;

    player->setAudioOutput(audioOutput);
    audioOutput->setVolume(volume);
    //player->setSource(QUrl::fromLocalFile(file.fileName()));
    QString currentDir = QDir::currentPath(); // Get the absolute path of the current working directory
    QFileInfo currentInfo(currentDir); // Create a QFileInfo object for the current directory
    QString parentDir = currentInfo.dir().path(); // Get the path of the parent directory
    player->setSource(QUrl::fromLocalFile(parentDir + "/" + QString::fromStdString(currentProject).mid(3) + "Track " + QString::number(trackNumber + 1) + ".m4a"));

    player->play();
    tracks[trackNumber]->playTrack->setText("Stop");
    player->setProperty("trackN", trackNumber);
    currentPlaybacks.push_back(player);

    QObject::connect(player, &QMediaPlayer::mediaStatusChanged, [=](QMediaPlayer::MediaStatus status) {

        if (status == QMediaPlayer::EndOfMedia) {
            timer->stop();

            player->stop();
            tracks[trackNumber]->playTrack->setText("Play");
            delete player;
            delete audioOutput;
            for(int i = 0; i < currentPlaybacks.size(); i++){
                if(currentPlaybacks[i]->property("trackN") == trackNumber){
                    currentPlaybacks.erase(currentPlaybacks.begin() + i);
                }
            }
            timer->start();
        }

    });

}

void MainWindow::stopAll(){
    timer->stop();

    while(currentPlaybacks.empty() == false){

        emit currentPlaybacks[0]->mediaStatusChanged(QMediaPlayer::EndOfMedia);
    }

    timer->start();
}

void MainWindow::recordTrack() {
    ui->addTrack->hide();
    stopAll();
    QPushButton *buttonSender = qobject_cast<QPushButton *>(sender());

    //There is additional latency when first calling the record after executing the program. This
    //Calls and closes the recording GUI once without the user seeing it so that there is no additional
    //latency for the user.
    if(firstCalled){
        AudioRecorder *newAudioRecorder = new AudioRecorder(buttonSender, this, 0);
        emit initializeRec();
        firstCalled = false;
        delete newAudioRecorder;
    }

    int trackNumber = buttonSender->property("trackNumber").toInt();
    buttonSender->setProperty("project", QString::fromStdString(currentProject));
    int latencyCor = ui->latencyCorrection->text().toInt();
    int pos;
    int neg;
    if(latencyCor < 0){
        neg = abs(latencyCor);
        pos = 0;
    }else{
        neg = 0;
        pos = latencyCor;
    }

    AudioRecorder *newAudioRecorder = new AudioRecorder(buttonSender, this, neg);
    fclose(trackFiles[trackNumber]->file);
    remove(trackFiles[trackNumber]->fileName.c_str());
    newAudioRecorder->setWindowModality(Qt::ApplicationModal);
    newAudioRecorder->show();
    QEventLoop loop;
    QObject::connect(newAudioRecorder, SIGNAL(recordingFinished()), &loop, SLOT(quit()));
    connect(newAudioRecorder, SIGNAL(playTime()), this, SLOT(playAll()));

    emit recordingTime();

    QThread::msleep(pos);
    loop.exec();
    delete newAudioRecorder;
    sync();
    stopAll();
    for(int i = 0; i < tracks.size(); i++){
        tracks[i]->playTrack->setText("Play");
    }
    ui->addTrack->show();
}

//Clear and then repopulate the trackFiles and tracks vectors and change the current project.
void MainWindow::loadProject(){
    QString fileName = QFileDialog::getExistingDirectory(this, tr("Select Project"), "../Projects", QFileDialog::ShowDirsOnly );

    //Do nothing if no file is selected
    if(fileName == ""){
        return;
    }

    loaded = true;

    //Extract the project name from the entire file path name selected by the user. Store it in fnameForwards because
    //it is first extracted backwards and must be reversed.
    fullProjectPath = fileName.toStdString();
    std::string fname;
    int z = fileName.toStdString().length()-1;
    while(fileName.toStdString()[z] != -1 && fileName.toStdString()[z] != '/'){
        fname.push_back(fileName.toStdString()[z]);
        z--;
    }
    std::string fnameForwards;
    for(int w = fname.length()-1; w >= 0; w--){
        fnameForwards.push_back(fname[w]);
    }

    //Set the current project.
    currentProject = "../Projects/" + fnameForwards + "/";
    ui->projectNameLabel->setText(QString::fromStdString(fnameForwards));

    //Closes all files.
    for (auto & trackFile : trackFiles)
        fclose(trackFile->file);


    //Delete all File pointers and trackGUI information
    for(int i = 0; i < tracks.size(); i++){
        delete tracks[i];
        delete trackFiles[i];
    }

    //Clear vectors
    trackFiles.clear();
    tracks.clear();
    std::string directoryPath = currentProject;

    //Count number of files in the project to be loaded.
    int fileCount = 0;
    for (const auto& entry : std::filesystem::directory_iterator(directoryPath)) {
        if (entry.is_regular_file()) {
            fileCount++;
        }
    }
    numTracks = 0; //Reset the number of tracks.
    //Add a track to represent each file in the folder. This will be broken if the user manually renames files.
    for(int i = 0; i < fileCount; i++){
        addTrack();
    }
    sync();

}

//Deletes a project and all associated tracks.
void MainWindow::deleteProject(){
    QString fileName;
    //Loop ensures the current working project cannot be deleted.
    do {
        fileName = QFileDialog::getExistingDirectory(this, tr("Select Project"), "../Projects",
                                                             QFileDialog::ShowDirsOnly);
    }while(fileName.toStdString() == fullProjectPath);

    //Returns if no file is selected.
    if(fileName == ""){
        return;
    }

    std::filesystem::remove_all(fileName.toStdString().c_str());

}

void MainWindow::addProject(){
    QString pName = QInputDialog::getText(nullptr, "Enter project name", "Project");
    if(pName == ""){
        return;
    }
    //Returns if no name is specified, otherwise creates a new directory and prompts the user to load a project.
    std::string path = "../Projects/" + pName.toStdString();
    QDir direct;
    direct.mkpath(QString::fromStdString(path));
    loadProject();
}

void MainWindow::playAll(){
    std::cout << "Play" << std::endl;
    timer->stop();

    while(currentPlaybacks.empty() == false){

        emit currentPlaybacks[0]->mediaStatusChanged(QMediaPlayer::EndOfMedia);
    }

    timer->start();
    for(int i = 0; i < tracks.size(); i++){
        QPushButton *button = tracks[i]->playTrack;
        button->click();

    }
}

void MainWindow::quit() {
    QApplication::quit();
}

void MainWindow::onRecordingFinished() {
    // This slot will be called when the recordingFinished() signal is emitted.
    // You can put any code here that needs to be executed when the recording is finished, but currently
    //that is not needed.
}


void MainWindow::Reload(){
    for (auto & trackFile : trackFiles)
        fclose(trackFile->file);


    //Delete all File pointers and trackGUI information
    for(int i = 0; i < tracks.size(); i++){
        delete tracks[i];
        delete trackFiles[i];
    }

    //Clear vectors
    trackFiles.clear();
    tracks.clear();
    std::string directoryPath = currentProject;

    //Count number of files in the project to be loaded.
    int fileCount = 0;
    for (const auto& entry : std::filesystem::directory_iterator(directoryPath)) {
        if (entry.is_regular_file()) {
            fileCount++;
        }
    }
    numTracks = 0; //Reset the number of tracks.
    //Add a track to represent each file in the folder. This will be broken if the user manually renames files.
    for(int i = 0; i < fileCount; i++){
        addTrack();
    }
    sync();
}