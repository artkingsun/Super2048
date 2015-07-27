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

	void InitNumber(void);                //��ֵ�ĳ�ʼ��
	void Up(void);                        //�����˶�
	void Down(void);                      //�����˶�
	void Left(void);                      //�����˶�
	void Right(void);                     //�����˶�
	void Level(void);                     //�ȼ�����
	int End(void);                        //�����ж�
	void WriteInLevel(void);              //������д����ߵȼ�
	void ReadOutLevel(void);              //��ȡ��ߵȼ�
	void WriteInScore(void);              //������д����߼�¼
	void ReadOutScore(void);              //��ȡ��߼�¼
};

