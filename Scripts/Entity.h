#pragma once
#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include "GameUtils.h"

class Entity {
public:
    virtual void Update() = 0;
    virtual void Draw() = 0;
    virtual void Reset() = 0;

    virtual ~Entity() = default;
};
