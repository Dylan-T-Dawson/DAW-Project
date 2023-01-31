//Purpose is to provide the implementation of functions to create projects and access tracks.
//Might wrap tracks in a class so we can easily track their position on the playback area.
//This file is just basic logic to create, move, and delete tracks and projects. However,
//in this example code, the tracks will be represented by text files rather than audio files.
//Then, after the logic is complete, it will be altered to work with audio files.
//g++ -o fileI.exe fileImplementation.cpp

#include <iostream>
#include <direct.h>
#include <filesystem>
#include <fstream>
#include <stdio.h>
#include <string>
using namespace std;

void mkProject(string name);
void rmProject(string name);
void addTrack(string project, string track);
void delTrack(string project, string track);

int main(){

    string command;
    string Pname;
    string Tname;
    while(command != "exit"){
        cout << "Type either mkP, addT, rmP, rmT, or exit" << endl;
        cin >> command;
        if(command == "mkP"){
            cout << "Enter the name of the new project" << endl;
            cin >> Pname;
            mkProject(Pname);
        }else if(command == "addT"){
            cout << "Enter the name of the project to which you want to add a track." << endl;
            cin >> Pname;
            cout << "Enter the name of the track you would like to create" << endl;
            cin >> Tname;
            addTrack(Pname, Tname);
        }else if(command == "rmP"){
            cout << "Enter the name of the project you would like to delete" << endl;
            cin >> Pname;
            rmProject(Pname);
        }else if(command == "delT"){
            cout << "Enter the name of the project you would like to delete a track from" << endl;
            cin >> Pname;
            cout << "Enter the name of the track you would like to delete" << endl;
            cin >> Tname;
            delTrack(Pname, Tname);
        }
    }
    return 0;
}

void mkProject(string name){
    _mkdir(("Tracks\\" + name).c_str());
}

void rmProject(string name){
    filesystem::remove_all(("Tracks\\" + name));
}

void addTrack(string project, string track){
    
    string fname = "Tracks\\" + project + "\\" + track + ".txt";
    ofstream file (fname);
    file.close();
}

void delTrack(string project, string track){
    string fname = "Tracks\\" + project + "\\" + track + ".txt";
    remove(fname.c_str());
}