#pragma once
#include "Zone.h"

class BlackSmith
{
public:
	// �ȳ־��ָ� ������ �ȵ�.
	//BlackSmith(UZone& _ParentZone)
	//	: ParentZone(_ParentZone)
	//{

	//}
	void Enforce(class UPlayer& _Player);

	void InPlayer(class UPlayer& _Player/*, int& Result*/);

	inline void SetParent(class UZone* _ParentZone)
	{
		ParentZone = _ParentZone;
	}


private:
	// class UZone& ParentZone;
	int EnforceStep = 0;

	int MaxEnforceStep = 15;
	class UZone* ParentZone = nullptr;
};

