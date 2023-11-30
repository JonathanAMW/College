#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include <SDL2/SDL.h>
#include <string>

class MainMenu 
{
private:
    // Define the coordinates and dimensions of the rectangles
    int serverRectX = 100;
    int serverRectY = 200;
    int serverRectWidth = 200;
    int serverRectHeight = 50;

    int clientRectX = 100;
    int clientRectY = 300;
    int clientRectWidth = 200;
    int clientRectHeight = 50;

    bool isServerSelected = false;
    bool isClientSelected = false;
    bool isRoleSelected = false;
public:
    void RenderMenu(SDL_Renderer* renderer);
    void HandleMouseClick(int mouseX, int mouseY);
    MainMenu();
    ~MainMenu();
    bool IsServerSelected();
    bool IsClientSelected();
    bool IsRoleSelected();
};

#endif