#!/bin/sh
g++ -o ../../Export/GettingStarted ../../Source/GettingStarted.cpp ../../Source/SDLStage.cpp -I/opt/PalmPDK/include -I/opt/PalmPDK/include/SDL -L/opt/PalmPDK/host/lib -framework Cocoa -arch i386 -lSDL -lSDLmain
../../Export/GettingStarted
