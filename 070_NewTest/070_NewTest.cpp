// 070_NewTest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    "&&**";
    "&&**";
    "****";
    "****";

    // 이중 포인터를 통해 2차원 표현..?
    int ImageScaleY = 4;
    char** AllImagePixel = new char* [ImageScaleY] {0,};
    char* Arr[4];

    int ImageScaleX = 4;
    AllImagePixel[0] = new char[ImageScaleX + 1];
    AllImagePixel[1] = new char[ImageScaleX + 1];
    AllImagePixel[2] = new char[ImageScaleX + 1];
    AllImagePixel[3] = new char[ImageScaleX + 1];
    
    // AllImagePixel가 가리키고있는 배열에서 각 해당 번호가 가리키고 있는 배열을 delete 하는 for문
    for (size_t i = 0; i < ImageScaleY; i++)
    {
        if (nullptr != AllImagePixel[i]) {
            delete[] AllImagePixel[i];
            AllImagePixel[i] = nullptr;
        }
    }

    // AllImagePixel가 가리키고있는 배열을 delete 하는 if문 <= 얘가 먼저 지워지면 위에서 가리키고 있는 애들을 찾을 수 없기 때문에 얘가 나중에 지워져야 함!
    if (nullptr != AllImagePixel)
    {
        delete[] AllImagePixel;
        AllImagePixel = nullptr;
    }

}
