#pragma once
#include <BaseSystem/EngineMath.h>
#include <vector>


class ConsoleImage
{

public:
	~ConsoleImage();

	void Release();

	// 뭐로 채울거냐?
	// 이미지의 크기를 바꾼다.
	// void Resize(int _X, int _Y, char _BaseChar);

	// 이미지를 지운다.
	void Clear(char _Clearchar);

	void Create(FIntPoint _Size, char _BaseChar)
	{
		Create(_Size.X, _Size.Y, _BaseChar);
	}

	// 이미지를 만든다.
	void Create(int _X, int _Y, char _BaseChar);

	// 값으로 리턴할거냐 참조로 리턴할거냐가 갈립니다.
	// 이건 복사가 일어납니다. 
	inline std::vector<char> GetLine(size_t _Y)
	{
		return Pixels[_Y];
	}

	// 수정은 하지마
	inline std::vector<char>& GetLineRef(size_t _Y)
	{
		return Pixels[_Y];
	}

	inline char GetPixel(int _X, int _Y)
	{
		return Pixels[_Y][_X];
	}


	inline FIntPoint GetImageSize() const
	{
		return ImageSize;
	}

	void Copy(FIntPoint _Offset, ConsoleImage& _Image);

	void SetPixel(FIntPoint _Pos, char _Char);


private:
	// 상수 안됩니다.
	// char** Arr = nullptr;
	std::vector<std::vector<char>> Pixels;
	FIntPoint ImageSize;
};

