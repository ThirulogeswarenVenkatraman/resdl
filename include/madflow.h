#ifndef MADFLOW_H
#define MADFLOW_H

#include <SDL2/SDL.h>

typedef float madflow;
#define madflow_pow powf
#define MADFLOW_MAX FLT_MAX

#define SCREEN_X 1024
#define SCREEN_Y 576

#define tSCALE 1

inline float InSec()
{
	float time = SDL_GetTicks();
	time /= 1000.0f;
	return time; //in seconds
}

#endif
