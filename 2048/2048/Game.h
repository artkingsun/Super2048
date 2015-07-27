#pragma once
#include "opencv2/opencv.hpp"
#include "Number.h"
#include "Source.h"
#include "Music.h"
#include "windows.h"
#include "mmsystem.h"//导入声音头文件
#pragma comment(lib, "winmm.lib")//导入声音头文件库
#include <iostream>
using namespace std;

class CGame
{
public:
	CGame(void);
	virtual ~CGame(void);

	CNumber number;
	CMusic music;
	CSource source;

	bool GameRun(void);                 //游戏运行

private:
	void GetKey(int key);               //接受键盘输入
	void Menu(void);                    //菜单显示
	void Prop(void);                    //道具显示
	void ChangeBox(void);               //方块更改
	void DrawBoxs(void);                //绘制方块到背景
	void PropMove(void);                //道具移动
	void Instruction(void);             //游戏说明
	void InitGame(void);                //初始化游戏
	void ChooseVersion(int l_Choose);   //选择游戏模式
};

