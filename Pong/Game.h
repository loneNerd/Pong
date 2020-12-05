#pragma once
#ifndef GAME_H_
#define GAME_H_

#include <SDL.h>
#include <iostream>
#include <list>

#include "Sprite.h"
#include "GameManager.h"

const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 600;

class Game {
public:
	SDL_Renderer* GetRenderer() { return renderer; }

	void AddSpriteToRender(Sprite* sprite) { Sprites.push_back(sprite); }
	void Init();
	void HandleEvents();
	void Update();
	void Render();
	void Clean();

	bool Running() const { return isRunning; }

private:
	bool isRunning;
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Event event;

	std::list<Sprite*> Sprites;
	std::list<Sprite*> Net;
};

#endif //GAME_H_