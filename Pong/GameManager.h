#pragma once
#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

#include "Ball.h"
#include "Paddle.h"
#include "Score.h"

class GameManager
{
public:
	static void Init(Ball* b, Paddle* player, Paddle* ai, Score* pField, Score* aiField);

	static const std::shared_ptr<Ball>& GetBall() { return ball; }
	static const std::shared_ptr<Paddle>& GetPlayerPaddle() { return playerPaddle; }
	static const std::shared_ptr<Paddle>& GetAIPaddle() { return aiPaddle; }
	static const std::shared_ptr<Score>& GetPlayerScore() { return playerScore; }
	static const std::shared_ptr<Score>& GetAIScore() { return aiScore; }

	static bool isPlayerAttack;

private:
	static std::shared_ptr<Ball> ball;
	static std::shared_ptr<Paddle> playerPaddle;
	static std::shared_ptr<Paddle> aiPaddle;
	static std::shared_ptr<Score> playerScore;
	static std::shared_ptr<Score> aiScore;
};

#endif //GAMEMANAGER_H_
