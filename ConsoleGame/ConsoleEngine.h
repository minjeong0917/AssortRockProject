#pragma once
#include "ConsoleWindow.h"
#include "Player.h"

class ConsoleEngine
{
	// void Update(); // 움직인다.
	// void Move(); // 움직인다.

public:
	static void Start();
	static UConsoleWindow& GetWindow()
	{
		return Window;
	}

	static FIntPoint GetWindowSize()
	{
		return WindowSize;
	}


private:
	ConsoleEngine();

	static UConsoleWindow Window;
	static FIntPoint WindowSize;

	Player NewPlayer;

	// 2번 실행되지 않습니다.
	void BeginPlay(); // 움직인다.

	void Tick(); // 움직인다.
	void Render(); // 그린다.
};

