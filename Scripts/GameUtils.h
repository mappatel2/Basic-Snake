#pragma once
#include <raylib.h>

namespace GameUtils {

    constexpr Color GREEN_COLOR = {173, 204, 96, 255};
    constexpr Color DARK_GREEN_COLOR = {43, 51, 24, 255};

    constexpr int CELL_SIZE = 30;
    constexpr int CELL_COUNT = 30;

    constexpr int SCREEN_WIDTH = CELL_SIZE * CELL_COUNT;
    constexpr int SCREEN_HEIGHT = CELL_SIZE * CELL_COUNT;

    constexpr int OFFSET = 30;

    constexpr int MIN_BOUND = OFFSET / CELL_SIZE;
    constexpr int MAX_BOUND = CELL_COUNT + 1 - (int)(OFFSET / CELL_SIZE);

    inline Vector2 GenerateRandomPosition() {
        const auto x = static_cast<float>(GetRandomValue(MIN_BOUND, MAX_BOUND));
        const auto y = static_cast<float>(GetRandomValue(MIN_BOUND, MAX_BOUND));
        return Vector2{x, y};
    }
}
