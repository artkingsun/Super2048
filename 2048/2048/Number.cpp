#include "stdafx.h"
#include "Number.h"


CNumber::CNumber(void)
{
	//将每个方格对应的数字赋值为0
	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j < 4;j++)
		{
			m_Number[i][j] = 0;
		}
	}

	//随机产生2个坐标，并随机赋值2或4   bug产生的坐标可能相同
	int x1 = rand()%4;
	int x2 = rand()%4;
	int y1 = rand()%4;
	int y2 = rand()%4;

	m_Number[x1][y1] = (rand()%2 + 1) * 2;
	m_Number[x2][y2] = (rand()%2 + 1) * 2;

	//初始化对应数字方块的数量
	m_NumberBox4 = 8;
	m_NumberBox8 = 4;
	m_NumberBox16 = 2;
	m_NumberBox32 = 1;

	m_NewNumber = 0;
	m_Score = 0;
	m_HighScore = 0;
	m_Level = 0;
	m_HighLevel = 0;
}


CNumber::~CNumber(void)
{
}


void CNumber::InitNumber(void)
{
	//将每个方格对应的数字赋值为0
	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j < 4;j++)
		{
			m_Number[i][j] = 0;
		}
	}

	//随机产生2个坐标，并随机赋值2或4   bug产生的坐标可能相同
	int x1 = rand()%4;
	int x2 = rand()%4;
	int y1 = rand()%4;
	int y2 = rand()%4;

	m_Number[x1][y1] = (rand()%2 + 1) * 2;
	m_Number[x2][y2] = (rand()%2 + 1) * 2;

	//初始化对应数字方块的数量
	m_NumberBox4 = 8;
	m_NumberBox8 = 4;
	m_NumberBox16 = 2;
	m_NumberBox32 = 1;

	m_NewNumber = 0;
	m_Score = 0;
	m_HighScore = 0;
	m_Level = 0;
	m_HighLevel = 0;
}


void CNumber::Up(void)
{
	//将数字方块往上挪
	for (int i = 0;i < 4;i++)
	{
		for (int n = 0;n < 4;n++)
		{
			if (m_Number[i][0] == 0)
			{
				m_Number[i][0] = m_Number[i][1];
				m_Number[i][1] = m_Number[i][2];
				m_Number[i][2] = m_Number[i][3];
				m_Number[i][3] = 0;
			}
		}

		for (int n = 0;n < 3;n++)
		{
			if (m_Number[i][1] == 0)
			{
				m_Number[i][1] = m_Number[i][2];
				m_Number[i][2] = m_Number[i][3];
				m_Number[i][3] = 0;
			}
		}

		for (int n = 0;n < 2;n++)
		{
			if (m_Number[i][2] == 0)
			{
				m_Number[i][2] = m_Number[i][3];
				m_Number[i][3] = 0;
			}
		}	
	}

	//执行加法运算
	for (int i = 0;i < 4;i++)
	{
		if (m_Number[i][0] == m_Number[i][1])
		{
			m_Number[i][0] = 2 * m_Number[i][1];
			m_Score +=  m_Number[i][0];
			m_Number[i][1] = m_Number[i][2];
			m_Number[i][2] = m_Number[i][3];
			m_Number[i][3] = 0;
		}
		if (m_Number[i][1] == m_Number[i][2])
		{
			m_Number[i][1] = 2 * m_Number[i][2];
			m_Score +=  m_Number[i][1];
			m_Number[i][2] = m_Number[i][3];
			m_Number[i][3] = 0;
		}
		if (m_Number[i][2] == m_Number[i][3])
		{
			m_Number[i][2] = 2 * m_Number[i][3];
			m_Score +=  m_Number[i][2];
			m_Number[i][3] = 0;
		}
	}
	//AddBox(m_Number[0][3],m_Number[1][3],m_Number[2][3],m_Number[3][3]);

	//按概论产生一个2或者4的数字
	int m = rand()%3;
	switch (m)
	{
	case 0:m_NewNumber = 4;
		break;
	default:m_NewNumber = 2;
		break;
	}
	cout<<m_NewNumber<<"AddBox"<<endl;
	//随机产生数字方块的位置，新的方块在运动方向的相反方向产生

	int r = 0;
	for (int t = 0;t < 4;t++)
	{
		if (m_Number[t][3] == 0)
		{
			r++;
		}
	}
	if (r != 0)
	{
		int s = rand()%r;
		for (int t = 0;t < 4;t++)
		{
			if (m_Number[t][3] == 0)
			{
				if (s == t)
				{
					music.PlayAddBoxMusic();
					m_Number[t][3] = m_NewNumber;
					break;
				}
			}
			else
			{
				s++;
			}
		}
	}
	cout<<"up"<<endl;
}


