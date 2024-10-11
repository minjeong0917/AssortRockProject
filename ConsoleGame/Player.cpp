#include "Player.h"
#include <conio.h>
#include "Enums.h"
#include "ConsoleEngine.h"

void Player::BeginPlay()
{
	PlayerSizeX = 3;
	PlayerSizeY = 9;

	PlayerImage.Create({ PlayerSizeX, PlayerSizeY }, '@');
}

void Player::Tick()
{
	int Value = _kbhit();

	ConsoleEngine::GetWindow();
	int MaxX = ConsoleEngine::GetWindowSize().X;
	int MaxY = ConsoleEngine::GetWindowSize().Y;

	bool BreakMove = true;

	Enums::GAMEDIR Dir = Enums::GAMEDIR::NONE;

	if (Value != 0)
	{
		int Select = _getch();

		switch (Select)
		{
		case 'A':
		case 'a':
			if (Pos.X - 1 < 0)
			{
				BreakMove = false;
				break;
			}
			Dir = Enums::GAMEDIR::LEFT;
			break;
		case 'D':
		case 'd':
			if (Pos.X + PlayerSizeX + 1 > MaxX)
			{
				BreakMove = false;
				break;
			}
			Dir = Enums::GAMEDIR::RIGHT;
			break;
		case 'W':
		case 'w':
			if (Pos.Y - 1 < 0)
			{
				BreakMove = false;
				break;
			}
			Dir = Enums::GAMEDIR::UP;
			break;
		case 'S':
		case 's':
			if (Pos.Y + PlayerSizeY == MaxY)
 			{
				BreakMove = false;
				break;
			}
			Dir = Enums::GAMEDIR::DOWN;
			break;
		default:
			break;
		}

	}

	if (BreakMove) {
		switch (Dir)
		{
		case Enums::GAMEDIR::LEFT:
			Pos += FIntPoint::LEFT;
			break;
		case Enums::GAMEDIR::RIGHT:
			Pos += FIntPoint::RIGHT;
			break;
		case Enums::GAMEDIR::UP:
			Pos += FIntPoint::UP;
			break;
		case Enums::GAMEDIR::DOWN:
			Pos += FIntPoint::DOWN;
			break;
		default:
			break;
		}
	}
}


void Player::Render(ConsoleImage* _BackBuffer)
{
	_BackBuffer->Copy(Pos, PlayerImage);
}

void Player::SetActorLocation(FIntPoint _Pos)
{
	Pos = _Pos;
}