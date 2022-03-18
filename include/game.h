#ifndef GAME_H
#define GAME_H

#include "common.h"

class game
{
	static game* gameinst;
	bool state;

	SDL_Window* window;
	SDL_Renderer* renderer;
	
public:
	SDL_Renderer* getRenderer();
	
	static game* getInstance();
	bool isRunnning();
	void setState(bool state);

	int getRefreshRate();
	bool Init(const char* title);
	void HandleEvents();
	void Update(float dt);
	void Render();
	void clean();
};

#endif
