#include "World.h"
#include <iostream>
#include <conio.h>


void UWorld::InPlayer(class UPlayer& _Player)
{
	char InputName[100] = { 0, };

	while (true)
	{
		system("cls");

		bool IsEnd = false;
		bool anoterKey = true;
		std::cout << "�̸��� �����ּ���" << std::endl;
		std::cin >> InputName;

		while (anoterKey) { // if������ �ذ��ϴ°� �� ������? 
			printf_s("����� �̸��� %s�Դϴ�. �����Ͻðڽ��ϱ�?\n", InputName);
			printf_s("a. ����\n");
			printf_s("b. ���Է�\n");
			int Select = _getch();

			switch (Select)
			{
			case 'a':
			case 'A':
				IsEnd = true;
				anoterKey = false;
				break;

			case 'b':
			case 'B':
				IsEnd = false;
				anoterKey = false;
				break;

			default:
				system("cls");
				printf_s("�߸��� �����Դϴ�. �ٽ� �������ּ���\n");

				break;
			}
		}

		if (true == IsEnd)
		{
			break;
		}
	}
}