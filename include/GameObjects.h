#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "game.h"
#include "TextureManager.h"
#include "Vector2d.h"

class GameObjects { 
public:
    virtual void Load() = 0;
    virtual void Update(float dt) = 0;
    virtual void Render() = 0;
    virtual void clean() = 0;
    virtual madflow retX() = 0;
    virtual madflow retY() = 0;
};

#endif
