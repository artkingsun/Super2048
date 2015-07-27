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

	void InitSourceNumber(void);                               //��ʼ�����ְ淽��
	void InitSourceDynasty(void);                              //��ʼ�������淽��
	void InitSourceMilitaryRank(void);                         //��ʼ�����ΰ淽��
	void InitSourceCasper(void);                               //��ʼ��ѧ�԰淽��
	void InitDynastyLevel(int a);                              //��ʼ��������ĵȼ�ͼƬ
	void InitMilitaryRankLevel(int a);                         //��ʼ�����ΰ�ĵȼ�ͼƬ
	void InitCasperLevel(int a);                               //��ʼ��ѧ�԰�ĵȼ�ͼƬ
	void DrawToBackground(IplImage * m_NumberImg,int x,int y); //��ͼƬ���ڱ�����
	void ProduceNumberBox(int getnumber);                      //�����µķ���
	void InitSourceBackground(int a);                          //��ʼ������ͼƬ

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

