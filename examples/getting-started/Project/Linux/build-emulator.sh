#!/bin/sh
i686-pc-linux-gnu-g++ -o ../../Export/GettingStarted ../../Source/GettingStarted.cpp ../../Source/SDLStage.cpp -I/opt/PalmPDK/include -Wl,--allow-shlib-undefined -lSDL
palm-package ../../Export -o ../../
palm-install ../../com.palm.tutorial.cpp.gettingstarted_1.0.0_all.ipk
palm-launch com.palm.tutorial.cpp.gettingstarted
