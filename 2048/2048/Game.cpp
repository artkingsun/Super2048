#include "stdafx.h"
#include "Game.h"

CvPoint l_MousePos;
bool l_PropMouse = false;
bool l_StartMouse = false;
bool l_EndMouse = false;
bool l_Instruction = false;
bool l_BackMain = false;
int l_PropNumber = 0;
int l_PropX = -1;
int l_PropY = -1;
int l_Choose = 0;

CGame game;

//��Ϸ��ʼʱ�������Ӧ
void on_MouseStart(int event ,int x,int y,int flags,void * param)
{
	if (event == CV_EVENT_LBUTTONUP)//���������²�����
	{
		//ѡ��ʼ��Ϸ
		//���ְ�
		if (x > 45 && x < 240 && y > 100 && y < 170)
		{
			l_Choose = 1;
			if (l_StartMouse == false)
			{
				l_StartMouse = true;
			}
		}
		//���ΰ�
		if (x > 45 && x < 240 && y > 205 && y < 275)
		{
			l_Choose = 2;
			if (l_StartMouse == false)
			{
				l_StartMouse = true;
			}
		}
		//������
		if (x > 45 && x < 240 && y > 310 && y < 380)
		{
			l_Choose = 3;
			if (l_StartMouse == false)
			{
				l_StartMouse = true;
			}
		}
		//ѧ�԰�
		if (x > 45 && x < 240 && y > 410 && y < 480)
		{
			l_Choose = 4;
			if (l_StartMouse == false)
			{
				l_StartMouse = true;
			}
		}
		//������Ϸ
		if (x > 890 && x < 1125 && y > 310 && y < 380)
		{
			if (l_EndMouse == false)
			{
				l_EndMouse = true;
			}
		}
		//��Ϸ˵��
		if (x > 890 && x < 1125 && y > 165 && y < 235)
		{
			if (l_Instruction == false)
			{
				l_Instruction = true;
			}
		}
	}
}
//�������˵��������Ӧ
void on_MouseInstruction(int event ,int x,int y,int flags,void * param)
{
	if (event == CV_EVENT_LBUTTONUP)//���������²�����
	{
		if (x > 500 && x < 700 && y > 460 && y < 530)
		{
			if (l_BackMain == false)
			{
				l_BackMain = true;
			}
		}
	}
}

//���ߵ������Ӧ
void on_MouseProp(int event ,int x,int y,int flags,void * param)
{
	//ѡ�����
	if (event == CV_EVENT_LBUTTONUP)//���������²�����
	{
		if (x > 900&&x < 1050&& y > 0&& y < 600)
		{
			if (l_PropMouse == false)
			{
				l_PropMouse = true;
				l_MousePos.x = x;
				l_MousePos.y = y;

				switch (l_MousePos.y/150)
				{
				case  0:l_PropNumber = 4;
					break;
				case  1:l_PropNumber = 8;
					break;
				case  2:l_PropNumber = 16;
					break;
				default:l_PropNumber = 32;
					break;
				}
			}
		}
	}
	//���ߵ��ƶ�
	if (event == CV_EVENT_MOUSEMOVE)//����ƶ�
	{
		if (l_PropMouse == true)
		{
			l_MousePos.x = x;
			l_MousePos.y = y;
		}	
	}

	//���ߵ�Ӧ��
	if (event == CV_EVENT_LBUTTONUP)//���������²�����
	{
		if (x > 250&&x < 850&& y > 0&& y < 600)
		{
			if (l_PropMouse == true)
			{
				l_PropMouse = false;
				//l_MousePos.x = x;
				//l_MousePos.y = y;
				l_PropX = (x - 250)/150;
				l_PropY = y/150;
			}	
		}
	}

	//ȡ������ѡ��
	if (event == CV_EVENT_RBUTTONDOWN)//����һ�
	{
		if (l_PropMouse == true)
		{
			l_PropMouse = false;
		}
	}
}

