#include <cstdlib>
#include <ctime>

#include "Game.h"
#include "Ball.h"
#include "Paddle.h"
#include "AI.h"

Game *game = nullptr;
AI* ai = nullptr;

int main(int argc, char* argv[])
{
	srand(time(0));

	const int Delay = 2;

	Uint32 Start;
	int Time;

	game = new Game();

	game->Init();

	GameManager::Init(new Ball(game->GetRenderer(), "assets/Ball.png", WINDOW_WIDTH / 2 + 150, WINDOW_HEIGHT / 2 - 12, 24, 24),
		new Paddle(game->GetRenderer(), "assets/Paddle.png", 25, WINDOW_HEIGHT / 2 - 50, 25, 100),
		new Paddle(game->GetRenderer(), "assets/Paddle.png", WINDOW_WIDTH - 50, WINDOW_HEIGHT / 2 - 50, 25, 100),
		new Score(game->GetRenderer(), WINDOW_WIDTH / 2 - 75, 0, 50, 50),
		new Score(game->GetRenderer(), WINDOW_WIDTH / 2 + 25, 0, 50, 50));

	ai = new AI();
	
	game->AddSpriteToRender(&GameManager::GetBall());
	game->AddSpriteToRender(&GameManager::GetPlayerPaddle());
	game->AddSpriteToRender(&GameManager::GetAIPaddle());
	game->AddSpriteToRender(&GameManager::GetPlayerScore());
	game->AddSpriteToRender(&GameManager::GetAIScore());

	while (game->Running())
	{
		Start = SDL_GetTicks();

		game->HandleEvents();
		ai->MakeMove(GameManager::GetAIPaddle(), GameManager::GetBall());
		game->Update();
		game->Render();

		Time = SDL_GetTicks() - Start;

		if (Delay > Time)
			SDL_Delay(Delay - Time);
	}

	game->Clean();

	delete ai;
	delete game;

	GameManager::Clean();

	return 0;
}