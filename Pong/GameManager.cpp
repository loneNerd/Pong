#include "GameManager.h"

std::shared_ptr<Ball> GameManager::ball(nullptr);
std::shared_ptr<Paddle> GameManager::playerPaddle(nullptr);
std::shared_ptr<Paddle> GameManager::aiPaddle(nullptr);
std::shared_ptr<Score> GameManager::playerScore(nullptr);
std::shared_ptr<Score> GameManager::aiScore(nullptr);

bool GameManager::isPlayerAttack = false;

void GameManager::Init(Ball* b, Paddle* player, Paddle* ai, Score* pField, Score* aiField)
{
	ball = std::make_shared<Ball>(*b);
	playerPaddle = std::make_shared<Paddle>(*player);
	aiPaddle = std::make_shared<Paddle>(*ai);
	playerScore = std::make_shared<Score>(*pField);
	aiScore = std::make_shared<Score>(*aiField);
}