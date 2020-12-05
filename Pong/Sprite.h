#pragma once
#ifndef SPRITE_H_
#define SPRITE_H_

#include <SDL.h>
#include <SDL_image.h>

class Sprite
{
public:
	Sprite(SDL_Renderer *renderer, const char* texturePath, int xpos, int ypos, int width, int height) 
	{
		SDL_Surface* surface = IMG_Load(texturePath);
		texture = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_FreeSurface(surface);

		frame.w = width;
		frame.h = height;
		frame.x = xpos;
		frame.y = ypos;
	}
	
	virtual int GetHeight() const { return frame.h; }
	virtual int GetWidth() const { return frame.w; }
	virtual int GetX() const { return frame.x; }
	virtual int GetY() const { return frame.y; }

	virtual SDL_Texture& GetTexture() const { return *texture; }
	virtual SDL_Rect& GetFrame() { return frame; }

protected:
	SDL_Texture *texture;
	SDL_Rect frame;
};

#endif //SPRITE_H_