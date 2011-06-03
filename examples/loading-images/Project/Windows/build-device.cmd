arm-none-linux-gnueabi-g++ -o "..\..\Export\GettingStarted" "..\..\Source\GettingStarted.cpp" "..\..\Source\SDLStage.cpp" -I"%PalmPDK%\include" -L"%PalmPDK%\device\lib" -Wl,--allow-shlib-undefined -lSDL

call palm-package "..\..\Export" --exclude="*.exe" --exclude="*.ilk" --exclude="*.pdb" -o "..\..\"

call palm-install "..\..\com.palm.tutorial.cpp.gettingstarted_1.0.0_all.ipk"

call palm-launch com.palm.tutorial.cpp.gettingstarted
