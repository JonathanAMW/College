#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <memory>

#include "ConnectionManager.hpp"
#include "RendererManager.hpp"
#include "Tank.hpp"
#include "Bullet.hpp"
// #include "Collider2D.hpp"
#include "GameObject.hpp"
#include "MainMenu.hpp"
#include "GameState.hpp"
#include "Config.hpp"


class Game 
{
private:
    ClientMode _clientMode = ClientMode::DUMMY_VALUE;
    GameState serverGameState; // Game state object on the server
    GameState clientGameState; // Game state object on the client

    // Private constructor
    Game() {}
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

public:
    static Game* GetInstance() {
        static Game instance;
        return &instance;
    }

    void Update();
    void Setup();
    void ResetMatch();
};


#endif