#include "Player.h"
#include <iostream>


// �ɹ��Լ� ���� ����
UPlayer::UPlayer()
{
	// std::cout << "�÷��̾� ������" << std::endl;
}

void UPlayer::StatusTextPrint()
{
    printf_s("���ݷ� : %d ~ %d + %d\n", MinAtt, MaxAtt, EquipAtt);
    printf_s("ü�� : %d\n", Hp);
}


void UPlayer::Equip(class Item* Weapon)
{

}
