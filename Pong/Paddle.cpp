#include "Paddle.h"
#include "Game.h"

void Paddle::MoveUp()
{
	if (frame.y > 0)
		--frame.y;
}

void Paddle::MoveDown()
{
	if (frame.y < WINDOW_HEIGHT - frame.h)
		++frame.y;
}