#include "raylib.h"
#include <iostream>
#include <thread>
#include <future>
#include <chrono>

using namespace std::chrono_literals;

typedef enum GameScreen
{
    LOGO = 0,
    TITLE,
    GAMEPLAY,
    ENDING
} GameScreen;

void system_call_from_thread()
{
    std::cout << "Thread function\n";
}

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "raylib template - simple game");
    GameScreen currentScreen = LOGO;
    int framesCounter = 0;
    SetTargetFPS(60);

    auto future = std::async(std::launch::async, [] {
        std::this_thread::sleep_for(3s);
        return 8;
    });

    while (!WindowShouldClose())
    {
        if (future.valid()) {
            auto status = future.wait_for(0ms);
            if (status == std::future_status::ready) {
                std::cout << "AJMOOOOOOOOO " << future.get() << std::endl;
            }
        }

        switch (currentScreen)
        {
        case LOGO:
        {
            framesCounter++;
            if (framesCounter > 120)
            {
                currentScreen = TITLE;
            }
        }
        break;
        case TITLE:
        {
            if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
            {
                currentScreen = GAMEPLAY;
            }
        }
        break;
        case GAMEPLAY:
        {
            if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
            {
                currentScreen = ENDING;
            }
        }
        break;
        case ENDING:
        {
            if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
            {
                currentScreen = TITLE;
            }
        }
        break;
        default:
            break;
        }
        BeginDrawing();
        ClearBackground(RAYWHITE);
        switch (currentScreen)
        {
        case LOGO:
        {
            DrawText("LOGO SCREEN", 20, 20, 40, LIGHTGRAY);
            DrawText("WAIT for 2 SECONDS...", 290, 220, 20, GRAY);
        }
        break;
        case TITLE:
        {
            DrawRectangle(0, 0, screenWidth, screenHeight, GREEN);
            DrawText("TITLE SCREEN", 20, 20, 40, DARKGREEN);
            DrawText("PRESS ENTER or TAP to JUMP to GAMEPLAY SCREEN", 120, 220, 20, DARKGREEN);
        }
        break;
        case GAMEPLAY:
        {
            DrawRectangle(0, 0, screenWidth, screenHeight, PURPLE);
            DrawText("GAMEPLAY SCREEN", 20, 20, 40, MAROON);
            DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, MAROON);
        }
        break;
        case ENDING:
        {
            DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
            DrawText("ENDING SCREEN", 20, 20, 40, DARKBLUE);
            DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, DARKBLUE);
        }
        break;
        default:
            break;
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
