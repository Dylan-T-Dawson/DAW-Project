//Purpose is to provide the implementation of functions to create projects and access tracks.
//Might wrap tracks in a class so we can easily track their position on the playback area.
//This file is just basic logic to create, move, and delete tracks and projects. However,
//in this example code, the tracks will be represented by text files rather than audio files.
//Then, after the logic is complete, it will be altered to work with audio files.

#include <iostream>
#include <direct.h>

using namespace std;

int main(){
    if(mkdir("E:/MyFolder") == -1)
        cerr << " Error : " << strerror(errno) << endl;
    else
        cout << "File Created";
}