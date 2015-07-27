#include "stdafx.h"
#include "Source.h"


CSource::CSource(void)
{
	//初始化化一些数据
	cvNamedWindow("2048",1);
	m_0 = cvLoadImage("0.png",1);
	m_Start = cvLoadImage("start.png",1);
	m_Instruction = cvLoadImage("instruction.png",1);
	m_Back = NULL;//cvLoadImage("backs.png",1);
	m_Box = NULL;
	m_ShowImg = NULL;
	m_Version = NULL;
	m_CasperLevel = NULL;
	m_DynastyLevel = NULL;
	m_MilitaryRankLevel = NULL;
	//复制背景图片
	//m_ShowImg = cvCreateImage(cvGetSize(m_Back),m_Back->depth,3);
	//cvCopy(m_Back,m_ShowImg,NULL);
}


CSource::~CSource(void)
{
	cvReleaseImage(&m_Back);
	cvReleaseImage(&m_Start);
	cvReleaseImage(&m_ShowImg);
	cvReleaseImage(&m_Version);
	cvReleaseImage(&m_Instruction);
	cvReleaseImage(&m_CasperLevel);
	cvReleaseImage(&m_DynastyLevel);
	cvReleaseImage(&m_MilitaryRankLevel);

	cvReleaseImage(&m_0);
	cvReleaseImage(&m_2);
	cvReleaseImage(&m_4);
	cvReleaseImage(&m_8);
	cvReleaseImage(&m_16);
	cvReleaseImage(&m_32);
	cvReleaseImage(&m_64);
	cvReleaseImage(&m_128);
	cvReleaseImage(&m_256);
	cvReleaseImage(&m_512);
	cvReleaseImage(&m_1024);
	cvReleaseImage(&m_2048);
	cvReleaseImage(&m_4096);
	cvReleaseImage(&m_8192);
	cvDestroyWindow("2048");
}



void CSource::InitSourceNumber(void)
{
	//数字版方块
	m_2 = cvLoadImage("2.png",1);
	m_4 = cvLoadImage("4.png",1);
	m_8 = cvLoadImage("8.png",1);
	m_16 = cvLoadImage("16.png",1);
	m_32 = cvLoadImage("32.png",1);
	m_64 = cvLoadImage("64.png",1);
	m_128 = cvLoadImage("128.png",1);
	m_256 = cvLoadImage("256.png",1);
	m_512 = cvLoadImage("512.png",1);
	m_1024 = cvLoadImage("1024.png",1);
	m_2048 = cvLoadImage("2048.png",1);
	m_4096 = cvLoadImage("4096.png",1);
	m_8192 = cvLoadImage("8192.png",1);
}



void CSource::InitSourceDynasty(void)
{
	//朝代版方块
	m_2 = cvLoadImage("2.2.png",1);
	m_4 = cvLoadImage("4.2.png",1);
	m_8 = cvLoadImage("8.2.png",1);
	m_16 = cvLoadImage("16.2.png",1);
	m_32 = cvLoadImage("32.2.png",1);
	m_64 = cvLoadImage("64.2.png",1);
	m_128 = cvLoadImage("128.2.png",1);
	m_256 = cvLoadImage("256.2.png",1);
	m_512 = cvLoadImage("512.2.png",1);
	m_1024 = cvLoadImage("1024.2.png",1);
	m_2048 = cvLoadImage("2048.2.png",1);
	m_4096 = cvLoadImage("4096.2.png",1);
	m_8192 = cvLoadImage("8192.2.png",1);
}


void CSource::InitSourceMilitaryRank(void)
{
	//军衔版方块
	m_2 = cvLoadImage("2.1.png",1);
	m_4 = cvLoadImage("4.1.png",1);
	m_8 = cvLoadImage("8.1.png",1);
	m_16 = cvLoadImage("16.1.png",1);
	m_32 = cvLoadImage("32.1.png",1);
	m_64 = cvLoadImage("64.1.png",1);
	m_128 = cvLoadImage("128.1.png",1);
	m_256 = cvLoadImage("256.1.png",1);
	m_512 = cvLoadImage("512.1.png",1);
	m_1024 = cvLoadImage("1024.1.png",1);
	m_2048 = cvLoadImage("2048.1.png",1);
	m_4096 = cvLoadImage("4096.1.png",1);
	m_8192 = cvLoadImage("8192.1.png",1);
}


void CSource::InitSourceCasper(void)
{
	//学霸版方块
	m_2 = cvLoadImage("2.3.png",1);
	m_4 = cvLoadImage("4.3.png",1);
	m_8 = cvLoadImage("8.3.png",1);
	m_16 = cvLoadImage("16.3.png",1);
	m_32 = cvLoadImage("32.3.png",1);
	m_64 = cvLoadImage("64.3.png",1);
	m_128 = cvLoadImage("128.3.png",1);
	m_256 = cvLoadImage("256.3.png",1);
	m_512 = cvLoadImage("512.3.png",1);
	m_1024 = cvLoadImage("1024.3.png",1);
	m_2048 = cvLoadImage("2048.3.png",1);
	m_4096 = cvLoadImage("4096.3.png",1);
	m_8192 = cvLoadImage("8192.3.png",1);
}



