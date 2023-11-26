#pragma once
#include <SDL2/SDL_net.h>
#include <memory>

#include "Collider2D.hpp"
#include "Tank.hpp"
#include "RendererManager.hpp"
#include "GameState.hpp"

#define BULLET_LIFE_TIME 5000

class Tank;
struct BulletState;

class Bullet : public GameObject, public std::enable_shared_from_this<Bullet>
{
public:
    Bullet();
    ~Bullet();
    void DrawRender(std::shared_ptr<RendererManager>);
    void DrawCollider();
    void Update();
    void Sync(BulletState);
    BulletState GetBulletState();
    bool GetIsDestroyed();
    bool GetIsStarted();
    void CheckCollision(std::shared_ptr<Collider2D>);
    std::shared_ptr<Collider2D> GetBulletCollider() const;
    void Init(float xInitPos, float yInitPos, float rotation, float xInitVelocity, float yInitVelocity, std::shared_ptr<Tank> enemyTank);

    
private:
    std::shared_ptr<Collider2D> _bulletCollider;
    std::shared_ptr<Tank> _enemyTank;
    float _speed = 5;
    int _radius = 5;
    float _xVelocity, _yVelocity;
    Uint32 _startTime;
    Uint32 _currentTime;
    Uint32 _elapsedTime;
    bool _isDestroyed = false;
    bool _isStarted = false;
};