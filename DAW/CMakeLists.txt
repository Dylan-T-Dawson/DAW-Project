cmake_minimum_required(VERSION 3.16)
project(DAW)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CMakeLocal.txt OPTIONAL)

include_directories(${CMAKE_SOURCE_DIR}/lib)




find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Multimedia
        REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(DAW main.cpp mainwindow.cpp mainwindow.h mainwindow.ui
        TrackGUI.h TrackGUI.cpp TrackFile.h
        TrackFile.cpp audiorecorder.h audiorecorder.cpp audiolevel.h audiolevel.cpp)

target_link_libraries(DAW PRIVATE
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Multimedia

        )


