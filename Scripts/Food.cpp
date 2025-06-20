#include "Food.h"

Food::Food() {
    Image foodImage = LoadImage("../Graphics/Food_Texture.png");
    m_Texture2D = LoadTextureFromImage(foodImage);
    UnloadImage(foodImage);
    SetNewPosition();
}

void Food::Update() {

}

void Food::SetNewPosition() {
    m_Position = GameUtils::GenerateRandomPosition();
}

Vector2 Food::GetPosition() const {
    return m_Position;
}

void Food::Reset() {
    SetNewPosition();
}

void Food::Draw() {
    DrawTexture(m_Texture2D, GameUtils::CELL_SIZE * static_cast<int>(m_Position.x),
        GameUtils::CELL_SIZE * static_cast<int>(m_Position.y), WHITE);
}

Food::~Food() {
    UnloadTexture(m_Texture2D);
}