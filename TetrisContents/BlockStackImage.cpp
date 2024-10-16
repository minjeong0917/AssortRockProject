#include "BlockStackImage.h"
#include <EngineCore/Renderer.h>
#include <vector>

BlockStackImage* BlockStackImage::BlockStackImg = nullptr;

void BlockStackImage::BeginPlay()
{
	Super::BeginPlay();
	BlockStackImg = this;

	Render = CreateDefaultSubObject();

	Render->RenderImage.Create({ 3, 5 }, '.');
}

void BlockStackImage::BlockSetPixel(FIntPoint _Pos)
{
	Render->RenderImage.SetPixel({ _Pos }, '@');
}

bool BlockStackImage::GetBlockPixelCheck(int _X, int _Y)
{
	if (this->Render->RenderImage.GetPixel(_X, _Y) == '@' )
	{
		return true;
	}
	return false;
}

void BlockStackImage::IsLineFullCheck()
{
	int WindowYSize = Render->RenderImage.GetImageSize().Y;
	int WindowXSize = Render->RenderImage.GetImageSize().X;

	for (int y = 0; y < WindowYSize; y++)
	{
		int CheckCount = 0;
		std::vector<char> YChar = this->Render->RenderImage.GetLine(y);
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
			if ((this->Render->RenderImage.GetPixel(x, y) == '@') && (this->Render->RenderImage.GetPixel(x, y+1) != '@'))
			{
				Render->RenderImage.SetPixel({ x, y }, '.');
				Render->RenderImage.SetPixel({ x, y + 1 }, '@');

			}

		}

			

	}
}

