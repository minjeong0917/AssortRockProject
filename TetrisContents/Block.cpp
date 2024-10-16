#include "Block.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/ConsoleWindow.h>
#include <conio.h>
#include "BlockStackImage.h"




void Block::BeginPlay()
{
	Super::BeginPlay();

	Renderer* Render = CreateDefaultSubObject();
	Render->RenderImage.Create({ 1, 1 }, '@');

	
}

void Block::Tick()
{

	Super::Tick();
	Block::Stack();


	int Value = _kbhit();
	if (Value != 0)
	{
		int Select = _getch();

		switch (Select)
		{
		case 'A':
		case 'a':
			AddActorLocation(FIntPoint::LEFT);
			break;
		case 'D':
		case 'd':
			AddActorLocation(FIntPoint::RIGHT);
			break;
		case 'W':
		case 'w':
			AddActorLocation(FIntPoint::UP);
			break;
		case 'S':
		case 's':
			AddActorLocation(FIntPoint::DOWN);
			break;
		case 'T':
		case 't':
			//NewBlockStcakImg->BlockStack();
			// AddActorLocation(FIntPoint::DOWN);
			break;
		default:
			break;
		}
	}
}

void Block::Stack()
{
	BlockStackImage* NewBlockStcakImg = BlockStackImage::GetBlockStackImg();
	ConsoleImage Size = NewBlockStcakImg->Render->RenderImage;
	int MaxY = Size.GetImageSize().Y - 1;

	bool IsBlock = false;

	if (GetActorLocation().Y < MaxY)
	{
		IsBlock = NewBlockStcakImg->GetBlockPixelCheck(GetActorLocation().X, GetActorLocation().Y + 1 );
	}

	if ( IsBlock || GetActorLocation().Y == MaxY)
	{
		NewBlockStcakImg->BlockSetPixel(GetActorLocation());
		SetActorLocation({ 0, 0 });

		bool ff = false;
		NewBlockStcakImg->IsLineFullCheck();

	}

}

void Block::LineFullStack()
{
	BlockStackImage* NewBlockStcakImg = BlockStackImage::GetBlockStackImg();


}


