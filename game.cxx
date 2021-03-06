#include "include/game.h"
#include "include/level.h"

Level* lvl = nullptr;
game* game::gameinst = nullptr;

game* game::getInstance()
{
	if (gameinst == 0)
	{
		gameinst = new game();
		return gameinst;
	}
	return gameinst;
}

int game::getRefreshRate()
{
	int displayIndex = SDL_GetWindowDisplayIndex(window);
	SDL_DisplayMode mode;
	SDL_GetDisplayMode(displayIndex, 0, &mode);
	return mode.refresh_rate;
}

void game::HandleEvents() { 
	InputHandler::getInstance()->EventUpdater(); 
	if(InputHandler::getInstance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		this->state = false;
	}
}

bool game::Init(int width, int height, const char* title)
{
	if (SDL_INIT_EVERYTHING)
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, width, height, 0);
		state = true;
	}
	else { std::cerr << SDL_GetError(); state = false;
	return false; }

	if (window)
	{
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		
		state = true;
	}
	else {std::cerr << SDL_GetError(); state = false;
	return false; }

	// Load Images
	lvl = new Level("assets/MapOne.tmx");
	
	return true;
}

void game::Update(float dt)
{

}

void game::Render()
{
	SDL_RenderClear(renderer);
	// Render Here
	lvl->drawLevel();
	SDL_RenderPresent(renderer);
}

void game::clean()
{
	lvl->freeLevel();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}