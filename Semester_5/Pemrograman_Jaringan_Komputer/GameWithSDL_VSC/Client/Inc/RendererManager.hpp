#ifndef RENDERER_MANAGER_HPP
#define RENDERER_MANAGER_HPP

#include <SDL2/SDL.h>
#include <iostream>
#include <cmath>
#include <memory> // Include for smart pointers

class RendererManager {
private:
    std::shared_ptr<SDL_Window> window;
    std::shared_ptr<SDL_Renderer> renderer;

    

    // Delete the copy constructor and assignment operator to prevent cloning
    RendererManager(const RendererManager&) = delete;
    RendererManager& operator=(const RendererManager&) = delete;

    static std::shared_ptr<RendererManager> instance;

public:

    // Private constructor and destructor to prevent external instantiation and destruction
    RendererManager();
    ~RendererManager();
    
    // Method to get the Singleton instance
    static std::shared_ptr<RendererManager>& GetInstance();

    // Method to get the renderer
    std::shared_ptr<SDL_Renderer> GetRenderer();

    void DrawObject(float, float, float, const float verticies[][2], size_t, Uint8);
};

#endif