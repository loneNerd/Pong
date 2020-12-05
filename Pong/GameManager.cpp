#include "GameManager.h"

Ball* GameManager::ball = nullptr;
Paddle* GameManager::playerPaddle = nullptr;
Paddle* GameManager::aiPaddle = nullptr;
Score* GameManager::playerScore = nullptr;
Score* GameManager::aiScore = nullptr;

bool GameManager::isPlayerAttack = false;

void GameManager::Init(Ball* b, Paddle* player, Paddle* ai, Score* pField, Score* aiField)
{
	ball = b;
	playerPaddle = player;
	aiPaddle = ai;
	playerScore = pField;
	aiScore = aiField;
}

void GameManager::Clean()
{
	delete ball;
	delete playerPaddle;
	delete aiPaddle;
	delete playerScore;
	delete aiScore;
}