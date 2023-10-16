
#pragma once


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


enum class ClientMode{
    DUMMY_VALUE,
    SERVER,
    CLIENT
};


class Game
{
private:
    ClientMode _clientMode = ClientMode::DUMMY_VALUE;
    GameState serverGameState; // Game state object on the server
    GameState clientGameState; // Game state object on the client
public:
    void Update();
    void Setup();
};