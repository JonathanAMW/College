#include "Game.hpp"

std::shared_ptr<Tank> StoredInitializedTanks[MAX_PLAYERS];

std::shared_ptr<RendererManager> gameRenderer;  
std::shared_ptr<ConnectionManager> gameConnectionManager;  
std::shared_ptr<MainMenu> gameMainMenu;  

SDL_Color redColor = {255, 0, 0, 255}; // Red
SDL_Color blueColor = {0, 0, 255, 255}; // Blue
SDL_Color yellowColor = {255, 255, 0, 255};

// bool firstInitByData = false;

// Game state initialization
GameState serverGameState;
GameState clientGameState;


void Game::Setup()
{
    gameRenderer = std::make_shared<RendererManager>();
    gameConnectionManager = std::make_shared<ConnectionManager>();
    gameMainMenu = std::make_shared<MainMenu>();


    //create and store tanks 
    std::shared_ptr<Tank> Player1 = std::make_shared<Tank>(200, 300, 0);
    std::shared_ptr<Tank> Player2 = std::make_shared<Tank>(600, 300, 180);
    
    StoredInitializedTanks[0] = Player1;
    StoredInitializedTanks[1] = Player2;

    StoredInitializedTanks[0]->Init(StoredInitializedTanks[1]);
    StoredInitializedTanks[1]->Init(StoredInitializedTanks[0]);

    Update();
}

void Game::Update() {
    bool isRunning = true;
    int mouseX, mouseY;
    bool roleSelected = false;

    while (isRunning) {
        SDL_Event event;
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                isRunning = false;
            }
        }

        SDL_SetRenderDrawColor(gameRenderer->GetRenderer().get(), 0, 0, 0, 255);
        SDL_RenderClear(gameRenderer->GetRenderer().get());

        if (!gameMainMenu->IsRoleSelected()) {
            int mouseX, mouseY;
            SDL_GetMouseState(&mouseX, &mouseY);
            gameMainMenu->HandleMouseClick(mouseX, mouseY);
            gameMainMenu->RenderMenu(gameRenderer->GetRenderer().get());
            if (gameMainMenu->IsServerSelected()) {
                _clientMode = ClientMode::SERVER;
                if (gameConnectionManager->RunAsServer() != 0) {
                    // Handle server setup error
                    isRunning = false;
                    std::cerr << "Running as server is failed" << std::endl;
                    break;

                }
            } else if (gameMainMenu->IsClientSelected()) {
                _clientMode = ClientMode::CLIENT;
                if (gameConnectionManager->RunAsClient() != 0) {
                    // Handle client setup error
                    isRunning = false;
                    std::cerr << "Running as client is failed" << std::endl;
                    break;

                }
            }
        } else {
            if(_IsGameReseting)
            {
                ResetMatch();
                _IsGameReseting = false;
            }

            if (_clientMode == ClientMode::SERVER) {
                StoredInitializedTanks[1]->DrawRender(gameRenderer, blueColor, yellowColor);
                StoredInitializedTanks[1]->UpdateBullets(gameRenderer);

                // Update and draw game objects using clientGameState
                StoredInitializedTanks[0]->Update();
                StoredInitializedTanks[0]->DrawRender(gameRenderer, redColor, yellowColor);
                StoredInitializedTanks[0]->UpdateBullets(gameRenderer);

                // //set data from server and send it to client
                // serverGameState.SetThisClientTankAndItsBulletState(StoredInitializedTanks[0]);

                //set data from server and send it to client
                serverGameState.SetThisClientTankAndItsBulletState(StoredInitializedTanks[0]);
                serverGameState.SetMatchState();

                if(!gameConnectionManager->SendData(serverGameState, _clientMode))
                {
                    std::cerr << "\nSending Data Failed!\n";
                }
                
                if(gameConnectionManager->ReceiveData(clientGameState, _clientMode))
                {
                    //std::cout << "server enemy tank updating\n";
                    clientGameState.SyncThisClientOtherTankAndItsBulletState(StoredInitializedTanks[1]);
                    clientGameState.SyncMatchState();
                    // StoredInitializedTanks[1]->PrinTankStats();

                }
                


            } else if (_clientMode == ClientMode::CLIENT) {
                if(gameConnectionManager->ReceiveData(serverGameState, _clientMode))
                {
                    //std::cout << "server enemy tank updating\n";
                    serverGameState.SyncThisClientOtherTankAndItsBulletState(StoredInitializedTanks[0]);
                    serverGameState.SyncMatchState();
                    // StoredInitializedTanks[1]->PrinTankStats();

                }

                StoredInitializedTanks[0]->DrawRender(gameRenderer, redColor, yellowColor);
                StoredInitializedTanks[0]->UpdateBullets(gameRenderer);

                StoredInitializedTanks[1]->Update();
                StoredInitializedTanks[1]->DrawRender(gameRenderer, blueColor, yellowColor);
                StoredInitializedTanks[1]->UpdateBullets(gameRenderer);


                //set data from client and send it to server
                clientGameState.SetThisClientTankAndItsBulletState(StoredInitializedTanks[1]);
                clientGameState.SetMatchState();

                
                if(!gameConnectionManager->SendData(clientGameState, _clientMode))
                {
                    std::cerr << "\nSending Data Failed!\n";
                }
                
            }

            // Update the renderer
            SDL_RenderPresent(gameRenderer->GetRenderer().get());
            SDL_Delay(16); // Aim for 60 FPS
        }
    }

    // Cleanup and exit
    SDL_Quit();
}

void Game::ResetMatch()
{
    if(StoredInitializedTanks[0] == nullptr && StoredInitializedTanks[1] == nullptr)
    {
        std::cerr << "tank is null" << std::endl;
        return;
    } 

    std::cerr << "\nResetting match..." << std::endl;   
    StoredInitializedTanks[0]->Reset();
    StoredInitializedTanks[1]->Reset();
}

bool Game::GetIsGameReseting()
{
    return _IsGameReseting;
}

void Game::SetIsGameReseting(bool value)
{
    _IsGameReseting = value;
}