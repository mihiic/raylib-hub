#include "raylib.h"
#include <iostream>
#include <thread>
#include <future>
#include <chrono>

#include "src/state_handler/state_manager.h"

int main(void)
{
    InitWindow(800, 600, "raylib template - simple game");
    SetTargetFPS(60);

    StateManager* stateManager = stateManager->getInstance();

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
