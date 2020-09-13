#include "raylib.h"
#include <iostream>

#include "src/state_handler/state_manager.h"
#include "src/states/test_state.h"

int main(void)
{
    InitWindow(800, 600, "raylib template - simple game");
    SetTargetFPS(60);

    StateManager* stateManager = StateManager::getInstance();

    /*State* currentState = new TestState();
    stateManager->setState(currentState);*/

    while (!WindowShouldClose())
    {
        stateManager->update();

        BeginDrawing();
        stateManager->render();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