CGame::CGame(void)//��ʼ��
{
	
}


CGame::~CGame(void)
{
}


bool CGame::GameRun(void)
{
	int key;
	for (;;)
	{
		music.StopBackgroundMusic();//ֹͣ�������ֲ���
		music.PlayStartMusic();//���ſ�ʼ����
		cvWaitKey(40);//40����ˢ��һ��
		cvShowImage("2048",source.m_Start);//��ʾ����ͼƬ
		cvSetMouseCallback("2048",on_MouseStart,0);//��ʼ�˵��������Ӧ
		Instruction();//��Ϸ˵��
		
		if (l_EndMouse == true)//�˳���Ϸ
		{
			l_EndMouse = false;
			return false;
			break;
		}

		if (l_StartMouse == true)//��ʼ��Ϸ
		{
			l_StartMouse = false;
			number.ReadOutLevel();//��ȡ��߼�¼
			number.ReadOutScore();//��ȡ��ߵȼ�
			music.StopStartMusic();//ֹͣ���ſ�ʼ����
			music.PlayBackgroundMusic();//��ʼ���ű�������
			ChooseVersion(l_Choose);//ѡ����Ϸģʽ
			source.InitSourceBackground(l_Choose);//ѡ����Ϸ����
			source.m_ShowImg = cvCreateImage(cvGetSize(source.m_Back),source.m_Back->depth,3);
			cvCopy(source.m_Back,source.m_ShowImg,NULL);
			for(;;)
			{
				key = cvWaitKey(40);//40����ˢ��һ��
				cvSetMouseCallback("2048",on_MouseProp,0);//���ߵ������Ӧ
				cvCopy(source.m_ShowImg,source.m_Back,NULL);//���Ʊ���
				GetKey(key);//���ܼ�������
				Prop();//��ʾ����		
				ChangeBox();//���߸�д����
				DrawBoxs();//���������ڱ�����
				Menu();//�˵�
				PropMove();//���߲��ƶ�
				cvShowImage("2048",source.m_Back);//��ʾ����ͼƬ
				number.WriteInLevel();//����ߵȼ�д���ļ�
				number.WriteInScore();//����߼�¼д���ļ�
				 
				if (16 == number.End())//�ж���Ϸ����
				{
					InitGame();
					break;
					GameRun();
					return false;
				}
				
				if (key == 27||number.m_HighLevel == 8192)//�˳� �������˵�
				{
					if (number.m_HighLevel == 8192)
					{
						music.PlayWinMusic();
					}
					break;
					GameRun();
					return false;
				}
			}
		}
	}
	return true;
}

//���̿���
void CGame::GetKey(int key)
{
	switch (key)
	{
	case 'W':number.Up();
		break;
	case 'w':number.Up();
		break;
	case '8':number.Up();
		break;
	case 'S':number.Down();
		break;
	case 's':number.Down();
		break;
	case '5':number.Down();
		break;
	case 'A':number.Left();
		break;
	case 'a':number.Left();
		break;
	case '4':number.Left();
		break;
	case 'D':number.Right();
		break;
	case 'd':number.Right();
		break;
	case '6':number.Right();
		break;
	}
}

