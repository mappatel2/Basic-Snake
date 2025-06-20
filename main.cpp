#include <raylib.h>
#include "Scripts/GameUtils.h"
#include "Scripts/GameLoop.h"

int main()
{
    InitWindow((2 * GameUtils::OFFSET) + GameUtils::SCREEN_WIDTH,
        (2 * GameUtils::OFFSET) + GameUtils::SCREEN_HEIGHT,
        "Retro Snake");

    GameLoop gameLoop = GameLoop();
    SetTargetFPS(60);

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(GameUtils::GREEN_COLOR);
        gameLoop.Run();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
