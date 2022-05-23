#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SDL2/SDL_image.h>

#include <iostream>
#include <map>
#include <string>

#include "madflow.h"

class TextureManager
{
	static TextureManager* textinst;
	std::map<std::string, SDL_Texture*> qtextures;
	std::map<std::string, SDL_Texture*> qtilesets; // contains tilesets
	SDL_Texture* Texture;
	SDL_Texture* TileSet;
public:
	static TextureManager* getInstance();
	bool Load(std::string fileName, std::string id, SDL_Renderer* renderer);
	bool LoadTileSet(std::string fileName, std::string tilesetid, SDL_Renderer* renderer);

	void clean(std::string textureName);
	void freeTileSet(std::string tilesetname);

	void Draw(std::string id, int x, int y, int width, int height,
	SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_RendererFlip::SDL_FLIP_NONE);
	void DrawFrame(std::string id, int x, int y, int width, int height, int currentRow,
	int currentFrame, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_RendererFlip::SDL_FLIP_NONE);

	void DrawTile(std::string tid, int x, int y, int width, int height, 
	int x_offset, int y_offset, SDL_Renderer* renderer);

};

#endif
