#ifndef MADFLOW_H
#define MADFLOW_H

#include <SDL2/SDL.h>

typedef float madflow;
#define madflow_pow powf
#define MADFLOW_MAX FLT_MAX

#define SCREEN_X 1280
#define SCREEN_Y 720

#define tSCALE 2.5

inline float InSec()
{
	float time = SDL_GetTicks();
	time /= 1000.0f;
	return time; //in seconds
}

#endif
