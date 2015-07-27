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

//游戏开始时的鼠标响应
void on_MouseStart(int event ,int x,int y,int flags,void * param)
{
	if (event == CV_EVENT_LBUTTONUP)//鼠标左键按下并弹起
	{
		//选择开始游戏
		//数字版
		if (x > 45 && x < 240 && y > 100 && y < 170)
		{
			l_Choose = 1;
			if (l_StartMouse == false)
			{
				l_StartMouse = true;
			}
		}
		//军衔版
		if (x > 45 && x < 240 && y > 205 && y < 275)
		{
			l_Choose = 2;
			if (l_StartMouse == false)
			{
				l_StartMouse = true;
			}
		}
		//朝代版
		if (x > 45 && x < 240 && y > 310 && y < 380)
		{
			l_Choose = 3;
			if (l_StartMouse == false)
			{
				l_StartMouse = true;
			}
		}
		//学霸版
		if (x > 45 && x < 240 && y > 410 && y < 480)
		{
			l_Choose = 4;
			if (l_StartMouse == false)
			{
				l_StartMouse = true;
			}
		}
		//结束游戏
		if (x > 890 && x < 1125 && y > 310 && y < 380)
		{
			if (l_EndMouse == false)
			{
				l_EndMouse = true;
			}
		}
		//游戏说明
		if (x > 890 && x < 1125 && y > 165 && y < 235)
		{
			if (l_Instruction == false)
			{
				l_Instruction = true;
			}
		}
	}
}
//返回主菜单的鼠标响应
void on_MouseInstruction(int event ,int x,int y,int flags,void * param)
{
	if (event == CV_EVENT_LBUTTONUP)//鼠标左键按下并弹起
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

//道具的鼠标响应
void on_MouseProp(int event ,int x,int y,int flags,void * param)
{
	//选择道具
	if (event == CV_EVENT_LBUTTONUP)//鼠标左键按下并弹起
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
	//道具的移动
	if (event == CV_EVENT_MOUSEMOVE)//鼠标移动
	{
		if (l_PropMouse == true)
		{
			l_MousePos.x = x;
			l_MousePos.y = y;
		}	
	}

	//道具的应用
	if (event == CV_EVENT_LBUTTONUP)//鼠标左键按下并弹起
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

	//取消道具选中
	if (event == CV_EVENT_RBUTTONDOWN)//鼠标右击
	{
		if (l_PropMouse == true)
		{
			l_PropMouse = false;
		}
	}
}

CGame::CGame(void)//初始化
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
		music.StopBackgroundMusic();//停止背景音乐播放
		music.PlayStartMusic();//播放开始音乐
		cvWaitKey(40);//40毫秒刷新一次
		cvShowImage("2048",source.m_Start);//显示所有图片
		cvSetMouseCallback("2048",on_MouseStart,0);//开始菜单的鼠标响应
		Instruction();//游戏说明
		
		if (l_EndMouse == true)//退出游戏
		{
			l_EndMouse = false;
			return false;
			break;
		}

		if (l_StartMouse == true)//开始游戏
		{
			l_StartMouse = false;
			number.ReadOutLevel();//读取最高纪录
			number.ReadOutScore();//读取最高等级
			music.StopStartMusic();//停止播放开始音乐
			music.PlayBackgroundMusic();//开始播放背景音乐
			ChooseVersion(l_Choose);//选择游戏模式
			source.InitSourceBackground(l_Choose);//选择游戏背景
			source.m_ShowImg = cvCreateImage(cvGetSize(source.m_Back),source.m_Back->depth,3);
			cvCopy(source.m_Back,source.m_ShowImg,NULL);
			for(;;)
			{
				key = cvWaitKey(40);//40毫秒刷新一次
				cvSetMouseCallback("2048",on_MouseProp,0);//道具的鼠标响应
				cvCopy(source.m_ShowImg,source.m_Back,NULL);//复制背景
				GetKey(key);//接受键盘输入
				Prop();//显示道具		
				ChangeBox();//道具改写方块
				DrawBoxs();//将方块贴在背景上
				Menu();//菜单
				PropMove();//道具并移动
				cvShowImage("2048",source.m_Back);//显示所有图片
				number.WriteInLevel();//将最高等级写入文件
				number.WriteInScore();//将最高纪录写入文件
				 
				if (16 == number.End())//判断游戏结束
				{
					InitGame();
					break;
					GameRun();
					return false;
				}
				
				if (key == 27||number.m_HighLevel == 8192)//退出 返回主菜单
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

//键盘控制
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

//菜单显示得分等信息
void CGame::Menu(void)
{
	number.Level();//计算当前等级
	if (number.m_Score >= number.m_HighScore)
	{
		number.m_HighScore = number.m_Score;
	}
	if (number.m_Level >= number.m_HighLevel)
	{
		number.m_HighLevel = number.m_Level;
	}
	//图片上显示文字
	CvFont font;
	cvInitFont(&font, CV_FONT_HERSHEY_COMPLEX, 1.0, 1.0, 0, 2, 8); //字体设置

	char textscore[10],texthighscore[10],texthighlevel[10],textlevel[10];
	//分数
	sprintf_s (textscore,"%d",number.m_Score);//当前分数
	sprintf_s (texthighscore,"%d",number.m_HighScore);//最高分数
	cvPutText(source.m_Back, "High Score", cvPoint(50,105), &font, CV_RGB(91,155,213)); 
	cvPutText(source.m_Back, texthighscore, cvPoint(50,155), &font, CV_RGB(255,255,255)); //显示最高分数
	cvPutText(source.m_Back, "Score", cvPoint(50,205), &font, CV_RGB(0,255,0)); 
	cvPutText(source.m_Back, textscore, cvPoint(50,255), &font, CV_RGB(255,255,255)); //显示当前分数
	//等级
	sprintf_s (textlevel,"%d",number.m_Level);//当前等级
	sprintf_s (texthighlevel,"%d",number.m_HighLevel);//最高等级
	cvPutText(source.m_Back, "High Level", cvPoint(50,305), &font, CV_RGB(255,255,0)); 
	cvPutText(source.m_Back, "Level", cvPoint(50,405), &font, CV_RGB(255,0,0)); 
	
	//不同模式显示不同
	switch (l_Choose)
	{
	case 1:
		cvPutText(source.m_Back, texthighlevel, cvPoint(50,355), &font, CV_RGB(255,255,255)); //显示最高等级
		cvPutText(source.m_Back, textlevel, cvPoint(50,455), &font, CV_RGB(255,255,255)); //显示当前等级
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

//显示道具
void CGame::Prop(void)
{
	source.DrawToBackground(source.m_4,900,0);
	source.DrawToBackground(source.m_8,900,150);
	source.DrawToBackground(source.m_16,900,300);
	source.DrawToBackground(source.m_32,900,450);

	CvFont font;
	char text4[10],text8[10],text16[10],text32[10];

	sprintf_s (text4,"%d",number.m_NumberBox4);//将int转换为char型
	sprintf_s (text8,"%d",number.m_NumberBox8);
	sprintf_s (text16,"%d",number.m_NumberBox16);	
	sprintf_s (text32,"%d",number.m_NumberBox32);

	cvInitFont(&font, CV_FONT_HERSHEY_COMPLEX, 1.0, 1.0, 0, 2, 8); 

	cvPutText(source.m_Back, "X", cvPoint(1070,100), &font, CV_RGB(255,255,255)); 
	cvPutText(source.m_Back, "X", cvPoint(1070,250), &font, CV_RGB(255,255,255)); 
	cvPutText(source.m_Back, "X", cvPoint(1070,400), &font, CV_RGB(255,255,255)); 
	cvPutText(source.m_Back, "X", cvPoint(1070,550), &font, CV_RGB(255,255,255));

	cvPutText(source.m_Back, text4, cvPoint(1100,100), &font, CV_RGB(255,255,255));//显示数字为4的方块的个数
	cvPutText(source.m_Back, text8, cvPoint(1100,250), &font, CV_RGB(255,255,255)); //显示数字为8的方块的个数
	cvPutText(source.m_Back, text16, cvPoint(1100,400), &font, CV_RGB(255,255,255)); //显示数字为16的方块的个数
	cvPutText(source.m_Back, text32, cvPoint(1100,550), &font, CV_RGB(255,255,255)); //显示数字为32的方块的个数
}


void CGame::ChangeBox(void)
{
	//道具改写方块
	if (l_PropMouse == false && l_PropX != -1)//防止方块在[0][0]位置出现
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

//将方块绘制在背景上
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

//道具的移动
void CGame::PropMove(void)
{
	if (l_PropMouse == true)
	{
		source.ProduceNumberBox(l_PropNumber);
		//防止越界
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

//游戏说明
void CGame::Instruction(void)
{
	if (l_Instruction == true)
	{
		l_Instruction = false;
		for (;;)
		{
			cvWaitKey(40);//40毫秒刷新一次
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

//初始化游戏
void CGame::InitGame(void)
{
	number.InitNumber();	
}

//选择不同的游戏模式
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
