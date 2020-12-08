#pragma once
#ifndef BALL_H_
#define BALL_H_

#include <SDL.h>
#include <SDL_image.h>
#include <memory>

#include "Sprite.h"
#include "Paddle.h"

class Ball : public Sprite
{
public:
	Ball(SDL_Renderer *renderer, const char* texturePath, int xpos, int ypos, int width, int height)
		: Sprite(renderer, texturePath, xpos, ypos, width, height) { }

	void Move(const std::shared_ptr<Paddle>& player, const std::shared_ptr<Paddle>& ai);
	void StartPlayerAttack();
	void StartAIAttack();

	int GetSpeed() const { return speed; }

private:
	bool isMoveUp = true;
	bool isMoveLeft = true;
	int speed = 3;
	int ticks = speed;
};

#endif //BALL_H_