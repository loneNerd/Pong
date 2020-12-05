#pragma once
#ifndef AI_H_
#define AI_H_

#include "Paddle.h"
#include "Ball.h"

class AI
{
public:
	void MakeMove(Paddle& paddle, Ball& ball);
};

#endif //AI_H_