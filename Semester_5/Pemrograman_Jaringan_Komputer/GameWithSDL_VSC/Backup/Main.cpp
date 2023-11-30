#include<iostream>
#include<Game.hpp>

#undef main

int main(int argc, const char** argv) 
{
    // std::shared_ptr<Game> GameInstance = std::make_shared<Game>();
    Game* GameInstance = Game::GetInstance();

    GameInstance->Setup();

    
    return 0;
}