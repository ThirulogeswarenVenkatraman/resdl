#ifndef GAME_H
#define GAME_H

#include "common.h"
#include "InputHandler.h"
#include "GameObjects.h"

class game
{
	bool state;
	static game* gameinst;
	SDL_Window* window;
	SDL_Renderer* renderer;

public:
	
	static game* getInstance();
	int getRefreshRate();

	bool isRunnning() { return state; }
	void setState(bool state) { this->state = state; }
	SDL_Renderer* getRenderer() { return this->renderer; }

	void HandleEvents();

	bool Init(const char* title);
	
	void Update(float dt);
	void Render();
	void clean();
};

#endif