//�˵���ʾ�÷ֵ���Ϣ
void CGame::Menu(void)
{
	number.Level();//���㵱ǰ�ȼ�
	if (number.m_Score >= number.m_HighScore)
	{
		number.m_HighScore = number.m_Score;
	}
	if (number.m_Level >= number.m_HighLevel)
	{
		number.m_HighLevel = number.m_Level;
	}
	//ͼƬ����ʾ����
	CvFont font;
	cvInitFont(&font, CV_FONT_HERSHEY_COMPLEX, 1.0, 1.0, 0, 2, 8); //��������

	char textscore[10],texthighscore[10],texthighlevel[10],textlevel[10];
	//����
	sprintf_s (textscore,"%d",number.m_Score);//��ǰ����
	sprintf_s (texthighscore,"%d",number.m_HighScore);//��߷���
	cvPutText(source.m_Back, "High Score", cvPoint(50,105), &font, CV_RGB(91,155,213)); 
	cvPutText(source.m_Back, texthighscore, cvPoint(50,155), &font, CV_RGB(255,255,255)); //��ʾ��߷���
	cvPutText(source.m_Back, "Score", cvPoint(50,205), &font, CV_RGB(0,255,0)); 
	cvPutText(source.m_Back, textscore, cvPoint(50,255), &font, CV_RGB(255,255,255)); //��ʾ��ǰ����
	//�ȼ�
	sprintf_s (textlevel,"%d",number.m_Level);//��ǰ�ȼ�
	sprintf_s (texthighlevel,"%d",number.m_HighLevel);//��ߵȼ�
	cvPutText(source.m_Back, "High Level", cvPoint(50,305), &font, CV_RGB(255,255,0)); 
	cvPutText(source.m_Back, "Level", cvPoint(50,405), &font, CV_RGB(255,0,0)); 
	
	//��ͬģʽ��ʾ��ͬ
	switch (l_Choose)
	{
	case 1:
		cvPutText(source.m_Back, texthighlevel, cvPoint(50,355), &font, CV_RGB(255,255,255)); //��ʾ��ߵȼ�
		cvPutText(source.m_Back, textlevel, cvPoint(50,455), &font, CV_RGB(255,255,255)); //��ʾ��ǰ�ȼ�
		break;
	case 2:
		source.InitMilitaryRankLevel(number.m_HighLevel);
		source.DrawToBackground(source.m_MilitaryRankLevel,20,305);
		source.InitMilitaryRankLevel(number.m_Level);
		source.DrawToBackground(source.m_MilitaryRankLevel,20,405);
		break;
	case 3:
		source.InitDynastyLevel(number.m_HighLevel);
		source.DrawToBackground(source.m_DynastyLevel,20,325);
		source.InitDynastyLevel(number.m_Level);
		source.DrawToBackground(source.m_DynastyLevel,20,425);
		break;
	case 4:
		source.InitCasperLevel(number.m_HighLevel);
		source.DrawToBackground(source.m_CasperLevel,20,305);
		source.InitCasperLevel(number.m_Level);
		source.DrawToBackground(source.m_CasperLevel,20,405);
		break;
	}
}

//��ʾ����
void CGame::Prop(void)
{
	source.DrawToBackground(source.m_4,900,0);
	source.DrawToBackground(source.m_8,900,150);
	source.DrawToBackground(source.m_16,900,300);
	source.DrawToBackground(source.m_32,900,450);

	CvFont font;
	char text4[10],text8[10],text16[10],text32[10];

	sprintf_s (text4,"%d",number.m_NumberBox4);//��intת��Ϊchar��
	sprintf_s (text8,"%d",number.m_NumberBox8);
	sprintf_s (text16,"%d",number.m_NumberBox16);	
	sprintf_s (text32,"%d",number.m_NumberBox32);

	cvInitFont(&font, CV_FONT_HERSHEY_COMPLEX, 1.0, 1.0, 0, 2, 8); 

	cvPutText(source.m_Back, "X", cvPoint(1070,100), &font, CV_RGB(255,255,255)); 
	cvPutText(source.m_Back, "X", cvPoint(1070,250), &font, CV_RGB(255,255,255)); 
	cvPutText(source.m_Back, "X", cvPoint(1070,400), &font, CV_RGB(255,255,255)); 
	cvPutText(source.m_Back, "X", cvPoint(1070,550), &font, CV_RGB(255,255,255));

	cvPutText(source.m_Back, text4, cvPoint(1100,100), &font, CV_RGB(255,255,255));//��ʾ����Ϊ4�ķ���ĸ���
	cvPutText(source.m_Back, text8, cvPoint(1100,250), &font, CV_RGB(255,255,255)); //��ʾ����Ϊ8�ķ���ĸ���
	cvPutText(source.m_Back, text16, cvPoint(1100,400), &font, CV_RGB(255,255,255)); //��ʾ����Ϊ16�ķ���ĸ���
	cvPutText(source.m_Back, text32, cvPoint(1100,550), &font, CV_RGB(255,255,255)); //��ʾ����Ϊ32�ķ���ĸ���
}


