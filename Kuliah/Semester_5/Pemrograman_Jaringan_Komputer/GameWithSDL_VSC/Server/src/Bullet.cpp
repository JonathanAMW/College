#include "Bullet.hpp"

Bullet::Bullet()
{
   
}

Bullet::~Bullet()
{
    
}

BulletState Bullet::GetBulletState()
{
    BulletState newBulletState;
    newBulletState.x = _xCenterPos;
    newBulletState.x = _xCenterPos;
    newBulletState.y = _yCenterPos;
    newBulletState.xVelocity = _xVelocity;
    newBulletState.yVelocity = _yVelocity;
    newBulletState.rotation = _rotation;
    newBulletState._startTime = _startTime;
    newBulletState._elapsedTime = _elapsedTime;
    newBulletState._currentTime = _currentTime;
    newBulletState._isStarted = _isStarted;
    newBulletState._isDestroyed = _isDestroyed;

    return newBulletState;
}

void Bullet::Sync(BulletState bulletState)
{
    _xCenterPos = bulletState.x;
    _yCenterPos = bulletState.y;
    _xVelocity = bulletState.xVelocity;
    _yVelocity = bulletState.yVelocity;
    _rotation = bulletState.rotation;
    _startTime = bulletState._startTime;
    _elapsedTime = bulletState._elapsedTime;
    _currentTime = bulletState._currentTime;
    _isStarted = bulletState._isStarted;
    _isDestroyed = bulletState._isDestroyed;
}

void Bullet::Init(float xInitPos, float yInitPos, float rotation, float xInitVelocity, float yInitVelocity, std::shared_ptr<Tank> enemyTank)
{
    std::cout << "bulelt got init\n";
    _xCenterPos = xInitPos;
    _yCenterPos = yInitPos;
    _xVelocity = xInitVelocity;
    _yVelocity = yInitVelocity;
    _enemyTank = enemyTank;
    _rotation = rotation;
    _startTime = SDL_GetTicks();

    DrawCollider();
    Update();
}



void Bullet::DrawRender(std::shared_ptr<RendererManager> renderer) 
{
    SDL_SetRenderDrawColor(renderer->GetRenderer().get(), 255, 255, 255, 255); // Red color (adjust as needed)

    for (int w = -_radius; w <= _radius; w++) {
        for (int h = -_radius; h <= _radius; h++) {
            if (w * w + h * h <= _radius * _radius) {
                SDL_RenderDrawPoint(renderer->GetRenderer().get(), _xCenterPos + w, _yCenterPos + h);
            }
        }
    }
}

void Bullet::DrawCollider() 
{
    _bulletCollider = ColliderFactory::CreateCircleCollider(_xCenterPos, _yCenterPos, _rotation, _enemyTank, _radius);
}


void Bullet::Update()
{
    // Calculate the elapsed time since the bullet was created
    if(!_isStarted)
    {
        std::cout << "bulelt got started\n";

        _isStarted = true;
        _isDestroyed = false;
        _currentTime = SDL_GetTicks();
    }

    if(_isStarted)
    {
        _elapsedTime = _currentTime - _startTime;
        // Check if the bullet's lifetime has expired
        if (_elapsedTime >= BULLET_LIFE_TIME) {
            _isDestroyed = true;
            _currentTime = 0;
            _elapsedTime = 0;
            _startTime = 0;
            _isStarted = false;
            // Update the bullet's position
            _xCenterPos += 0;
            _yCenterPos += 0;
            return;
        }

        // Update the bullet's position
        _xCenterPos += _xVelocity * _speed;  
        _yCenterPos += _yVelocity * _speed; 

    }

    
    _bulletCollider->UpdateColliderPositionRotation();

    // Check for collisions and apply any logic for hits on enemies here.
    CheckCollision(_enemyTank->GetTankCollider());
}


bool Bullet::GetIsDestroyed()
{
    return _isDestroyed;
}

bool Bullet::GetIsStarted()
{
    return _isStarted;
}


void Bullet::CheckCollision(std::shared_ptr<Collider2D> otherTankCollider)
{
    if(_bulletCollider->CheckCollision(otherTankCollider))
    {
        _enemyTank->TakeDamage();
    }
}

std::shared_ptr<Collider2D> Bullet::GetBulletCollider() 
const{
    return _bulletCollider;
};