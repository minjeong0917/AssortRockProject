#include "BlockStackImage.h"
#include <EngineCore/Renderer.h>

BlockStackImage* BlockStackImage::BlockStackImg = nullptr;

void BlockStackImage::BeginPlay()
{
	Super::BeginPlay();
	BlockStackImg = this;

	Render = CreateDefaultSubObject();

	Render->RenderImage.Create({ 3, 5 }, '#');
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