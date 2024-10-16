#include "TetrisConsoleImage.h"
#include <EngineCore/ConsoleEngine.h>
#include <EngineCore/ConsoleWindow.h>

void TetrisConsoleImage::BeginPlay(ConsoleEngine* _MainEngine)
{
	// 시작을 합니다.
	_MainEngine->GetWindow()->SetScreenSize({ 3, 5 });
	_MainEngine->SpawnActor<Block>();
}