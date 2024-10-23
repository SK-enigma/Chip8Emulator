#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Chip8.h"
#include "Platform.h"
#include <chrono>
#include <string>




int main(int argc, char** argv)
{
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <Scale> <Delay> <ROM>\n";
        std::exit(EXIT_FAILURE);
    }

    int videoScale = std::stoi(argv[1]);
    int cycleDelay = std::stoi(argv[2]);
    const char* romFilename = argv[3];
    
    try {
        Platform platform("CHIP-8 Emulator", VIDEO_WIDTH * videoScale, VIDEO_HEIGHT * videoScale, VIDEO_WIDTH, VIDEO_HEIGHT);
        Chip8 chip8;
        chip8.LoadROM(romFilename);

        int videoPitch = sizeof(chip8.video[0]) * VIDEO_WIDTH;
        auto lastCycleTime = std::chrono::high_resolution_clock::now();
        bool quit = false;

        while (!quit) {
            quit = platform.ProcessInput(chip8.keypad);

            auto currentTime = std::chrono::high_resolution_clock::now();
            float dt = std::chrono::duration<float, std::chrono::milliseconds::period>(currentTime - lastCycleTime).count();

            if (dt > cycleDelay) {
                lastCycleTime = currentTime;
                chip8.Cycle();
                platform.Update(chip8.video, videoPitch);
            }

            // Add a sleep to reduce CPU usage and allow for easier debugging
            //SDL_Delay(16); // roughly 60 FPS
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        std::cin.get(); // Wait for input to keep the console open
        return -1;
    }

   // std::cin.get(); // Keep the console open after exiting the loop
    return 0;
}

