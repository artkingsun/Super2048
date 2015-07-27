#include "stdafx.h"
#include "Music.h"


CMusic::CMusic(void)
{
}


CMusic::~CMusic(void)
{
}


void CMusic::PlayStartMusic(void)
{
	mciSendString(TEXT("play start.mp3"),NULL,0,NULL);//��ʼ�˵�����
}


void CMusic::PlayBackgroundMusic(void)
{
	mciSendString(TEXT("play back.wav"),NULL,0,NULL);//��������
}


void CMusic::PlayNewLevelMusic(int m_NewNumber)
{
	//��ͬ�ĵȼ����в�ͬ����Ч
	switch (m_NewNumber)
	{
	case 124:mciSendString(TEXT("play 512.mp3"), NULL, 0, NULL);
		break;
	case 256:mciSendString(TEXT("play 512.mp3"), NULL, 0, NULL);
		break;
	case 512:mciSendString(TEXT("play 512.mp3"), NULL, 0, NULL);
		break;
	case 1024:mciSendString(TEXT("play 1024.mp3"), NULL, 0, NULL);
		break;
	case 2048:mciSendString(TEXT("play 2048.mp3"), NULL, 0, NULL);
		break;
	case 4096:mciSendString(TEXT("play 4096.mp3"), NULL, 0, NULL);
		break;
	case 8192:mciSendString(TEXT("play 8192.mp3"), NULL, 0, NULL);
		break;
	}
}


void CMusic::PlayAddBoxMusic(void)
{
	PlaySound(TEXT("add.wav"), NULL, SND_FILENAME | SND_ASYNC);  //�����·���
}


void CMusic::StopStartMusic(void)
{
	mciSendString(TEXT("stop start.mp3"),NULL,0,NULL);//��ʼ�˵�����
}


void CMusic::StopBackgroundMusic(void)
{
	mciSendString(TEXT("stop back.wav"),NULL,0,NULL);//��������
}


void CMusic::PlayWinMusic(void)
{
	mciSendString(TEXT("play V.mp3"),NULL,0,NULL);//�ﵽ��ߵȼ��Ľ�������
}
