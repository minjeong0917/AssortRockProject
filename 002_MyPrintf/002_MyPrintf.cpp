// 002_MyPrintf.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int NumberCount(int _Value)
{
	int Result = 0;
	while (_Value)
	{
		_Value /= 10;
		Result += 1;
	}
	return Result;
}

void NumberToString(char* Buffer, int BufferSize, int _Value)
{
	int Count = NumberCount(_Value);

	int MulValue = 1;
	for (int i = 0; i < Count - 1; i += 1)
	{
		MulValue *= 10;
	}

	for (int i = 0; i < Count; i += 1)
	{
		// 12321
		int CurValue = _Value / MulValue;
		Buffer[i] = CurValue + '0';
		_Value -= CurValue * MulValue;
		MulValue /= 10;
	}

	return;
}

const int IntMaxCount = 10;
const int ParameterInter = 8;

// 함수의 인자는 무조건 8바이트씩 떨어져 있다.
int MyPrintf(const char* const _Ptr, ...)
{
	__int64 FAdd = reinterpret_cast<__int64>(&_Ptr);

	int ChCount = 0;

	while (_Ptr[ChCount])
	{
		char Ch = _Ptr[ChCount];

		if (Ch == '%')
		{
			Ch = _Ptr[ChCount + 1];

			switch (Ch)
			{
			case 'd':
			{
				int* Ptr = reinterpret_cast<int*>(FAdd += ParameterInter);
				int ConvertValue = *Ptr;
				char Arr[IntMaxCount] = {};
				NumberToString(Arr, IntMaxCount, ConvertValue);

				MyPrintf(Arr);
				ChCount += 2;
				break;
			}
			default:
				break;
			}

		}

		putchar(_Ptr[ChCount]);
		ChCount += 1;
	}

	return ChCount;
}



int main()
{
	MyPrintf("Number : %d\n", 123251);
	MyPrintf("Number : %d\n", 151);
	MyPrintf("Number %d \n", 159159155);
	MyPrintf("%d Number\n", 12388251);

	int a = 0;
}