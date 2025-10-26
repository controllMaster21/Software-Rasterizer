#include <iostream>
#include <SDL2/SDL.h>
#include <sys/resource.h>

#include "Math/Triangle.hpp"
#include "Rendering/Camera.hpp"
#include "Rendering/Mesh.hpp"

#define WIDTH 1280
#define HEIGHT 720

SDL_Window* window;
SDL_Surface* windowSurface;
MeshFile suzanne = MeshFile("/home/viko/Projekte/c++/Software-Rasterizer/suzanne.obj");

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

    windowSurface = SDL_GetWindowSurface(window);
    if (!windowSurface) {
        std::cerr << "Error fetching window surface: \n" << SDL_GetError() << std::endl;
        return 3;
    }
    return 0;
}

void renderFrame() {
    Camera cam = Camera();

    Mesh testMesh = suzanne.convertToMesh();
    testMesh.pos = vec3(0, 0, -0.5);

    Mesh transformed = testMesh.getTransformed(cam);
    
    Triangle2D render = transformed.tris.at(0).to2D();
    const Bounds bounds = render.getBounds();

    std::cout << bounds.topLeftX << " " << bounds.topLeftY << " " << bounds.bottomRightX << " " << bounds.bottomRightY << std::endl;

    for (int x = bounds.topLeftX; x <= bounds.bottomRightX; x++) {
        for (int y = bounds.topLeftY; y <= bounds.bottomRightY; y++) {
            if (render.pointInside(vec2(x, y))) {
                SDL_FillRect(windowSurface, new SDL_Rect{x + WIDTH / 2, y + HEIGHT / 2, 1, 1}, 0xffff0000);
            }
        }
    }

    SDL_UpdateWindowSurface(window);

}

int main(int argc, char** argv) {
    if (init() != 0) {
        return -1;
    }

    renderFrame();
    SDL_Delay(5000);

}