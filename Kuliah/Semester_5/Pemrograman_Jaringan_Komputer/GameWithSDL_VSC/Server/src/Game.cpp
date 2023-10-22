#include "Game.hpp"

std::shared_ptr<Tank> StoredInitializedTanks[MAX_PLAYERS];

std::shared_ptr<RendererManager> gameRenderer;  
std::shared_ptr<ConnectionManager> gameConnectionManager;  
std::shared_ptr<MainMenu> gameMainMenu;  

SDL_Color redColor = {255, 0, 0, 255}; // Red
SDL_Color blueColor = {0, 0, 255, 255}; // Blue
SDL_Color yellowColor = {255, 255, 0, 255};

bool firstInitByData = false;

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

    Player1->Init(Player2);
    Player2->Init(Player1);

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
                }
            } else if (gameMainMenu->IsClientSelected()) {
                _clientMode = ClientMode::CLIENT;
                if (gameConnectionManager->RunAsClient() != 0) {
                    // Handle client setup error
                }
            }
        } else {

            if (_clientMode == ClientMode::SERVER) {
                

                if(gameConnectionManager->ReceiveData(serverGameState, _clientMode))
                {
                    //std::cout << "server enemy tank updating\n";
                    serverGameState.SyncThisClientOtherTankAndItsBulletState(StoredInitializedTanks[1]);
                    // StoredInitializedTanks[1]->PrinTankStats();

                }

                StoredInitializedTanks[1]->DrawRender(gameRenderer, blueColor, yellowColor);
                StoredInitializedTanks[1]->UpdateBullets(gameRenderer);

                // Update and draw game objects using clientGameState
                StoredInitializedTanks[0]->Update();
                StoredInitializedTanks[0]->DrawRender(gameRenderer, redColor, yellowColor);
                StoredInitializedTanks[0]->UpdateBullets(gameRenderer);

                //set data from server and send it to client
                serverGameState.SetThisClientTankAndItsBulletState(StoredInitializedTanks[0]);
                
                if(!gameConnectionManager->SendData(serverGameState, _clientMode))
                {
                    std::cout << "\nSending Data Failed!\n";
                }
                


            } else if (_clientMode == ClientMode::CLIENT) {
                if(gameConnectionManager->ReceiveData(serverGameState, _clientMode))
                {
                    //std::cout << "server enemy tank updating\n";
                    serverGameState.SyncThisClientOtherTankAndItsBulletState(StoredInitializedTanks[1]);
                    // StoredInitializedTanks[1]->PrinTankStats();

                }

                StoredInitializedTanks[0]->DrawRender(gameRenderer, redColor, yellowColor);
                StoredInitializedTanks[0]->UpdateBullets(gameRenderer);

                StoredInitializedTanks[1]->Update();
                StoredInitializedTanks[1]->DrawRender(gameRenderer, blueColor, yellowColor);
                StoredInitializedTanks[1]->UpdateBullets(gameRenderer);


                //set data from client and send it to server
                clientGameState.SetThisClientTankAndItsBulletState(StoredInitializedTanks[1]);

                
                if(!gameConnectionManager->SendData(clientGameState, _clientMode))
                {
                    std::cout << "\nSending Data Failed!\n";
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