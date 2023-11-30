#include "RendererManager.hpp"

// Static member initialization
std::shared_ptr<RendererManager> RendererManager::instance = nullptr;

RendererManager::RendererManager() {
    std::cout << "rendererManager get called\n";

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cerr << "SDL Initialization Error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    window = std::shared_ptr<SDL_Window>(SDL_CreateWindow("Game Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0), SDL_DestroyWindow);
    if (!window) {
        std::cerr << "Window Creation Error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    renderer = std::shared_ptr<SDL_Renderer>(SDL_CreateRenderer(window.get(), -1, 0), SDL_DestroyRenderer);
    if (!renderer) {
        std::cerr << "Renderer Creation Error: " << SDL_GetError() << std::endl;
        exit(1);
    }
}

RendererManager::~RendererManager() {
    // SDL_DestroyRenderer and SDL_DestroyWindow are called automatically via shared_ptr destructors
    SDL_Quit();
}

std::shared_ptr<RendererManager>& RendererManager::GetInstance() {
    if (!instance) {
        instance = std::make_shared<RendererManager>();
    }
    return instance;
}

std::shared_ptr<SDL_Renderer> RendererManager::GetRenderer() {
    return renderer;
}
