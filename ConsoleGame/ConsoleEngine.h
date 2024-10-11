#pragma once
#include "ConsoleWindow.h"
#include "Player.h"

class ConsoleEngine
{
	// void Update(); // �����δ�.
	// void Move(); // �����δ�.

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

	// 2�� ������� �ʽ��ϴ�.
	void BeginPlay(); // �����δ�.

	void Tick(); // �����δ�.
	void Render(); // �׸���.
};

