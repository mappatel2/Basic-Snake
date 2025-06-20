#pragma once
#include "Entity.h"
#include <iostream>

class Food : public Entity {
private:
    Texture2D m_Texture2D;
    Vector2 m_Position;

public:
    Food();
    ~Food() override;

    void Update() override;
    void Draw() override;
    void Reset() override;

    void SetNewPosition();
    Vector2 GetPosition() const;
};