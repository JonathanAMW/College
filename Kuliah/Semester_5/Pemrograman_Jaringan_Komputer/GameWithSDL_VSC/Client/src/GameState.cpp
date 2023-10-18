// GameState.cpp
#include <iostream>

#include "GameState.hpp"

GameState::GameState() {
    // Initialize the game state as needed
    // You can add initial tank and bullet states here if necessary
}

//ambil state tank pemain dan set untuk dikirimkan
void GameState::SetThisClientTankAndItsBulletState(std::shared_ptr<Tank> playerTank) 
{
    _playerTankAndItsBulletState = playerTank->GetTankState();
}

//kembalikan nilai tnk pemain untuk dikirim nantinya
TankState GameState::GetThisClientTankAndItsBulletState()
{
    return _playerTankAndItsBulletState;
}


//set enemy tank state according to received data
void GameState::SyncThisClientOtherTankAndItsBulletState(std::shared_ptr<Tank> enemyTank) 
{
    enemyTank->Sync(_enemyTankAndItsBulletState);
}


void GameState::Serialize(char* buffer, int bufferSize) const {
    if (bufferSize < sizeof(TankState)) {
        std::cerr << "Buffer size is too small for serialization." << std::endl;
        return;
    }

    // Serialize player tank state
    memcpy(buffer, &_playerTankAndItsBulletState, sizeof(TankState));
}

void GameState::Deserialize(const char* buffer, int bufferSize) {
    if (bufferSize < sizeof(TankState)) {
        std::cerr << "Received buffer is too small for deserialization." << std::endl;
        return;
    }

    // Deserialize player tank state
    memcpy(&_enemyTankAndItsBulletState, buffer, sizeof(TankState));
}





// void GameState::PrintGameState() const {
//     std::cout << "Player Tank State:" << std::endl;
//     std::cout << "x: " << _playerTankAndItsBulletState.x << std::endl;
//     std::cout << "y: " << _playerTankAndItsBulletState.y << std::endl;
//     std::cout << "rotation: " << _playerTankAndItsBulletState.rotation << std::endl;

//     std::cout << "Bullets Owned:" << std::endl;
//     for (int i = 0; i < MAX_BULLETS; i++) {
//         std::cout << "Bullet " << i << ":" << std::endl;
//         std::cout << "x: " << _playerTankAndItsBulletState._bulletsOwnedState[i].x << std::endl;
//         std::cout << "y: " << _playerTankAndItsBulletState._bulletsOwnedState[i].y << std::endl;
//         // Print other bullet state members as needed
//     }
// }


