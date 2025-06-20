#include "GameLoop.h"

void GameLoop::Run() {
    Update();
    Render();
}

GameLoop::GameLoop() {
    m_Food = std::make_unique<Food>();
    m_Snake = std::make_unique<Snake>();
    m_GameOver = false;
    m_Score = 0;
}

void GameLoop::Update() {
    if(m_GameOver) {
        m_CurrentTime = GetTime();
        if(m_CurrentTime - m_LastTime < TIME_DELTA) {
            return;
        }
        if(IsKeyPressed(KEY_SPACE)) {
            m_GameOver = false;
            Reset();
            return;
        }
        return;
    }

    if(m_Snake->HasEatenSegment()) {
        m_GameOver = true;

        m_CurrentTime = GetTime();
        m_LastTime = m_CurrentTime;

        std::cout << "Game Over\n";
        return;
        // Reset();
    }

    m_Snake->Update();

    if(Vector2Equals(m_Snake->GetHeadPosition(), m_Food->GetPosition())){
        do {
            m_Food->SetNewPosition();
        }while(m_Snake->CheckIfPositionIsPartOfBody(m_Food->GetPosition()));
        m_Snake->AddSegment();
        m_Score++;
    }

    m_Food->Update();
}

void GameLoop::Render() {
    m_Snake->Draw();
    m_Food->Draw();

    DrawRectangleLinesEx(
            Rectangle{GameUtils::OFFSET - 5, GameUtils::OFFSET - 5, GameUtils::CELL_SIZE * GameUtils::CELL_COUNT + 10,
                (GameUtils::CELL_SIZE * GameUtils::CELL_COUNT) + 10}, 5, GameUtils::DARK_GREEN_COLOR);

    DrawText("Basic Snake", GameUtils::MIN_BOUND + GameUtils::OFFSET - 5,
        GameUtils::MIN_BOUND + 5, 20, GameUtils::DARK_GREEN_COLOR);
    DrawText(TextFormat("%i", m_Score), GameUtils::MIN_BOUND + GameUtils::OFFSET + 5,
        GameUtils::CELL_SIZE * GameUtils::MAX_BOUND + 10, 20, GameUtils::DARK_GREEN_COLOR);
}

void GameLoop::Reset() {
    m_Snake->Reset();
    m_Food->Reset();
    m_GameOver = false;
    m_LastTime = 0.f;
    m_CurrentTime = 0.f;
    m_Score = 0;
}