void CSource::InitDynastyLevel(int a)
{
	//朝代版等级图片
	switch (a)
	{
	case 2:m_DynastyLevel = cvLoadImage("c2.png",1);
		break;
	case 4:m_DynastyLevel = cvLoadImage("c4.png",1);
		break;
	case 8:m_DynastyLevel = cvLoadImage("c8.png",1);
		break;
	case 16:m_DynastyLevel = cvLoadImage("c16.png",1);
		break;
	case 32:m_DynastyLevel = cvLoadImage("c32.png",1);
		break;
	case 64:m_DynastyLevel = cvLoadImage("c64.png",1);
		break;
	case 128:m_DynastyLevel = cvLoadImage("c128.png",1);
		break;
	case 256:m_DynastyLevel = cvLoadImage("c256.png",1);
		break;
	case 512:m_DynastyLevel = cvLoadImage("c512.png",1);
		break;
	case 1024:m_DynastyLevel = cvLoadImage("c1024.png",1);
		break;
	case 2048:m_DynastyLevel = cvLoadImage("c2048.png",1);
		break;
	case 4096:m_DynastyLevel = cvLoadImage("c4096.png",1);
		break;
	case 8192:m_DynastyLevel = cvLoadImage("c8192.png",1);
		break;
	}
}


void CSource::InitMilitaryRankLevel(int a)
{
	//军衔版等级图片
	switch (a)
	{
	case 2:m_MilitaryRankLevel = cvLoadImage("j2.png",1);
		break;
	case 4:m_MilitaryRankLevel = cvLoadImage("j4.png",1);
		break;
	case 8:m_MilitaryRankLevel = cvLoadImage("j8.png",1);
		break;
	case 16:m_MilitaryRankLevel = cvLoadImage("j16.png",1);
		break;
	case 32:m_MilitaryRankLevel = cvLoadImage("j32.png",1);
		break;
	case 64:m_MilitaryRankLevel = cvLoadImage("j64.png",1);
		break;
	case 128:m_MilitaryRankLevel = cvLoadImage("j128.png",1);
		break;
	case 256:m_MilitaryRankLevel = cvLoadImage("j256.png",1);
		break;
	case 512:m_MilitaryRankLevel = cvLoadImage("j512.png",1);
		break;
	case 1024:m_MilitaryRankLevel = cvLoadImage("j1024.png",1);
		break;
	case 2048:m_MilitaryRankLevel = cvLoadImage("j2048.png",1);
		break;
	case 4096:m_MilitaryRankLevel = cvLoadImage("j4096.png",1);
		break;
	case 8192:m_MilitaryRankLevel = cvLoadImage("j8192.png",1);
		break;
	}
}


void CSource::InitCasperLevel(int a)
{
	//学霸版等级图片
	switch (a)
	{
	case 2:m_CasperLevel = cvLoadImage("x2.png",1);
		break;
	case 4:m_CasperLevel = cvLoadImage("x4.png",1);
		break;
	case 8:m_CasperLevel = cvLoadImage("x8.png",1);
		break;
	case 16:m_CasperLevel = cvLoadImage("x16.png",1);
		break;
	case 32:m_CasperLevel = cvLoadImage("x32.png",1);
		break;
	case 64:m_CasperLevel = cvLoadImage("x64.png",1);
		break;
	case 128:m_CasperLevel = cvLoadImage("x128.png",1);
		break;
	case 256:m_CasperLevel = cvLoadImage("x256.png",1);
		break;
	case 512:m_CasperLevel = cvLoadImage("x512.png",1);
		break;
	case 1024:m_CasperLevel = cvLoadImage("x1024.png",1);
		break;
	case 2048:m_CasperLevel = cvLoadImage("x2048.png",1);
		break;
	case 4096:m_CasperLevel = cvLoadImage("x4096.png",1);
		break;
	case 8192:m_CasperLevel = cvLoadImage("x8192.png",1);
		break;
	}
}


void CSource::DrawToBackground(IplImage * m_NumberImg,int x,int y)
{
	int r,g,b;
	if (m_NumberImg != NULL && m_Back != NULL )
	{
		for(int i=0;i<m_NumberImg->width;i++)//i代表行
		{
			for(int j=0;j<m_NumberImg->height;j++)//j代表列
			{
				r = CV_IMAGE_ELEM( m_NumberImg, uchar, j, i*3+0);//红色通道赋值
				g = CV_IMAGE_ELEM( m_NumberImg, uchar, j, i*3+1);//绿色通道赋值
				b = CV_IMAGE_ELEM( m_NumberImg, uchar, j, i*3+2);//蓝色通道赋值
				if (!(r >220 && g >220 && b>220))  //使和白色相近的颜色透明
				{
					CV_IMAGE_ELEM( m_Back, uchar, y+j, (x+i)*3+0) = r;
					CV_IMAGE_ELEM( m_Back, uchar, y+j, (x+i)*3+1) = g; 
					CV_IMAGE_ELEM( m_Back, uchar, y+j, (x+i)*3+2) = b; 
				}
			}
		}
	}    
}


void CSource::ProduceNumberBox(int getnumber)
{
	//根据数字产生方块
	switch (getnumber)
	{
	case  0:m_Box = m_0;
		break;
	case 2:m_Box = m_2;
		break;
	case 4:m_Box = m_4;
		break;
	case 8:m_Box = m_8;
		break;
	case 16:m_Box = m_16;
		break;
	case 32:m_Box = m_32;
		break;
	case 64:m_Box = m_64;
		break;
	case 128:m_Box = m_128;
		break;
	case 256:m_Box = m_256;
		break;
	case 512:m_Box = m_512;
		break;
	case 1024:m_Box = m_1024;
		break;
	case 2048:m_Box = m_2048;
		break;
	case 4096:m_Box = m_4096;
		break;
	case 8192:m_Box = m_8192;
		break;
	}
}



void CSource::InitSourceBackground(int a)	
{
	//不同的游戏模式背景不同
	switch (a)
	{
	case 1:m_Back = cvLoadImage("back1.png",1);
		break;
	case 2:m_Back = cvLoadImage("back2.png",1);
		break;
	case 3:m_Back = cvLoadImage("back3.png",1);
		break;
	case 4:m_Back = cvLoadImage("back4.png",1);
		break;
	}
}
