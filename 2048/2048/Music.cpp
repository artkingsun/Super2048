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
	mciSendString(TEXT("play start.mp3"),NULL,0,NULL);//开始菜单音乐
}


void CMusic::PlayBackgroundMusic(void)
{
	mciSendString(TEXT("play back.wav"),NULL,0,NULL);//背景音乐
}


void CMusic::PlayNewLevelMusic(int m_NewNumber)
{
	//不同的等级会有不同的音效
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
	PlaySound(TEXT("add.wav"), NULL, SND_FILENAME | SND_ASYNC);  //增加新方块
}


void CMusic::StopStartMusic(void)
{
	mciSendString(TEXT("stop start.mp3"),NULL,0,NULL);//开始菜单音乐
}


void CMusic::StopBackgroundMusic(void)
{
	mciSendString(TEXT("stop back.wav"),NULL,0,NULL);//背景音乐
}


void CMusic::PlayWinMusic(void)
{
	mciSendString(TEXT("play V.mp3"),NULL,0,NULL);//达到最高等级的结束音乐
}
