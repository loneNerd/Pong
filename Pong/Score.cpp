#include "Score.h"

Score::Score(SDL_Renderer *renderer, int xpos, int ypos, int width, int height)
	: Sprite(renderer, "", xpos, ypos, width, height)
{
	TTF_Init();
	TTF_Font* arial = TTF_OpenFont("assets/arial.ttf", 24);
	SDL_Color White = { 255, 255, 255 };

	SDL_Surface* surfaceMessage = TTF_RenderText_Blended(arial, "0", White);

	texture = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

	SDL_FreeSurface(surfaceMessage);
	TTF_CloseFont(arial);
}

void Score::IncreaseScore(SDL_Renderer *renderer)
{
	++score;

	TTF_Init();
	TTF_Font* arial = TTF_OpenFont("assets/arial.ttf", 24);
	SDL_Color White = { 255, 255, 255 };

	char str[3];
	sprintf_s(str, "%d", score);

	SDL_Surface* surfaceMessage = TTF_RenderText_Blended(arial, str, White);

	texture = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

	SDL_FreeSurface(surfaceMessage);
	TTF_CloseFont(arial);
}