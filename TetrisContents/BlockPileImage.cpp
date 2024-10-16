#include "BlockPileImage.h"


void BlockPileImage::BeginPlay()
{
	Super::BeginPlay();
	Renderer* Render = CreateDefaultSubObject();

	Render->RenderImage.Create({ 3, 5 }, '*');

}