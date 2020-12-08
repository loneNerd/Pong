#include "Game.h"

void Game::Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL subsystem initialized" << std::endl;

		window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

		if (window)
			std::cout << "Window created" << std::endl;

		renderer = SDL_CreateRenderer(window, -1, 0);

		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
			std::cout << "Renderer created" << std::endl;
		}

		for (int i = 0; i < WINDOW_HEIGHT; i += 50)
		{
			Sprite* cell = new Sprite(renderer, "assets/Paddle.png", WINDOW_WIDTH / 2 - 5, i, 10, 40);
			Net.push_back(std::make_shared<Sprite>(*cell));
		}

		isRunning = true;
	}
	else
	{
		std::cerr << "SDL subsystem initialization failed" << std::endl;
		isRunning = false;
	}
}

void Game::HandleEvents()
{
	SDL_PollEvent(&event);

	if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
		isRunning = false;
	else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_UP)
		GameManager::GetPlayerPaddle()->MoveUp();
	else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_DOWN)
		GameManager::GetPlayerPaddle()->MoveDown();
}

void Game::Render()
{
	SDL_RenderClear(renderer);

	for (auto& elem : Net)
		SDL_RenderCopy(renderer, &elem->GetTexture(), NULL, &elem->GetFrame());

	for (auto& elem : Sprites)
		SDL_RenderCopy(renderer, &elem->GetTexture(), NULL, &elem->GetFrame());

	SDL_RenderPresent(renderer);
}

void Game::Clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	std::cout << "Game closed" << std::endl;
}

void Game::Update()
{
	if (GameManager::GetBall()->GetX() <= 0 || GameManager::GetBall()->GetX() + GameManager::GetBall()->GetWidth() >= WINDOW_WIDTH)
	{
		if (GameManager::GetBall()->GetX() <= 0)
			GameManager::GetAIScore()->IncreaseScore(renderer);
		else if (GameManager::GetBall()->GetX() + GameManager::GetBall()->GetWidth() >= WINDOW_WIDTH)
			GameManager::GetPlayerScore()->IncreaseScore(renderer);

		if (GameManager::GetAIScore()->GetScore() == 11 || GameManager::GetPlayerScore()->GetScore() == 11)
			isRunning = false;

		if ((GameManager::GetAIScore()->GetScore() + GameManager::GetPlayerScore()->GetScore()) % 5 == 0)
			GameManager::isPlayerAttack = !GameManager::isPlayerAttack;

		if (GameManager::isPlayerAttack)
			GameManager::GetBall()->StartPlayerAttack();
		else
			GameManager::GetBall()->StartAIAttack();
	}

	GameManager::GetBall()->Move(GameManager::GetPlayerPaddle(), GameManager::GetAIPaddle());
}