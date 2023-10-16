#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP
#pragma once

#include <vector>


#include "Tank.hpp"
#include "Config.hpp"

class Tank;

struct BulletState {
    int x;
    int y;
    float xVelocity;
    float yVelocity;
    Uint32 _startTime;
    bool _isDestroyed = false;
    Uint32 _currentTime;
    Uint32 _elapsedTime;
    bool _isStarted = false;
    float rotation;
};

struct TankState {
    float x;
    float y;
    float rotation;
    BulletState _bulletsOwnedState[MAX_BULLETS];
    Uint32 _lastBulletFireTime;
};


class GameState {
public:
    GameState(); // Constructor to initialize the game state
    void SetThisClientTankAndItsBulletState(std::shared_ptr<Tank>);
    TankState GetThisClientTankAndItsBulletState();
    void SyncThisClientOtherTankAndItsBulletState(std::shared_ptr<Tank>);
    

private:
    TankState _playerTankAndItsBulletState;
    TankState _enemyTankAndItsBulletState;
};

#endif
