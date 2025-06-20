#pragma once
#include <memory>
#include "Food.h"
#include "Snake.h"

class GameLoop {

private:

    double m_CurrentTime = 0.f;
    double m_LastTime = 0.f;
    static constexpr double TIME_DELTA = 0.2f;
    bool m_GameOver = false;
    int m_Score;

private:

    void Update();
    void Render();
    void Reset();

    std::unique_ptr<Food> m_Food;
    std::unique_ptr<Snake> m_Snake;

public:
    GameLoop();
    ~GameLoop() = default;
    void Run();
};

