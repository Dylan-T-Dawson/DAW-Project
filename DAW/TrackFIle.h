//
// Created by dtda230 on 3/27/2023.
//

#ifndef DAW_TRACKFILE_H
#define DAW_TRACKFILE_H

#include <cstdio>
#include <string>

class TrackFile{
public:
    FILE* file;
    std::string fileName;

    //Time before audio starts
    double delay;
    //Time until audio ends
    double length;
};

#endif //DAW_TRACKFILE_H
