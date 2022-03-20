#ifndef COMMON_H
#define COMMON_H

typedef float madflow;
#define madflow_pow powf
#define MADFLOW_MAX FLT_MAX

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <float.h>
#include <vector>
#include <string>
#include <map>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Vector2d.h"

inline float InSec()
{
	float time = SDL_GetTicks();
	time /= 1000.0f;
	return time; //in seconds
}

#endif