void CNumber::Down(void)
{
	//将数字方块往下挪
	for (int i = 0;i < 4;i++)
	{
		for (int n = 0;n < 2;n++)
		{
			if (m_Number[i][3] == 0)
			{
				m_Number[i][3] = m_Number[i][2];
				m_Number[i][2] = m_Number[i][1];
				m_Number[i][1] = m_Number[i][0];
				m_Number[i][0] = 0;
			}
		}

		for (int n = 0;n < 3;n++)
		{
			if (m_Number[i][2] == 0)
			{
				m_Number[i][2] = m_Number[i][1];
				m_Number[i][1] = m_Number[i][0];
				m_Number[i][0] = 0;
			}
		}

		for (int n = 0;n < 2;n++)
		{
			if (m_Number[i][1] == 0)
			{
				m_Number[i][1] = m_Number[i][0];
				m_Number[i][0] = 0;
			}
		}	
	}

	//执行加法运算
	for (int i = 0;i < 4;i++)
	{
		if (m_Number[i][3] == m_Number[i][2])
		{
			m_Number[i][3] = 2 * m_Number[i][2];
			m_Score +=  m_Number[i][3];
			m_Number[i][2] = m_Number[i][1];
			m_Number[i][1] = m_Number[i][0];
			m_Number[i][0] = 0;
		}
		if (m_Number[i][2] == m_Number[i][1])
		{
			m_Number[i][2] = 2 * m_Number[i][1];
			m_Score +=  m_Number[i][2];
			m_Number[i][1] = m_Number[i][0];
			m_Number[i][0] = 0;

		}
		if (m_Number[i][1] == m_Number[i][0])
		{
			m_Number[i][1] = 2 * m_Number[i][0];
			m_Score +=  m_Number[i][1];
			m_Number[i][0] = 0;
		}
	}
	//AddBox(m_Number[0][0],m_Number[1][0],m_Number[2][0],m_Number[3][0]);
	int m = rand()%3;
	switch (m)
	{
	case 0:m_NewNumber = 4;
		break;
	default:m_NewNumber = 2;
		break;
	}
	cout<<m_NewNumber<<"AddBox"<<endl;

	int r = 0;
	for (int t = 0;t < 4;t++)
	{
		if (m_Number[t][0] == 0)
		{
			r++;
		}
	}

	if (r != 0)
	{
		int s = rand()%r;
		for (int t = 0;t < 4;t++)
		{
			if (m_Number[t][0] == 0)
			{
				if (s == t)
				{
					music.PlayAddBoxMusic();
					m_Number[t][0] = m_NewNumber;
					break;
				}
			}
			else
			{
				s++;
			}
		}
	}
	
	cout<<"down"<<endl;
}



void CNumber::Left(void)
{
	//将数字方块往左挪

	for (int j = 0;j < 4;j++)
	{
		for (int n = 0;n < 4;n++)
		{
			if (m_Number[0][j] == 0)
			{
				m_Number[0][j] = m_Number[1][j];
				m_Number[1][j] = m_Number[2][j];
				m_Number[2][j] = m_Number[3][j];
				m_Number[3][j] = 0;
			}
		}

		for (int n = 0;n < 3;n++)
		{
			if (m_Number[1][j] == 0)
			{
				m_Number[1][j] = m_Number[2][j];
				m_Number[2][j] = m_Number[3][j];
				m_Number[3][j] = 0;
			}
		}

		for (int n = 0;n < 2;n++)
		{
			if (m_Number[2][j] == 0)
			{
				m_Number[2][j] = m_Number[3][j];
				m_Number[3][j] = 0;
			}
		}
	}

	//执行加法运算
	for (int j = 0;j < 4;j++)
	{
		if (m_Number[0][j] == m_Number[1][j])
		{
			m_Number[0][j] = 2 * m_Number[1][j];
			m_Score +=  m_Number[0][j];
			m_Number[1][j] = m_Number[2][j];
			m_Number[2][j] = m_Number[3][j];
			m_Number[3][j] = 0;
		}
		if (m_Number[1][j] == m_Number[2][j])
		{
			m_Number[1][j] = 2 * m_Number[2][j];
			m_Score +=  m_Number[1][j];
			m_Number[2][j] = m_Number[3][j];
			m_Number[3][j] = 0;
		}
		if (m_Number[2][j] == m_Number[3][j])
		{
			m_Number[2][j] = 2 * m_Number[3][j];
			m_Score +=  m_Number[2][j];
			m_Number[3][j] = 0;
		}
	}

	//随机产生2或者4，按照2:1的比例
	int m = rand()%3;
	switch (m)
	{
	case 0:m_NewNumber = 4;
		break;
	default:m_NewNumber = 2;
		break;
	}
	//计算相反的列或行有几个空格
	int r = 0;
	for (int t = 0;t < 4;t++)
	{
		if (m_Number[3][t] == 0)
		{
			r++;
		}
	}
	//随机赋值给新产生的方块
	if (r != 0)
	{
		int s = rand()%r;
		for (int t = 0;t < 4;t++)
		{
			if (m_Number[3][t] == 0)
			{
				if (s == t)
				{
					music.PlayAddBoxMusic();
					m_Number[3][t] = m_NewNumber;
					break;
				}
			}
			else
			{
				s++;
			}
		}
	}
	
	//只要是能执行方向键的，反方向一定有空格
	cout<<m_Number[3][0]<<m_Number[3][1]<<m_Number[3][1]<<m_Number[3][2]<<"left"<<endl;
}



