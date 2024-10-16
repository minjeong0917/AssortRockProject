#pragma once
#include <EngineCore/Actor.h>


class BlockStackImage : public AActor
{
public:
	Renderer* Render;

	void BeginPlay() override;

	void BlockSetPixel(FIntPoint _Pos);

	static BlockStackImage* GetBlockStackImg()
	{
		return BlockStackImg;
	}

	bool GetBlockPixelCheck(int _X, int _Y);
	void IsLineFullCheck();
	void DownBlock();

private:
	static BlockStackImage* BlockStackImg;

};