void CGame::ChangeBox(void)
{
	//���߸�д����
	if (l_PropMouse == false && l_PropX != -1)//��ֹ������[0][0]λ�ó���
	{
		if (l_PropNumber == 4 && number.m_NumberBox4 != 0)
		{
			number.m_Score += l_PropNumber;
			number.m_Number[l_PropX][l_PropY] = l_PropNumber;
			number.m_NumberBox4--;
		}
		if (l_PropNumber == 8 && number.m_NumberBox8 != 0)
		{
			number.m_Score += l_PropNumber;
			number.m_Number[l_PropX][l_PropY] = l_PropNumber;
			number.m_NumberBox8--;
		}
		if (l_PropNumber == 16 && number.m_NumberBox16 != 0)
		{
			number.m_Score += l_PropNumber;
			number.m_Number[l_PropX][l_PropY] = l_PropNumber;
			number.m_NumberBox16--;
		}		
		if (l_PropNumber == 32 && number.m_NumberBox32 != 0)
		{
			number.m_Score += l_PropNumber;
			number.m_Number[l_PropX][l_PropY] = l_PropNumber;
			number.m_NumberBox32--;
		}
		l_PropX = l_PropY = -1;
	}
}

//����������ڱ�����
void CGame::DrawBoxs(void)
{
	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j < 4;j++)
		{
			source.ProduceNumberBox(0);
			source.DrawToBackground(source.m_Box,i*150 + 250,j*150);
		}
	}
	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j < 4;j++)
		{
			if (number.m_Number[i][j] != 0)
			{	
				source.ProduceNumberBox(number.m_Number[i][j]);
				source.DrawToBackground(source.m_Box,i*150 + 250,j*150);
			}
		}
	}
}

//���ߵ��ƶ�
void CGame::PropMove(void)
{
	if (l_PropMouse == true)
	{
		source.ProduceNumberBox(l_PropNumber);
		//��ֹԽ��
		if (l_MousePos.x <= 0)
		{
			l_MousePos.x = 0;
		}
		if (l_MousePos.x >= 1050)
		{
			l_MousePos.x = 1050;
		}
		if (l_MousePos.y <= 0)
		{
			l_MousePos.y = 0;
		}
		if (l_MousePos.y >= 450)
		{
			l_MousePos.y = 450;
		}
		source.DrawToBackground(source.m_Box,l_MousePos.x,l_MousePos.y);
	}
}

//��Ϸ˵��
void CGame::Instruction(void)
{
	if (l_Instruction == true)
	{
		l_Instruction = false;
		for (;;)
		{
			cvWaitKey(40);//40����ˢ��һ��
			cvShowImage("2048",source.m_Instruction);
			cvSetMouseCallback("2048",on_MouseInstruction,0);//
			if (l_BackMain == true)
			{
				l_BackMain = false;
				break;
			}
		}	
	}
}

//��ʼ����Ϸ
void CGame::InitGame(void)
{
	number.InitNumber();	
}

//ѡ��ͬ����Ϸģʽ
void CGame::ChooseVersion(int l_Choose)
{
	switch (l_Choose)
	{
	case 1:source.InitSourceNumber();
		break;
	case 2:source.InitSourceMilitaryRank();
		break;
	case 3:source.InitSourceDynasty();
		break;
	case 4:source.InitSourceCasper();
		break;
	}
}
