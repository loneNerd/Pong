#pragma once
#ifndef SCORE_H_
#define SCORE_N_

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>

#include "Sprite.h"

class Score : public Sprite
{
public:
	Score(SDL_Renderer *renderer, int xpos, int ypos, int width, int height);
	void IncreaseScore(SDL_Renderer *renderer);

	int GetScore() const { return score; }

private:
	int score = 0;
};

#endif //SCORE_H_
