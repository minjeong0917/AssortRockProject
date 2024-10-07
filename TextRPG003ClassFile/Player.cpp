#include "Player.h"
#include <iostream>


// 맴버함수 분할 구현
UPlayer::UPlayer()
{
	// std::cout << "플레이어 생성자" << std::endl;
}

void UPlayer::StatusTextPrint()
{
    printf_s("공격력 : %d ~ %d + %d\n", MinAtt, MaxAtt, EquipAtt);
    printf_s("체력 : %d\n", Hp);
}


void UPlayer::Equip(class Item* Weapon)
{

}
