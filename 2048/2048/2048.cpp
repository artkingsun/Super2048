// 2048.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Game.h"
#include <time.h>
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"wmainCRTStartup\"" )//����dos��

int _tmain(int argc, _TCHAR* argv[])
{
	srand((int)time(0));
	CGame *game = new CGame;
	game->GameRun();
	delete game;
	return 0;
}

