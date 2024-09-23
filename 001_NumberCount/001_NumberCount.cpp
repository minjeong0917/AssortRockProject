// 001_NumberCount.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

//음수 및 0 이외 양수의 자리수 카운트, 나누기 연산 사용
int NumberCount(int _Value)
{
    int Result = 0;

    while (true)
    {
        if (_Value <= 0 )
        {
            break;
        }

        _Value /= 10;

        Result += 1;
    }

    return Result;
}


int main()
{
    int Result0 = NumberCount(12358);
    int Result1 = NumberCount(5258);
    int Result2 = NumberCount(5258111);
    int Result3 = NumberCount(2147483647);
    int Result4 = NumberCount(0);
    int Result5 = NumberCount(-2);
    int Result6 = NumberCount(556);
    int Result7 = NumberCount(552226);

    int a = 0;
}
