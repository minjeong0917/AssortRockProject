#pragma once
#include "ConsoleImage.h"

//class AActor
//{
//	FIntPoint Location;
//};
//
//class Monster
//{
//	
//};

// ȭ���򰡿� �̳༮�� ������
// �Ϲ����� ���ӿ���
class Player
{
public:
	void BeginPlay();
	void Tick();
	void Render(ConsoleImage* _BackBuffer);

	void SetActorLocation(FIntPoint _Pos);

private:
	int PlayerSizeX = 0;
	int PlayerSizeY = 0;

	FIntPoint Pos;
	ConsoleImage PlayerImage;
};

