// 2048.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Game.h"
#include <time.h>
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"wmainCRTStartup\"" )//消除dos框

int _tmain(int argc, _TCHAR* argv[])
{
	srand((int)time(0));
	CGame *game = new CGame;
	game->GameRun();
	delete game;
	return 0;
}

