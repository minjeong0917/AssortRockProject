#include "TetrisInit.h"
#include <EngineCore/ConsoleEngine.h>
#include <EngineCore/ConsoleWindow.h>

#include "Block.h"
#include "BlockStackImage.h"


void TetrisInit::UserBeginPlay(ConsoleEngine* _MainEngine)
{
	// ������ �մϴ�.
	_MainEngine->GetWindow()->SetScreenSize({5, 10});
	_MainEngine->SpawnActor<BlockStackImage>();
	_MainEngine->SpawnActor<Block>();

}