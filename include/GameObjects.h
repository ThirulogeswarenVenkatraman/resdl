#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "game.h"
#include "TextureManager.h"

class GameObjects { 
public:
    virtual bool Load() = 0;
    virtual void Update(float dt) = 0;
    virtual void Render() = 0;
    virtual void clean() = 0;
};

#endif
