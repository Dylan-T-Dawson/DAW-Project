#include "mainwindow.h"
#include "ui_mainwindow.h"

//Declared global so it can be accessed by process functions

jack_port_t *output_port;
jack_client_t *client;

//Records from the default input device.
int process_record(jack_nframes_t nframes, void* arg)
{

    return 0;
}

//Plays audio from a .raw file. (Currently plays a note instead)
int process_play(jack_nframes_t nframes, void *arg)
{

    jack_default_audio_sample_t *out = (jack_default_audio_sample_t *)jack_port_get_buffer(output_port, nframes);

    // fill the output buffer with a sine wave
    static float phase = 0.0;
    float freq = 220.0;
    float delta = freq * 2.0 * M_PI / jack_get_sample_rate(client);

    for (int i = 0; i < nframes; i++) {
        out[i] = sin(phase);
        phase += delta;
    }

    return 0;
}

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

    // start the Jack server in a separate process

    /*
    jackProcess = new QProcess(this);
    QStringList arguments;
    arguments << "-d" << "jackdmp";
    jackProcess->start("jackd", arguments);
     */

    // open a client named "my_client"
    //client = jack_client_open("my_client", JackNullOption, NULL);

    // create an output port

    /*
    output_port = jack_port_register(client, "output", JACK_DEFAULT_AUDIO_TYPE, JackPortIsOutput, 0);
    jack_set_process_callback(client, process_play, 0);
    */

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
        for(int i = 0; i < trackFiles.size(); i++){
            fclose(trackFiles[i]->file);
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

    //This code can be ignored for now. It describes how to use jack to play audio.
    /*
    jack_set_process_callback(client, process_play, 0);
    jack_activate(client);
    jack_connect(client, jack_port_name(output_port), "system:playback_1");
    jack_connect(client, jack_port_name(output_port), "system:playback_2");
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    jack_deactivate(client);
     */

}

MainWindow::~MainWindow() {
    //Close all clients, terminate all processes, and close the window.
    /*
    jack_client_close(client);
    jackProcess->terminate();
    jackProcess->waitForFinished();
     */
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
    file->file = fopen((currentProject.c_str() + addT->audioFileName).c_str(), "wb");
    file->fileName = (currentProject.c_str() + addT->audioFileName).c_str();
    trackFiles.push_back(file);
    QObject::connect(addT->deleteTrack, SIGNAL(clicked()), this, SLOT(removeTrack()));
    //Add mute connect here
    sync();
}

//Ensures GUI elements, vectors, and filenames are updated after every action.
void MainWindow::sync(){
    //Ensures the trackFiles, tracks, and actual files are all synced up correctly.
    //Each file must be closed, renamed, and reopened.
    for(int i = 0; i < tracks.size(); i++){
        //Close the file under old name
        fclose(trackFiles[i]->file);
        tracks[i]->trackNumber = i;
        tracks[i]->deleteTrack->setProperty("trackNumber", i);
        tracks[i]->mute->setProperty("trackNumber", i);
        tracks[i]->label->setText("Track " + QString::number(i+1));
        tracks[i]->audioFileName = "Track " + QString::number(i+1).toStdString() + ".raw";
        rename(trackFiles[i]->fileName.c_str(), (currentProject + tracks[i]->audioFileName).c_str());
        trackFiles[i]->fileName = (currentProject + tracks[i]->audioFileName).c_str();
        trackFiles[i]->file = fopen(trackFiles[i]->fileName.c_str(), "wb");
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

    //Close the file associated with the track, delete associated file pointers and track information from vectors.
    //Clear those entries from the vectors and then sync.
    fclose(trackFiles[trackNumber]->file);
    delete tracks[trackNumber];
    tracks.erase(tracks.begin() + trackNumber);
    delete trackFiles[trackNumber];
    trackFiles.erase(trackFiles.begin() + trackNumber);
    numTracks--;
    sync();
}

//Clear and then repopulate the trackFiles and tracks vectors and change the current project.
void MainWindow::loadProject(){
    QString fileName = QFileDialog::getExistingDirectory(this, tr("Select Project"), "../Projects", QFileDialog::ShowDirsOnly );

    //Do nothing if no file is selected
    if(fileName == ""){
        return;
    }

    loaded = 1;

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
    for(int i = 0; i < trackFiles.size(); i++){
        fclose(trackFiles[i]->file);
    }

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

void MainWindow::quit() {
    QApplication::quit();
}