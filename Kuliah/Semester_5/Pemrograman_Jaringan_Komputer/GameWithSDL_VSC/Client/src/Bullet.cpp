#include "Bullet.hpp"

Bullet::Bullet()
{
   
}

Bullet::~Bullet()
{
    
}

BulletState Bullet::GetBulletState()
{
    std::cout << "get bullet state" << std::endl;

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
    std::cout << "sync bullet" << std::endl;

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

    DrawCollider();
    Update();
}

void Bullet::Init(float xInitPos, float yInitPos, float rotation, float xInitVelocity, float yInitVelocity, std::shared_ptr<Tank> enemyTank)
{
    std::cout << "init bullet" << std::endl;

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
    // _bulletCollider = ColliderFactory::CreateCircleCollider(_xCenterPos, _yCenterPos, _rotation, _enemyTank, _radius);
    _bulletCollider = ColliderFactory::CreateCircleCollider(_xCenterPos, _yCenterPos, _rotation, shared_from_this(), _radius);
}


void Bullet::Update()
{
    // Calculate the elapsed time since the bullet was created
    if(!_isStarted)
    {
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

    std::cerr << "\nupdate bullet collider" << std::endl;
    _bulletCollider->Update();

    // Check for collisions and apply any logic for hits on enemies here.
    std::cerr << "\ncheck bullet collision" << std::endl;
    if(_enemyTank == nullptr)
    {
        std::cerr << "enemy tank is null" << std::endl;
        return;
    }
    else
    {
        std::cerr << "enemy tank is not null" << std::endl;
        CheckCollision(_enemyTank->GetTankCollider());

    }
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
    std::cerr << "\ncheck bullet collision 2" << std::endl;

    if (!otherTankCollider)
    {
        std::cerr << "enemy tank collider is null" << std::endl;
        return;
    }
    else
    {
        std::cerr << "enemy tank collider is not null" << std::endl;
    }

    if (_bulletCollider->CheckCollision(otherTankCollider))
    {
        std::cerr << "enemy tank die" << std::endl;
        _enemyTank->TakeDamage();
    }
}


std::shared_ptr<Collider2D> Bullet::GetBulletCollider() 
const{
    return _bulletCollider;
};
