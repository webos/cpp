#!/bin/sh
/opt/PalmPDK/arm-gcc/bin/arm-none-linux-gnueabi-g++ -o ../../Export/GettingStarted ../../Source/GettingStarted.cpp ../../Source/SDLStage.cpp -I/opt/PalmPDK/include -L/opt/PalmPDK/device/lib -Wl,--allow-shlib-undefined -lSDL
palm-package ../../Export -o ../../
palm-install ../../com.palm.tutorial.cpp.gettingstarted_1.0.0_all.ipk
palm-launch com.palm.tutorial.cpp.gettingstarted
