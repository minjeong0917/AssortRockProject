// 003_PlusString.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


const int IntMaxCount = 10;

void PlusString(char* _Buffer, int _BufferSize, const char* const _Value0, const char* const _Value1)
{

	int ChCount = 0;

	for (int i = 0; i < 2; i++)
	{
		_Buffer[ChCount] = _Value0[ChCount];
		putchar(_Value0[ChCount]);
		ChCount += 1;
	}


	return;

}

int main()
{
    char Arr[100] = {};

    PlusString(Arr, 100, "AAAA", "BBBB");

	int a = 1;

}