void CNumber::Right(void)
{
	//将数字方块往右挪

	for (int j = 0;j < 4;j++)
	{
		for (int n = 0;n < 4;n++)
		{
			if (m_Number[3][j] == 0)
			{
				m_Number[3][j] = m_Number[2][j];
				m_Number[2][j] = m_Number[1][j];
				m_Number[1][j] = m_Number[0][j];
				m_Number[0][j] = 0;
			}
		}

		for (int n = 0;n < 3;n++)
		{
			if (m_Number[2][j] == 0)
			{
				m_Number[2][j] = m_Number[1][j];
				m_Number[1][j] = m_Number[0][j];
				m_Number[0][j] = 0;
			}
		}

		for (int n = 0;n < 2;n++)
		{
			if (m_Number[1][j] == 0)
			{
				m_Number[1][j] = m_Number[0][j];
				m_Number[0][j] = 0;
			}
		}
	}

	//执行加法运算
	for (int j = 0;j < 4;j++)
	{
		if (m_Number[3][j] == m_Number[2][j])
		{
			m_Number[3][j] = 2 * m_Number[2][j];
			m_Score +=  m_Number[3][j];
			m_Number[2][j] = m_Number[1][j];
			m_Number[1][j] = m_Number[0][j];
			m_Number[0][j] = 0;
		}
		if (m_Number[2][j] == m_Number[1][j])
		{
			m_Number[2][j] = 2 * m_Number[1][j];
			m_Score +=  m_Number[2][j];
			m_Number[1][j] = m_Number[0][j];
			m_Number[0][j] = 0;
		}
		if (m_Number[1][j] == m_Number[0][j])
		{
			m_Number[1][j] = 2 * m_Number[0][j];
			m_Score +=  m_Number[1][j];
			m_Number[0][j] = 0;
		}
	}
	//AddBox(m_Number[0][0],m_Number[0][1],m_Number[0][2],m_Number[0][3]);
	//随机产生2或4的新方块
	int m = rand()%3;
	switch (m)
	{
	case 0:m_NewNumber = 4;
		break;
	default:m_NewNumber = 2;
		break;
	}
	cout<<m_NewNumber<<"AddBox"<<endl;

	//计算反方向的空格数
	int r = 0;
	for (int t = 0;t < 4;t++)
	{
		if (m_Number[0][t] == 0)
		{
			r++;
		}
	}
	//随机选择位置
	if (r != 0)
	{
		int s = rand()%r;
		for (int t = 0;t < 4;t++)
		{
			if (m_Number[0][t] == 0)
			{
				if (s == t)
				{
					music.PlayAddBoxMusic();
					m_Number[0][t] = m_NewNumber;
					break;
				}
			}
			else
			{
				s++;
			}
		}
	}
	
	cout<<"right"<<endl;
}

void CNumber::Level(void)
{
	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j < 4;j++)
		{
			if (m_Level < m_Number[i][j])
			{
				music.PlayNewLevelMusic(m_Number[i][j]);
				m_Level = m_Number[i][j];
			}
		}
	}
}


int CNumber::End(void)
{
	int s = 0,t = 0;
	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j < 4;j++)
		{
			if (m_Number[i][j] > 0)
			{		
				t += 1;
			}
		}
	}
	
	for (int t = 0;t < 4;t++)
	{
		if (m_Number[0][t] != m_Number[1][t] 
		&& m_Number[1][t] != m_Number[2][t]
		&& m_Number[2][t] != m_Number[3][t]
		&& m_Number[t][0] != m_Number[t][1] 
		&& m_Number[t][1] != m_Number[t][2]
		&& m_Number[t][2] != m_Number[t][3])
		{
			s += 4;
		}
	}
	if (t == 16 && s == 16)
	{
		return 16;
	}
	return 0;
}

void CNumber::WriteInLevel(void)
{
	ofstream out;
	out.open("HighLevel.txt", ios::binary);
	//以二进制形式写入m_HighLevel
	out.write((char *)&m_HighLevel,sizeof(m_HighLevel)); 
	out.close(); 
}


void CNumber::ReadOutLevel(void)
{
	ifstream in;
	in.open("HighLevel.txt", ios::binary); 
	//读取m_HighLevel 
	in.read((char*)&m_HighLevel,sizeof(m_HighLevel)); 
	in.close(); 
}


void CNumber::WriteInScore(void)
{
	ofstream out;
	out.open("HighScore.txt", ios::binary);
	//以二进制形式写入m_HighScore
	out.write((char *)&m_HighScore,sizeof(m_HighScore)); 
	out.close(); 
}


void CNumber::ReadOutScore(void)
{
	ifstream in;
	in.open("HighScore.txt", ios::binary); 
	//读取m_HighScore 
	in.read((char*)&m_HighScore,sizeof(m_HighScore)); 
	in.close(); 
}
