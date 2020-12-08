#include "Ball.h"
#include "Game.h"

const double PI = 3.14159265;

void Ball::Move(const std::shared_ptr<Paddle>& player, const std::shared_ptr<Paddle>& ai)
{
	if (frame.y <= 0 || frame.y + frame.w >= WINDOW_HEIGHT)
		isMoveUp = !isMoveUp;

	if ((frame.y + frame.h == player->GetY() && frame.x > player->GetX() && frame.x < player->GetX() + player->GetWidth()) ||
		(frame.y + frame.h == ai->GetY() && frame.x + frame.w > ai->GetX() && frame.x + frame.w < ai->GetX() + ai->GetWidth()))
		isMoveUp = true;
	else if ((frame.y == player->GetY() + player->GetHeight() && frame.x > player->GetX() && frame.x < player->GetX() + player->GetWidth()) ||
		(frame.y == ai->GetY() + ai->GetHeight() && frame.x + frame.w > ai->GetX() && frame.x + frame.w < ai->GetX() + ai->GetWidth()))
		isMoveUp = false;

	if ((frame.x == player->GetX() + player->GetWidth() && frame.y + frame.h > player->GetY() && frame.y < player->GetY() + player->GetHeight()) ||
		(frame.x + frame.w == ai->GetX() && frame.y + frame.h > ai->GetY() && frame.y < ai->GetY() + ai->GetHeight()))
		isMoveLeft = !isMoveLeft;

	if (isMoveUp)
		--frame.y;
	else
		++frame.y;

	if (isMoveLeft)
		--frame.x;
	else
		++frame.x;
}

void Ball::StartPlayerAttack()
{
	isMoveUp = true;
	isMoveLeft = false;
	frame.x = WINDOW_WIDTH / 2 - 150;
	frame.y = rand() % (WINDOW_HEIGHT / 2) + 150;
}

void Ball::StartAIAttack()
{
	isMoveUp = true;
	isMoveLeft = true;
	frame.x = WINDOW_WIDTH / 2 + 150;
	frame.y = rand() % (WINDOW_HEIGHT / 2) + 150;
}