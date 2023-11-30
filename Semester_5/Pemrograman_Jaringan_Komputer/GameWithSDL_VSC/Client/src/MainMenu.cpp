#include <SDL2/SDL.h>

#include "MainMenu.hpp"

MainMenu::MainMenu()
{

}

MainMenu::~MainMenu()
{
    
}


void MainMenu::RenderMenu(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Draw the "Server" rectangle in red
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_Rect serverRect = {serverRectX, serverRectY, serverRectWidth, serverRectHeight};
    SDL_RenderFillRect(renderer, &serverRect);

    // Draw the "Client" rectangle in blue
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_Rect clientRect = {clientRectX, clientRectY, clientRectWidth, clientRectHeight};
    SDL_RenderFillRect(renderer, &clientRect);

    // Update the renderer
    SDL_RenderPresent(renderer);
}

void MainMenu::HandleMouseClick(int mouseX, int mouseY) {
    Uint32 mouseState = SDL_GetMouseState(&mouseX, &mouseY);

    if (mouseState & SDL_BUTTON(SDL_BUTTON_LEFT)) 
    {
        // Check if the mouse click is inside the "Server" rectangle
        if (mouseX >= serverRectX && mouseX <= serverRectX + serverRectWidth &&
            mouseY >= serverRectY && mouseY <= serverRectY + serverRectHeight) {
            isServerSelected = true;
            isRoleSelected = true;
        }
        // Check if the mouse click is inside the "Client" rectangle
        else if (mouseX >= clientRectX && mouseX <= clientRectX + clientRectWidth &&
                mouseY >= clientRectY && mouseY <= clientRectY + clientRectHeight) {
            isClientSelected = true;
            isRoleSelected = true;
        }
    }
}

bool MainMenu::IsServerSelected() {
    return isServerSelected;
}

bool MainMenu::IsClientSelected() {
    return isClientSelected;
}

bool MainMenu::IsRoleSelected()
{
    return isRoleSelected;
}


