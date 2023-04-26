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

//Adds a new track, including its GUI representation, corresponding .raw file, and File pointer (which goes in
//trackFiles vector). Connects its buttons to their appropriate functions.
void MainWindow::addTrack(){

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
    //Add mute connect here
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

void MainWindow::removeTrack(){
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
    int fd = fileno(trackFiles[trackNumber]->file);
    QFile file;
    file.open(fd, QIODevice::ReadOnly);
    QMediaPlayer *player = new QMediaPlayer;
    QAudioOutput *audioOutput = new QAudioOutput;
    player->setAudioOutput(audioOutput);
    audioOutput->setVolume(50);
    //player->setSource(QUrl::fromLocalFile(file.fileName()));
    QString currentDir = QDir::currentPath(); // Get the absolute path of the current working directory
    QFileInfo currentInfo(currentDir); // Create a QFileInfo object for the current directory
    QString parentDir = currentInfo.dir().path(); // Get the path of the parent directory
    player->setSource(QUrl::fromLocalFile(parentDir + "/" + QString::fromStdString(currentProject).mid(3) + "Track " + QString::number(trackNumber + 1) + ".m4a"));

    player->play();


    QObject::connect(player, &QMediaPlayer::mediaStatusChanged, [=](QMediaPlayer::MediaStatus status) {
        if (status == QMediaPlayer::EndOfMedia) {
            player->stop();
            delete player;
            delete audioOutput;
            std::cout << "Here" << std::endl;
        }
    });

}

void MainWindow::recordTrack() {

    QPushButton *buttonSender = qobject_cast<QPushButton *>(sender());

    int trackNumber = buttonSender->property("trackNumber").toInt();
    buttonSender->setProperty("project", QString::fromStdString(currentProject));

    AudioRecorder *newAudioRecorder = new AudioRecorder(buttonSender, this);
    fclose(trackFiles[trackNumber]->file);
    remove(trackFiles[trackNumber]->fileName.c_str());
    newAudioRecorder->setWindowModality(Qt::ApplicationModal);
    newAudioRecorder->show();
    QEventLoop loop;
    QObject::connect(newAudioRecorder, SIGNAL(recordingFinished()), &loop, SLOT(quit()));

    emit recordingTime();

    playAll();
    loop.exec();
    sync();


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
    // You can put any code here that needs to be executed when the recording is finished.
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