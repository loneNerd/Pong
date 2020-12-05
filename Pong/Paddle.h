#pragma once
#ifndef PADDLE_H_
#define PADDLE_H_

#include <SDL.h>
#include <SDL_image.h>

#include "Sprite.h"

class Paddle : public Sprite
{
public:
	Paddle(SDL_Renderer *renderer, const char* texturePath, int xpos, int ypos, int width, int height)
		: Sprite(renderer, texturePath, xpos, ypos, width, height) { }

	void MoveUp();
	void MoveDown();
};

#endif //PADDLE_H_