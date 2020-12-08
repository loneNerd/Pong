#include "AI.h"

void AI::MakeMove(const std::shared_ptr<Paddle>& paddle, const std::shared_ptr<Ball>& ball)
{
	if (ball->GetY() + ball->GetHeight() / 2 < paddle->GetY() + paddle->GetHeight() / 2)
		paddle->MoveUp();
	else
		paddle->MoveDown();
}