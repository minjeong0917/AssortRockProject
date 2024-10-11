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

    int ImageScaleY = 4;
    char** AllImagePixel = new char* [ImageScaleY] {0,};
    char* Arr[4];

    int ImageScaleX = 4;
    AllImagePixel[0] = new char[ImageScaleX + 1];
    AllImagePixel[1] = new char[ImageScaleX + 1];
    AllImagePixel[2] = new char[ImageScaleX + 1];
    AllImagePixel[3] = new char[ImageScaleX + 1];

    for (size_t i = 0; i < ImageScaleX; i++)
    {
        if (nullptr != AllImagePixel[i]) {
            delete[] AllImagePixel[i];
            AllImagePixel[i] = nullptr;
        }
    }

    if (nullptr != AllImagePixel)
    {
        delete[] AllImagePixel;
        AllImagePixel = nullptr;
    }

}
