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
	static void Clean();

	static Ball& GetBall() { return *ball; }
	static Paddle& GetPlayerPaddle() { return *playerPaddle; }
	static Paddle& GetAIPaddle() { return *aiPaddle; }
	static Score& GetPlayerScore() { return *playerScore; }
	static Score& GetAIScore() { return *aiScore; }

	static bool isPlayerAttack;

private:
	static Ball* ball;
	static Paddle* playerPaddle;
	static Paddle* aiPaddle;
	static Score* playerScore;
	static Score* aiScore;
};

#endif //GAMEMANAGER_H_
