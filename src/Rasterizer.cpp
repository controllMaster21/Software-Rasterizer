#include <iostream>
#include <SDL2/SDL.h>

#define WIDTH 1280
#define HEIGHT 720

SDL_Window* window;
SDL_Surface* windowSurface;

int init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Error initializing SDL: \n" << SDL_GetError() << std::endl;
        return 1;
    }

    window = SDL_CreateWindow("Rasterizer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    if (!window) {
        std::cerr << "Error creating window: \n" << SDL_GetError() << std::endl;
        return 2;
    }
}

void main(int argc, char* argv) {
    std::cout << "Hello World" << std::endl;
}