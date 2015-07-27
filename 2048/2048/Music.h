#pragma once
#include "windows.h"
#include "mmsystem.h"//导入声音头文件
#pragma comment(lib, "winmm.lib")//导入声音头文件库
class CMusic
{
public:
	CMusic(void);
	virtual ~CMusic(void);
	void PlayStartMusic(void);                   //播放开始音乐
	void PlayBackgroundMusic(void);              //播放背景音乐
	void PlayNewLevelMusic(int m_NewNumber);     //播放达到新的等级时的音乐
	void PlayAddBoxMusic(void);                  //播放增加新方块时的音乐
	void StopStartMusic(void);                   //关闭开始音乐
	void StopBackgroundMusic(void);              //关闭背景音乐
	void PlayWinMusic(void);                     //播放达到最高等级时的音乐
};

