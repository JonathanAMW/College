#ifndef TANK_HPP
#define TANK_HPP

#include <vector>

#include "GameObject.hpp"
#include "Collider2D.hpp"
#include "Bullet.hpp"
#include "RendererManager.hpp"
#include "GameState.hpp"
#include "Config.hpp"


#define BULLET_FIRE_DELAY 1500

class Bullet;
struct BulletState;
struct TankState;

class Tank : public GameObject, public std::enable_shared_from_this<Tank>
{    
private:
    std::shared_ptr<Collider2D> _tankCollider; 
    std::shared_ptr<Tank> _enemyTank; 
    float _tankSpeed = 2.0f;
    int _width = 30;
    int _height = 30;
    std::shared_ptr<Bullet> _bulletsOwned[MAX_BULLETS];
    Uint32 _lastBulletFireTime = 0;
    std::shared_ptr<TankState> _tankState;

public:
    Tank(int, int, float);
    ~Tank();
    void Fire();
    void Move();
    void DrawRender(std::shared_ptr<RendererManager> rendererManager, SDL_Color tankColor, SDL_Color turretColor);
    void DrawCollider();
    void Update();
    void Sync(TankState);
    void UpdateBullets(std::shared_ptr<RendererManager> rendererManager);
    void TakeDamage();
    void Init(std::shared_ptr<Tank> enemyTank);
    void DrawFilledTriangle(SDL_Renderer* renderer, SDL_Point vertices[3], SDL_Color color);
    std::shared_ptr<Collider2D> GetTankCollider();
    TankState GetTankState();
    void SetTankState(std::shared_ptr<TankState>);
    std::vector<std::shared_ptr<Bullet>> GetBulletsOwned();


    void PrinTankStats();

};  

#endif
