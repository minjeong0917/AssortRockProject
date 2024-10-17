#include "BlockStackImage.h"
#include <EngineCore/Renderer.h>
#include <vector>

BlockStackImage* BlockStackImage::BlockStackImg = nullptr;

void BlockStackImage::BeginPlay()
{
	Super::BeginPlay();
	BlockStackImg = this;

	Render = CreateDefaultSubObject();

	Render->RenderImage.Create({ 5, 10 }, '.');
}

void BlockStackImage::BlockSetPixel(FIntPoint _Pos)
{
	Render->RenderImage.SetPixel({ _Pos }, '@');
}

// 해당 블럭이 '@'인지 체크하는 함수
bool BlockStackImage::GetBlockPixelCheck(int _X, int _Y)
{
	if (this->Render->RenderImage.GetPixel(_X, _Y) == '@' )
	{
		return true;
	}
	return false;
}

// 블럭을 설치할때마다 라인 다 채웠는지 확인하고 다채우면 지우는 함수
void BlockStackImage::IsLineFullCheck()
{
	int WindowYSize = Render->RenderImage.GetImageSize().Y;
	int WindowXSize = Render->RenderImage.GetImageSize().X;

	for (int y = 0; y < WindowYSize; y++)
	{
		int CheckCount = 0;
		std::vector<char> YChar = this->Render->RenderImage.GetLine(y);

		// 해당 y열에 @가 몇개있는지 확인 
		for (int x = 0; x < WindowXSize; x++)
		{
			if (YChar[x] != '@')
			{
				continue;
			}
			else
			{
				++CheckCount;
			}
		}

		// 3줄이 전부 찼다면
		if (CheckCount == WindowXSize)
		{
			for (int x = 0; x < WindowXSize; x++)
			{
				Render->RenderImage.SetPixel({ x, y }, '.');
				BlockStackImage::DownBlock();
			}
		}
	}
}

// 블럭이 지워졌을때 위에있던 블럭들 내리는 함수
void BlockStackImage::DownBlock()
{
	int WindowYSize = Render->RenderImage.GetImageSize().Y - 2;
	int WindowXSize = Render->RenderImage.GetImageSize().X;

	for(int y = WindowYSize; y > 0; y--)
	{
		std::vector<char> YChar = this->Render->RenderImage.GetLine(y);
		std::vector<char> NextYChar = this->Render->RenderImage.GetLine(static_cast<size_t>(y) + 1);

		for (int x = 0; x < WindowXSize; x++)
		{
			// 전체를 돌면서 해당 픽셀이 @이고, 바로 아래가 @이 아니라면 한칸 아래로 내려감
			if ((this->Render->RenderImage.GetPixel(x, y) == '@') && (this->Render->RenderImage.GetPixel(x, y+1) != '@'))
			{
				Render->RenderImage.SetPixel({ x, y }, '.');
				Render->RenderImage.SetPixel({ x, y + 1 }, '@');

			}
		}
	}
}

