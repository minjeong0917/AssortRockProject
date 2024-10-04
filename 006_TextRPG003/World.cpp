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
		std::cout << "이름을 적어주세요" << std::endl;
		std::cin >> InputName;

		while (anoterKey) { // if문으로 해결하는게 더 좋을듯? 
			printf_s("당신의 이름은 %s입니다. 결정하시겠습니까?\n", InputName);
			printf_s("a. 결정\n");
			printf_s("b. 재입력\n");
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
				printf_s("잘못된 선택입니다. 다시 선택해주세요\n");

				break;
			}
		}

		if (true == IsEnd)
		{
			break;
		}
	}
}