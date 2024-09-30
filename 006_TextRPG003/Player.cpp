#include "Player.h"
#include <iostream>

// #CPP에서는 #include를 아무리 많이해도 순환참조는 걱정 안해도 된다.
// 그런데 문제가 있다. 빌드가 오래 걸린다.
// obj파일마다 #include가 


// 맴버함수 분할 구현
UPlayer::UPlayer()
{
	std::cout << "플레이어 생성자" << std::endl;
}

