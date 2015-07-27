#pragma once
#include "windows.h"
#include "mmsystem.h"//��������ͷ�ļ�
#pragma comment(lib, "winmm.lib")//��������ͷ�ļ���
class CMusic
{
public:
	CMusic(void);
	virtual ~CMusic(void);
	void PlayStartMusic(void);                   //���ſ�ʼ����
	void PlayBackgroundMusic(void);              //���ű�������
	void PlayNewLevelMusic(int m_NewNumber);     //���Ŵﵽ�µĵȼ�ʱ������
	void PlayAddBoxMusic(void);                  //���������·���ʱ������
	void StopStartMusic(void);                   //�رտ�ʼ����
	void StopBackgroundMusic(void);              //�رձ�������
	void PlayWinMusic(void);                     //���Ŵﵽ��ߵȼ�ʱ������
};

