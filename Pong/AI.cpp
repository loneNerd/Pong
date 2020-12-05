#include "AI.h"

void AI::MakeMove(Paddle& paddle, Ball& ball)
{
	if (ball.GetY() + ball.GetHeight() / 2 < paddle.GetY() + paddle.GetHeight() / 2)
		paddle.MoveUp();
	else
		paddle.MoveDown();
}