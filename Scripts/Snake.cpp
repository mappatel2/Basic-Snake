#include "Snake.h"

Snake::Snake() {
    Init();
}

void Snake::Init() {
    for(int i = 1; i < 4; i++) {
        auto xPosition = static_cast<float>(i);
        m_Body.push_front(Vector2{xPosition, 9});
    }
    m_AddSegment = false;
    m_Direction = Vector2{1, 0};
    m_TempDirection = Vector2{1, 0};
}

void Snake::Update() {

    SetDirection();

    m_CurrentMoveTimer = GetTime();
    if(m_CurrentMoveTimer - m_LastMoveTimer < MOVE_TIMER_INTERVAL) {
        return;
    }
    m_LastMoveTimer = m_CurrentMoveTimer;

    m_Direction = m_TempDirection;
    m_Body.push_front(Vector2Add(m_Body.front(), m_Direction));
    if(m_AddSegment) {
        m_AddSegment = false;
    }
    else {
        m_Body.pop_back();
    }

    ClampMovement();
}

void Snake::Reset() {
    m_Body.clear();

    m_LastMoveTimer = 0.f;
    m_CurrentMoveTimer = 0.f;

    Init();
}

void Snake::ClampMovement() {
    for(auto& bodyPosition : m_Body) {
        if(bodyPosition.x < GameUtils::MIN_BOUND) {
            bodyPosition.x = GameUtils::MAX_BOUND;
        }
        else if(bodyPosition.x > GameUtils::MAX_BOUND) {
            bodyPosition.x = GameUtils::MIN_BOUND;
        }

        if(bodyPosition.y < GameUtils::MIN_BOUND) {
            bodyPosition.y = GameUtils::MAX_BOUND;
        }
        else if(bodyPosition.y > GameUtils::MAX_BOUND) {
            bodyPosition.y = GameUtils::MIN_BOUND;
        }
    }
}

void Snake::Draw() {
    for(const auto& position : m_Body) {
        DrawRectangleRounded(Rectangle{position.x * GameUtils::CELL_SIZE,
            position.y * GameUtils::CELL_SIZE, GameUtils::CELL_SIZE,
            GameUtils::CELL_SIZE}, 0.5f, 6, GameUtils::DARK_GREEN_COLOR);
    }
}

void Snake::SetDirection() {
    if(IsKeyPressed(KEY_UP) && m_Direction.y != 1) {
        m_TempDirection = {0 , -1};
    }

    if(IsKeyPressed(KEY_DOWN) && m_Direction.y != -1) {
        m_TempDirection = {0, 1};
    }

    if(IsKeyPressed(KEY_LEFT) && m_Direction.x != 1) {
        m_TempDirection = {-1 , 0};
    }

    if(IsKeyPressed(KEY_RIGHT) && m_Direction.x != -1) {
        m_TempDirection = {1, 0};
    }
}

bool Snake::CheckIfPositionIsPartOfBody(const Vector2& position) const {
    for(const auto& bodyPosition : m_Body) {
        if(Vector2Equals(bodyPosition, position)) {
            return true;
        }
    }
    return false;
}

void Snake::AddSegment() {
    m_AddSegment = true;
}

bool Snake::HasEatenSegment() const {
    Vector2 headPosition = GetHeadPosition();
    for(int i = 1; i < m_Body.size(); i++) {
        if(Vector2Equals(headPosition, m_Body[i])) {
            return true;
        }
    }
    return false;
}

Vector2 Snake::GetHeadPosition() const {
    return m_Body.front();
}

Vector2 Snake::GetTailPosition() const {
    return m_Body.back();
}

Snake::~Snake() {
    std::cout << "Snake Destructor Called\n";
}