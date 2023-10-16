// GameState.cpp
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

//kembalikan nilai 
TankState GameState::GetThisClientTankAndItsBulletState()
{
    return _playerTankAndItsBulletState;
}

void GameState::SyncThisClientOtherTankAndItsBulletState(std::shared_ptr<Tank> enemyTank) 
{
    enemyTank->Sync(_enemyTankAndItsBulletState);
}

