#include "Tank.hpp"
#include "Game.hpp"


Tank::Tank(int xCenterPos, int yCenterPos, float rotation)
{
    _xCenterPos = xCenterPos;
    _yCenterPos = yCenterPos;
    _rotation = rotation;
    _isDie = false;

    _defaultXPos = xCenterPos;
    _defaultYPos = yCenterPos;
    _defaultRotation = rotation;

    for(int i = 0; i < MAX_BULLETS; i++)
    {
        _bulletsOwned[i] = std::make_shared<Bullet>();
    }
}


Tank::~Tank()
{

}


void Tank::Init(std::shared_ptr<Tank> enemyTank)
{
    _enemyTank = enemyTank;

    while(_enemyTank == nullptr)
    {
        _enemyTank = enemyTank;
        std::cerr << "Enemy tank still null" << std::endl;
    }

    DrawCollider();
}

void Tank::Sync(TankState tankState)
{
    _xCenterPos = tankState.x;
    _yCenterPos = tankState.y;
    _rotation = tankState.rotation;
    _lastBulletFireTime = tankState._lastBulletFireTime;
    _isDie = tankState.isDie;
    if(_isDie)
    {
        std::cerr << "enemy tank is dead" << std::endl;
        TakeDamage();
    }

    // std::cout << "Sync: xCenterPos = " << _xCenterPos << ", yCenterPos = " << _yCenterPos << ", rotation = " << _rotation << ", lastBulletFireTime = " << _lastBulletFireTime << std::endl;

    // Update bullets based on the received state
    for (int i = 0; i < MAX_BULLETS; i++) {
        _bulletsOwned[i]->Sync(tankState._bulletsOwnedState[i]);
        // std::cout << "Bullet " << i << " synced: x = " << _bulletsOwned[i]->GetBulletState().x << ", y = " << _bulletsOwned[i]->GetBulletState().y << std::endl;
    }

    _tankCollider->Update();
}


TankState Tank::GetTankState()
{
    TankState newTankState;

    newTankState.x = _xCenterPos;
    newTankState.y = _yCenterPos;
    newTankState.rotation = _rotation;
    newTankState._lastBulletFireTime = _lastBulletFireTime;
    newTankState.isDie = _isDie;

    
    for(int i = 0; i < MAX_BULLETS; i++)
    {
        newTankState._bulletsOwnedState[i] = _bulletsOwned[i]->GetBulletState();
    }

    return newTankState;
}


//for self
void Tank::Update()
{
    Move();
    Fire();
    //DrawRender(RendererManager::GetInstance());

    _tankCollider->Update();
}




void Tank::Fire() {

    const Uint8* keyboardState = SDL_GetKeyboardState(nullptr);
    Uint32 currentTime = SDL_GetTicks();

    if (keyboardState[SDL_SCANCODE_F] && (currentTime - _lastBulletFireTime >= BULLET_FIRE_DELAY)) 
    {
        _lastBulletFireTime = currentTime; // Update the last fire time

        // Calculate the initial position of the bullet based on the turret's direction
        float bulletX = static_cast<float>(_xCenterPos) + (cos(_rotation * M_PI / 180));
        float bulletY = static_cast<float>(_yCenterPos) + (sin(_rotation * M_PI / 180));

        // Calculate the initial velocity of the bullet based on the tank's rotation
        float bulletVelocityX = cos(_rotation * M_PI / 180);
        float bulletVelocityY = sin(_rotation * M_PI / 180);
        
        for(int i = 0; i<MAX_BULLETS; i++)
        {
            if(!_bulletsOwned[i]->GetIsStarted())
            {
                _bulletsOwned[i]->Init(bulletX, bulletY, 0, bulletVelocityX, bulletVelocityY, _enemyTank);
                break;
            }
        }
    }
}



void Tank::UpdateBullets(std::shared_ptr<RendererManager> rendererManager) 
{
    for(int i = 0; i<MAX_BULLETS; i++)
    {
        if(_bulletsOwned[i]->GetIsStarted())
        {
            _bulletsOwned[i]->Update();
            _bulletsOwned[i]->DrawRender(rendererManager);
        }
    }
}



