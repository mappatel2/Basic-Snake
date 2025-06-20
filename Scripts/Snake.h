#pragma once
#include "Entity.h"
#include <deque>

class Snake : public Entity{
private:
    std::deque<Vector2> m_Body ;
    Vector2 m_Direction  = {1, 0};
    Vector2 m_TempDirection = {0, 0};

    double m_LastMoveTimer = 0.f;
    static constexpr double MOVE_TIMER_INTERVAL = 0.2f;
    double m_CurrentMoveTimer = 0.f;

    bool m_AddSegment = false;

public:
    Snake();
    ~Snake() override;

    void Update() override;
    void Draw() override;
    void Reset() override;

    void Init();
    void SetDirection();
    Vector2 GetHeadPosition() const;
    Vector2 GetTailPosition() const;
    void ClampMovement();
    void AddSegment();
    bool CheckIfPositionIsPartOfBody(const Vector2&) const;
    bool HasEatenSegment() const;
};

