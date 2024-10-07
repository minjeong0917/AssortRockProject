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
		MSGASSERT("�θ����� ���õ��� �ʾҽ��ϴ�");
		return;
	}

	_Player.SetGold(1000000);


	while (true)
	{
		system("cls");
		_Player.StatusRender();
		printf_s("%d�� �Դϴ�. \n", EnforceStep);
		std::cout << "1. ��ȭ\n";
		std::cout << "2. ������\n";
		int Select = _getch();

		if (EnforceStep == 15)
		{
			printf_s("�ְ� ��ȭ �ܰ��Դϴ�.");
		}

		switch (Select)
		{
			case '1':
				if (_Player.GetGold() <= 0)
				{
					printf_s("���� ���� ��ȭ�� �Ұ����մϴ�.");
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