#include "BlackSmith.h"
#include "Player.h"
#include <BaseSystem/EngineDebug.h>
#include <conio.h>

int BlackSmith::Enforce(class UPlayer& _Player)
{

	srand(time(nullptr));
	int RandNum = rand() % 2;

	int CurGold = _Player.GetGold();

	CurGold -= (EnforceStep+1) * 100;
	_Player.SetGold(CurGold);

	system("cls");

	_Player.StatusRender();

	if (EnforceStep >= 0 && EnforceStep <= 5)
	{
		if (RandNum == 0)
		{
			EnforceStep += 1;

		}

	}
	else if (EnforceStep >= 6 && EnforceStep <= 10)
	{
		if (RandNum == 0)
		{
			EnforceStep += 1;
		}
		else
		{
			EnforceStep -= 1;
		}
	}
	else if (EnforceStep >= 11 && EnforceStep <= 14)
	{
		if (RandNum == 0)
		{
			EnforceStep += 1;
		}
		else
		{
			EnforceStep = 0;

		}
	}

	return EnforceStep;
}

void BlackSmith::InPlayer(class UPlayer& _Player/*, int& Result*/)
{
	if (nullptr == ParentZone)
	{
		MSGASSERT("부모존이 세팅되지 않았습니다");
		return;
	}

	_Player.SetGold(1000000);


	while (true)
	{
		system("cls");
		_Player.StatusRender();
		printf_s("%d강 입니다. \n", EnforceStep);
		std::cout << "1. 강화\n";
		std::cout << "2. 나간다\n";
		int Select = _getch();

		if (EnforceStep == 15)
		{
			printf_s("최고 강화 단계입니다.");
		}

		switch (Select)
		{
			case '1':
				if (_Player.GetGold() <= 0)
				{
					printf_s("돈이 없어 강화가 불가능합니다.");
					_getch();
					break;
				}
				else
				{
					Enforce(_Player);
					break;
				}


			case '2':
				return;

			default:
				break;
		}
	}
}