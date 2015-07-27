#pragma once
#include "windows.h"
#include "Music.h"
#include <fstream>
#include<iostream>
using namespace std;

class CNumber
{
public:
	CNumber(void);
	virtual ~CNumber(void);

	CMusic music;

	int m_NewNumber;
	int m_Score;
	int m_HighScore;
	int m_Level;
	int m_HighLevel;
	int m_NumberBox4;
	int m_NumberBox8;
	int m_NumberBox16;
	int m_NumberBox32;
	int m_Number[4][4];

	void InitNumber(void);                //数值的初始化
	void Up(void);                        //向上运动
	void Down(void);                      //向下运动
	void Left(void);                      //向左运动
	void Right(void);                     //向右运动
	void Level(void);                     //等级计算
	int End(void);                        //结束判断
	void WriteInLevel(void);              //二进制写入最高等级
	void ReadOutLevel(void);              //读取最高等级
	void WriteInScore(void);              //二进制写入最高纪录
	void ReadOutScore(void);              //读取最高纪录
};

