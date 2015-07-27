#pragma once
#include "opencv2/opencv.hpp"
#include "Number.h"
#include "Source.h"
#include "Music.h"
#include "windows.h"
#include "mmsystem.h"//��������ͷ�ļ�
#pragma comment(lib, "winmm.lib")//��������ͷ�ļ���
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

	bool GameRun(void);                 //��Ϸ����

private:
	void GetKey(int key);               //���ܼ�������
	void Menu(void);                    //�˵���ʾ
	void Prop(void);                    //������ʾ
	void ChangeBox(void);               //�������
	void DrawBoxs(void);                //���Ʒ��鵽����
	void PropMove(void);                //�����ƶ�
	void Instruction(void);             //��Ϸ˵��
	void InitGame(void);                //��ʼ����Ϸ
	void ChooseVersion(int l_Choose);   //ѡ����Ϸģʽ
};