void Tank::Move()
{
    //top left corner of window is (0,0)
    const Uint8* keyboardState = SDL_GetKeyboardState(nullptr);
    
    int dx = 0;
    int dy = 0;

    if (keyboardState[SDL_SCANCODE_W]) {
        dy -= _tankSpeed;
    }
    if (keyboardState[SDL_SCANCODE_S]) {
        dy += _tankSpeed;
    }
    if (keyboardState[SDL_SCANCODE_A]) {
        dx -= _tankSpeed;
    }
    if (keyboardState[SDL_SCANCODE_D]) {
        dx += _tankSpeed;
    }
    

    // Calculate the rotation angle based on the movement direction
    if (dx != 0 || dy != 0) {
        _rotation = atan2(dy, dx) * 180 / M_PI; // Convert from radians to degrees
    }

    // Update the position using both dx and dy
    _xCenterPos += dx;
    _yCenterPos += dy;
}


void Tank::TakeDamage()
{
    _isDie = true;
    Game* GameInstance = Game::GetInstance();
    GameInstance->SetIsGameReseting(true);
}

void Tank::Reset()
{
    _xCenterPos = _defaultXPos;
    _yCenterPos = _defaultYPos;
    _rotation = _defaultRotation;
    _isDie = false;

    for(int i = 0; i < MAX_BULLETS; i++)
    {
        _bulletsOwned[i]->Reset();
    }

    _tankCollider->Update();
}


void Tank::SetTankState(std::shared_ptr<TankState> tankState) 
{
    _tankState = tankState;
}

void Tank::DrawRender(std::shared_ptr<RendererManager> rendererManager, SDL_Color tankColor, SDL_Color turretColor) {
    // Set the pivot point (center of the tank)
    SDL_Point pivot = {_xCenterPos, _yCenterPos};

    // Define the tank body dimensions and positions
    SDL_Rect tankRect = {_xCenterPos - _width / 2, _yCenterPos - _height / 2, _width, _height};

    // Draw the tank body as a rotated rectangle
    SDL_SetRenderDrawColor(rendererManager->GetRenderer().get(), tankColor.r, tankColor.g, tankColor.b, tankColor.a); // Tank color
    SDL_RenderFillRect(rendererManager->GetRenderer().get(), &tankRect);

    // Define the vertices for the filled turret triangle
    SDL_Point vertices[3] = {
        {pivot.x - 5, pivot.y - _height / 2}, // Top vertex
        {pivot.x + 5, pivot.y - _height / 2}, // Bottom-right vertex
        {pivot.x, pivot.y - _height} // Bottom vertex
    };

    // Rotate the vertices based on the tank's rotation angle
    float angle = (_rotation+90) * M_PI / 180.0;
    for (int i = 0; i < 3; i++) {
        int tempX = vertices[i].x - pivot.x;
        int tempY = vertices[i].y - pivot.y;
        vertices[i].x = pivot.x + tempX * cos(angle) - tempY * sin(angle);
        vertices[i].y = pivot.y + tempX * sin(angle) + tempY * cos(angle);
    }

    // Draw the filled turret triangle
    DrawFilledTriangle(rendererManager->GetRenderer().get(), vertices, turretColor);
}


void Tank::DrawFilledTriangle(SDL_Renderer* renderer, SDL_Point vertices[3], SDL_Color color) {
    int minX = std::min(std::min(vertices[0].x, vertices[1].x), vertices[2].x);
    int maxX = std::max(std::max(vertices[0].x, vertices[1].x), vertices[2].x);
    int minY = std::min(std::min(vertices[0].y, vertices[1].y), vertices[2].y);
    int maxY = std::max(std::max(vertices[0].y, vertices[1].y), vertices[2].y);

    for (int y = minY; y <= maxY; y++) {
        for (int x = minX; x <= maxX; x++) {
            int side1 = (vertices[1].x - vertices[0].x) * (y - vertices[0].y) - (vertices[1].y - vertices[0].y) * (x - vertices[0].x);
            int side2 = (vertices[2].x - vertices[1].x) * (y - vertices[1].y) - (vertices[2].y - vertices[1].y) * (x - vertices[1].x);
            int side3 = (vertices[0].x - vertices[2].x) * (y - vertices[2].y) - (vertices[0].y - vertices[2].y) * (x - vertices[2].x);

            if ((side1 >= 0 && side2 >= 0 && side3 >= 0) || (side1 < 0 && side2 < 0 && side3 < 0)) {
                SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
                SDL_RenderDrawPoint(renderer, x, y);
            }
        }
    }
}


void Tank::DrawCollider()
{   
    _tankCollider = ColliderFactory::CreateBoxCollider(_xCenterPos, _yCenterPos, _rotation, shared_from_this(), _width, _height);
}


std::shared_ptr<Collider2D> Tank::GetTankCollider()
{
    return _tankCollider;
}
