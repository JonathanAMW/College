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
    
     // Serialize the GameState into a byte array for sending
    void Serialize(char* buffer, int bufferSize) const;
    // Deserialize a byte array into a GameState object after receiving
    void Deserialize(const char* buffer, int bufferSize);

void GameState::Serialize(char* buffer, int bufferSize, std::string test) const; 
void GameState::Deserialize(const char* buffer, int bufferSize, std::string test) ;


    void PrintGameState() const;
private:
    TankState _playerTankAndItsBulletState; //something that will be set by this client and send to other client
    TankState _enemyTankAndItsBulletState; //something that will be set by data that received by other client
};

#endif
