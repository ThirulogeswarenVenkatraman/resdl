#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "InputHandler.h"
#include "GameObjects.h"

class GameObjects;

class game
{
	bool state;
	static game* gameinst;
	SDL_Window* window;
	SDL_Renderer* renderer;
	std::vector<GameObjects*> gObjs;
public:
	static game* getInstance();
	int getRefreshRate();

	bool isRunnning() { return state; }
	void setState(bool state) { this->state = state; }
	SDL_Renderer* getRenderer() { return this->renderer; }

	void HandleEvents();

	bool Init(int width, int height, const char* title);
	
	void Update(float dt);
	void Render();
	void clean();
};

#endif
