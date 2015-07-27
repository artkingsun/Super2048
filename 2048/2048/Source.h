#pragma once
#include "opencv2/opencv.hpp"
#include "Number.h"

class CSource
{
public:
	CSource(void);
	virtual ~CSource(void);

	CNumber number;

	IplImage* m_4;
	IplImage* m_8;
	IplImage* m_16;
	IplImage* m_32;
	IplImage* m_ShowImg;
	IplImage* m_Back;
	IplImage* m_Box;
	IplImage* m_Start;
	IplImage* m_Version;
	IplImage* m_CasperLevel;
	IplImage* m_Instruction;
	IplImage* m_DynastyLevel;
	IplImage* m_MilitaryRankLevel;

	void InitSourceNumber(void);                               //初始化数字版方块
	void InitSourceDynasty(void);                              //初始化朝代版方块
	void InitSourceMilitaryRank(void);                         //初始化军衔版方块
	void InitSourceCasper(void);                               //初始化学霸版方块
	void InitDynastyLevel(int a);                              //初始化朝代版的等级图片
	void InitMilitaryRankLevel(int a);                         //初始化军衔版的等级图片
	void InitCasperLevel(int a);                               //初始化学霸版的等级图片
	void DrawToBackground(IplImage * m_NumberImg,int x,int y); //将图片贴在背景上
	void ProduceNumberBox(int getnumber);                      //产生新的方块
	void InitSourceBackground(int a);                          //初始化背景图片

private:
	IplImage* m_0;
	IplImage* m_2;
	IplImage* m_64;
	IplImage* m_128;
	IplImage* m_256;
	IplImage* m_512;
	IplImage* m_1024;
	IplImage* m_2048;
	IplImage* m_4096;
	IplImage* m_8192;
};

