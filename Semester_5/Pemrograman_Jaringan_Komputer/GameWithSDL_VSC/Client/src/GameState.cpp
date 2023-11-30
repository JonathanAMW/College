// GameState.cpp
#include <iostream>

#include "GameState.hpp"
#include "Game.hpp"

GameState::GameState() {
    // Initialize the game state as needed
    // You can add initial tank and bullet states here if necessary
}

//ambil state tank pemain dan set untuk dikirimkan
void GameState::SetThisClientTankAndItsBulletState(std::shared_ptr<Tank> playerTank) 
{
    _playerTankAndItsBulletState = playerTank->GetTankState();
}

// //kembalikan nilai tnk pemain untuk dikirim nantinya
// TankState GameState::GetThisClientTankAndItsBulletState()
// {
//     return _playerTankAndItsBulletState;
// }

//set enemy tank state according to received data
void GameState::SyncThisClientOtherTankAndItsBulletState(std::shared_ptr<Tank> enemyTank) 
{
    enemyTank->Sync(_enemyTankAndItsBulletState);
}


void GameState::SyncMatchState()
{
    Game *game = Game::GetInstance();
    game->SetIsGameReseting(_matchState.IsGameReseting);
}

void GameState::SetMatchState()
{
    _matchState.IsGameReseting = Game::GetInstance()->GetIsGameReseting();
}



void GameState::Serialize(char* buffer, int bufferSize) const {
    if (bufferSize < sizeof(GameState)) {
        std::cerr << "Buffer size is too small for serialization." << std::endl;
        return;
    }

    // Serialize player tank state
    memcpy(buffer, &_playerTankAndItsBulletState, sizeof(TankState));
    memcpy(buffer, &_matchState, sizeof(MatchState));
}

void GameState::Deserialize(const char* buffer, int bufferSize) {
    if (bufferSize < sizeof(GameState)) {
        std::cerr << "Received buffer is too small for deserialization." << std::endl;
        return;
    }

    // Deserialize player tank state
    memcpy(&_enemyTankAndItsBulletState, buffer, sizeof(TankState));
    memcpy(&_matchState, buffer, sizeof(MatchState));
}