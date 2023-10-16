#include "Game.hpp"

std::shared_ptr<Tank> StoredInitializedTanks[MAX_PLAYERS];

std::shared_ptr<RendererManager> gameRenderer;  
std::shared_ptr<ConnectionManager> gameConnectionManager;  
std::shared_ptr<MainMenu> gameMainMenu;  

SDL_Color redColor = {255, 0, 0, 255}; // Red
SDL_Color blueColor = {0, 0, 255, 255}; // Blue
SDL_Color yellowColor = {255, 255, 0, 255};



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

    // Game state initialization
    GameState serverGameState;
    GameState clientGameState;

    while (isRunning && !roleSelected) {
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
            // Handle user input
            // Update game logic, tank positions, etc.
            if (_clientMode == ClientMode::SERVER) {
                bool IsValid = true;
                int receivedBytes = gameConnectionManager->ReceiveData(&clientGameState, sizeof(GameState));

                if (receivedBytes < 0) {
                    IsValid = false;
                }

                if(IsValid)
                {
                    serverGameState.SyncThisClientOtherTankAndItsBulletState(StoredInitializedTanks[1]);
                }
                
                StoredInitializedTanks[1]->DrawRender(gameRenderer, blueColor, yellowColor);
                StoredInitializedTanks[1]->UpdateBullets(gameRenderer);

                // Update and draw game objects using clientGameState
                StoredInitializedTanks[0]->Update();
                StoredInitializedTanks[0]->DrawRender(gameRenderer, redColor, yellowColor);
                StoredInitializedTanks[0]->UpdateBullets(gameRenderer);


                serverGameState.SetThisClientTankAndItsBulletState(StoredInitializedTanks[0]);
                gameConnectionManager->SendData(&serverGameState, sizeof(GameState));


            } else if (_clientMode == ClientMode::CLIENT) {
                bool IsValid = true;

                // Receive and update game state from the server
                // Deserialize the received game state into clientGameState
                int receivedBytes = gameConnectionManager->ReceiveData(&serverGameState, sizeof(GameState));
                if (receivedBytes < 0) {
                    IsValid = false;
                }

                if(IsValid)
                {
                    serverGameState.SyncThisClientOtherTankAndItsBulletState(StoredInitializedTanks[0]);
                }

                StoredInitializedTanks[0]->DrawRender(gameRenderer, redColor, yellowColor);
                StoredInitializedTanks[0]->UpdateBullets(gameRenderer);

                StoredInitializedTanks[1]->Update();
                StoredInitializedTanks[1]->DrawRender(gameRenderer, blueColor, yellowColor);
                StoredInitializedTanks[1]->UpdateBullets(gameRenderer);


                clientGameState.SetThisClientTankAndItsBulletState(StoredInitializedTanks[1]);
                gameConnectionManager->SendData(&clientGameState, sizeof(GameState));
            }

            // Update the renderer
            SDL_RenderPresent(gameRenderer->GetRenderer().get());
            SDL_Delay(16); // Aim for 60 FPS
        }
    }

    // Cleanup and exit
    SDL_Quit();
}




// void Game::Update() {
//     bool isRunning = true;

//     while (isRunning) {
//         // Handle events, such as quitting the game
//         SDL_Event event;
//         if (SDL_PollEvent(&event)) {
//             if (event.type == SDL_QUIT) {
//                 isRunning = false;
//             }
//         }

//         // Set the background color to black (R: 0, G: 0, B: 0, A: 255)
//         SDL_SetRenderDrawColor(gameRenderer->GetRenderer().get(), 0, 0, 0, 255);

//         // Clear the renderer with the background color
//         SDL_RenderClear(gameRenderer->GetRenderer().get());

//         if (!gameMainMenu->IsRoleSelected()) {
//             // Render the main menu
//             int mouseX, mouseY;
//             SDL_GetMouseState(&mouseX, &mouseY);
//             gameMainMenu->HandleMouseClick(mouseX, mouseY);
//             gameMainMenu->RenderMenu(gameRenderer->GetRenderer().get());
//             if(gameMainMenu->IsServerSelected())
//             {
//                 _clientMode = ClientMode::SERVER;
//             }
//             else if(gameMainMenu->IsClientSelected())
//             {
//                 _clientMode = ClientMode::CLIENT;
//             }
//         } else {
//             // Handle user input
//             // Update game logic, tank positions, etc.
//             if(_clientMode==ClientMode::SERVER)
//             {
//                 StoredInitializedTanks[0]->Update();
//             }
//             else if(_clientMode == ClientMode::CLIENT)
//             {
//                 StoredInitializedTanks[1]->Update();

//             }

//             // Draw game objects, including tanks
//             StoredInitializedTanks[0]->DrawRender(gameRenderer, redColor, yellowColor);
//             StoredInitializedTanks[1]->DrawRender(gameRenderer, blueColor, yellowColor);

//             // Update and draw the bullets for both tanks
//             StoredInitializedTanks[0]->UpdateBullets(gameRenderer);
//             StoredInitializedTanks[1]->UpdateBullets(gameRenderer);
//         }

//         // Update the renderer
//         SDL_RenderPresent(gameRenderer->GetRenderer().get());

//         // Optionally, control the frame rate by adding a delay
//         SDL_Delay(16); // Aim for 60 FPS (1000ms / 60)
//     }

//     // Cleanup and exit
//     SDL_Quit();
// }

