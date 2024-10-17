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

// �ش� ���� '@'���� üũ�ϴ� �Լ�
bool BlockStackImage::GetBlockPixelCheck(int _X, int _Y)
{
	if (this->Render->RenderImage.GetPixel(_X, _Y) == '@' )
	{
		return true;
	}
	return false;
}

// ���� ��ġ�Ҷ����� ���� �� ä������ Ȯ���ϰ� ��ä��� ����� �Լ�
void BlockStackImage::IsLineFullCheck()
{
	int WindowYSize = Render->RenderImage.GetImageSize().Y;
	int WindowXSize = Render->RenderImage.GetImageSize().X;

	for (int y = 0; y < WindowYSize; y++)
	{
		int CheckCount = 0;
		std::vector<char> YChar = this->Render->RenderImage.GetLine(y);

		// �ش� y���� @�� ��ִ��� Ȯ�� 
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

		// 3���� ���� á�ٸ�
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

// ���� ���������� �����ִ� ���� ������ �Լ�
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
			// ��ü�� ���鼭 �ش� �ȼ��� @�̰�, �ٷ� �Ʒ��� @�� �ƴ϶�� ��ĭ �Ʒ��� ������
			if ((this->Render->RenderImage.GetPixel(x, y) == '@') && (this->Render->RenderImage.GetPixel(x, y+1) != '@'))
			{
				Render->RenderImage.SetPixel({ x, y }, '.');
				Render->RenderImage.SetPixel({ x, y + 1 }, '@');

			}
		}
	}
}

