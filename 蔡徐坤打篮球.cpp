/*推箱子0.3 vel*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<windows.h>
#include<time.h>
#include<string.h>
#include<graphics.h>
#pragma comment(lib,"Winmm.lib")		//声音宏定义
#define caslength 6
#define line 10
IMAGE people;
IMAGE Box;
IMAGE Wall;
IMAGE Road;
IMAGE Basket;
IMAGE Baskets;
IMAGE peoples;

void Initialize();		//地图初始化，撤回操作 
void drawMap();			//绘图 
void keyDown();			//按键处理 
int gameOver();			//游戏结束判断 
void gameend();			//退出游戏 
void start();			//开始游戏 
void Nextcas();			//下一关 
void Lastcas();			//上一关 
void Endgame();			//通关游戏界面 
void to_withdraw();		//游戏提示 
void graph_initialization();	//图形初始化
void play_music();				//打开音乐
void exit_music();


int high = 10;
int map1[caslength][10][10];//临时数组保存 
int cas = 1;	//为0表示第一关
int step_number = 0;
//记录每一关的箱子数 或者是项目和目的在一起的总数
int boxSum[caslength] = { 4,3,2,3,3,3 };

char gamekey[caslength][120] = {
"ssswwwaadwwsddd",
"dddwwssaaawwddaassaaww",
"dwwaaawasddddssawdwaaassaaawwddsdsawwwdss",
"assdwssdsdssaawwwawwddssasssddwwawwwaswdwwass",
"wawsdddwwaasasdwaaasddwdwwasdsassdwawwdddssadwwaaassaawd",
"dwwwaaassaawwdassddwwddsdwwwasdsaaassaawwddddsdwsssawwdwawwdssswaaassaawwddddsdwaaaaawwddswaassddddsssdw"
};
//自己可以设计关卡 10*10 目前只有6关 
int map[caslength][10][10] = {
	{
	0, 0, 1, 1, 1, 0, 0, 0, 0, 0,
	0, 0, 1, 3, 1, 0, 0, 0, 0, 0,
	0, 0, 1, 0, 1, 1, 1, 1, 1, 0,
	1, 1, 1, 4, 0, 0, 4, 3, 1, 0,
	1, 3, 0, 4, 5, 1, 1, 1, 1, 0,
	1, 1, 1, 1, 0, 1, 0, 0, 0, 0,
	0, 0, 0, 1, 0, 1, 0, 0, 0, 0,
	0, 0, 0, 1, 4, 1, 0, 0, 0, 0,
	0, 0, 0, 1, 3, 1, 0, 0, 0, 0,
	0, 0, 0, 1, 1, 1, 0, 0, 0, 0
	}
,
	{
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
	1, 0, 0, 0, 0, 0, 0, 1, 0, 0,
	1, 3, 1, 0, 1, 1, 3, 1, 0, 0,
	1, 4, 0, 0, 4, 0, 3, 1, 0, 0,
	1, 0, 1, 0, 1, 1, 4, 1, 0, 0,
	1, 0, 0, 5, 0, 0, 0, 1, 0, 0,
	1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	}
,
	{
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 1, 1, 1, 1, 0, 0, 0,
	0, 1, 1, 1, 0, 0, 1, 1, 1, 1,
	0, 1, 0, 0, 0, 0, 0, 4, 0, 1,
	0, 1, 0, 1, 0, 0, 1, 4, 0, 1,
	0, 1, 0, 3, 0, 3, 1, 5, 0, 1,
	0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	}
,
	{
	0, 1, 1, 1, 1, 0, 0, 0, 0, 0,
	1, 1, 0, 0, 1, 0, 0, 0, 0, 0,
	1, 0, 5, 0, 1, 0, 0, 0, 0, 0,
	1, 0, 4, 0, 1, 0, 0, 0, 0, 0,
	1, 0, 7, 0, 1, 0, 0, 0, 0, 0,
	1, 0, 7, 0, 1, 1, 0, 0, 0, 0,
	1, 1, 3, 0, 0, 1, 0, 0, 0, 0,
	0, 1, 0, 1, 0, 1, 0, 0, 0, 0,
	0, 1, 0, 0, 0, 1, 0, 0, 0, 0,
	0, 1, 1, 1, 1, 1, 0, 0, 0, 0
	}
,	{
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
	0, 0, 1, 0, 0, 1, 1, 1, 0, 0,
	1, 1, 1, 0, 0, 0, 0, 1, 0, 0,
	1, 0, 0, 7, 3, 1, 0, 1, 0, 0,
	1, 0, 0, 4, 7, 0, 0, 1, 0, 0,
	1, 1, 1, 0, 5, 1, 1, 1, 0, 0,
	0, 0, 1, 0, 0, 1, 0, 0, 0, 0,
	0, 0, 1, 1, 1, 1, 0, 0, 0, 0
	}
,	{
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 1, 1, 1, 1, 1, 1, 1, 1, 0,
	0, 1, 0, 0, 0, 1, 0, 0, 1, 0,
	0, 1, 0, 1, 0, 1, 4, 3, 1, 0,
	0, 1, 0, 0, 0, 0, 4, 3, 1, 0,
	0, 1, 0, 1, 0, 1, 4, 3, 1, 0,
	0, 1, 0, 0, 0, 1, 0, 0, 1, 0,
	0, 1, 1, 1, 1, 1, 5, 0, 1, 0,
	0, 0, 0, 0, 0, 1, 1, 1, 1, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	}
};
int map2[1][10][10] = {
	{
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 1, 0, 0, 1, 0, 0, 0,
	0, 0, 1, 0, 1, 1, 0, 1, 0, 0,
	0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
	0, 0, 1, 0, 0, 0, 0, 1, 0, 0,
	0, 0, 0, 1, 0, 0, 1, 0, 0, 0,
	0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	}
};
int main()
{
	int startTime, endTime, toileTime = 0;
	start();
	Initialize();
	system("color 8E");
	graph_initialization();
	while (1)
	{
		startTime = clock();

		printf("\n\n\t\t   第【%d】关 你已经走了%d步\t游戏倒计时：%d 秒\n\t\t\t\t\t\t ☆箱子 ※目的地 ♀人\n \t\t\t\tR:撤回  T:下一关  Y:上一关  X:游戏提示  U:退出游戏  N:打开背景音乐 B:关闭背景音乐\n", cas, step_number, 120 - toileTime / 1000);
		//		if(60-toileTime/1000==0)
		//		exit(0); 
		drawMap();
		if (gameOver() == boxSum[cas])
		{
			cas++;
			Initialize();
			if (cas >= caslength) {
				system("cls");
				Endgame();
				break;
			}
		}
		keyDown();

		endTime = clock();

		toileTime = toileTime + (endTime - startTime);

		system("cls");
	}
	//	printf("\t\t\t\t恭喜你通过游戏。。。。。。\n\n");
	system("pause");
	return 0;
}

void Initialize() {
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < high; j++)
		{
			map1[cas][i][j] = map[cas][i][j];
		}
	}
	step_number = 0;
}
void drawMap()
{
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < high; j++)
		{
			if (j == 0)
				printf("\t\t");
			switch (map1[cas][i][j])
			{

			case 0:
				printf("  ");
				putimage(j * 50, i * 50, &Road);
				break;
			case 1:
				printf("▓");
				putimage(j * 50, i * 50, &Wall);
				break;

			case 3:
				printf("※");
				putimage(j * 50, i * 50, &Basket);
				break;
			case 4:
				printf("☆");
				putimage(j * 50, i * 50, &Box); 
				break;

			case 5:
			case 8:
				printf("♀");
				putimage(j * 50, i * 50, &people);
				break;
			case 7:
				printf("★");
				putimage(j * 50, i * 50, &Baskets);
				break;

			}
		}
		printf("\n");
	}
}
//按键处理
void keyDown()
{
	//分析按键过程
	//定位人在哪里
	//人有两种情况：第一个是：人，第二个：人站在目的上
	int i, j;
	for (i = 0; i < line; i++)
	{
		for (j = 0; j < high; j++)
		{
			if (map1[cas][i][j] == 5 || map1[cas][i][j] == 8)
			{
				break;
			}
		}
		if (map1[cas][i][j] == 5 || map1[cas][i][j] == 8)
		{
			break;
		}
	}

	char ch = _getch();	//看不见的字符输入，+头文件 conio.h
	switch (ch)
	{
		//72 80   75 77
	case 'w':
	case 'W':
	case 72:
		//下一个地方等于空地或者是目的 能走
		if (map1[cas][i - 1][j] == 0 || map1[cas][i - 1][j] == 3)
		{
			//3+5=8 ：表示目的和人在一起
			//新地方(map[i-1][j])人（5）来了
			map1[cas][i - 1][j] += 5;
			//老地方(map[i][j])人（5）走了
			map1[cas][i][j] -= 5;
			step_number++;
		}
		//如果下一个是箱子，要进一步判断能走
		//注意点：箱子两种状态：箱子，箱子和目的在一起
		else if (map1[cas][i - 1][j] == 4 || map1[cas][i - 1][j] == 7)
		{
			//做箱子的下一个地方判断能不能走
			if (map1[cas][i - 2][j] == 0 || map1[cas][i - 2][j] == 3)
			{
				//新的地方箱子来了
				map1[cas][i - 2][j] += 4;
				//箱子的位置：箱子（-4）走了 人来（+5）
				map1[cas][i - 1][j] += 1;
				//原来的地方人走了
				map1[cas][i][j] -= 5;
				step_number++;
			}

		}

		break;
	case 's':
	case 'S':
	case 80:
		//下一个地方等于空地或者是目的 能走
		if (map1[cas][i + 1][j] == 0 || map1[cas][i + 1][j] == 3)
		{
			//3+5=8 ：表示目的和人在一起
			//新地方(map[i-1][j])人（5）来了
			map1[cas][i + 1][j] += 5;
			//老地方(map[i][j])人（5）走了
			map1[cas][i][j] -= 5;
			step_number++;
		}
		else if (map1[cas][i + 1][j] == 4 || map1[cas][i + 1][j] == 7)
		{
			//做箱子的下一个地方判断能不能走
			if (map1[cas][i + 2][j] == 0 || map1[cas][i + 2][j] == 3)
			{
				//新的地方箱子来了
				map1[cas][i + 2][j] += 4;
				//箱子的位置：箱子（-4）走了 人来（+5）
				map1[cas][i + 1][j] += 1;
				//原来的地方人走了
				map1[cas][i][j] -= 5;
				step_number++;
			}

		}
		break;

	case 'a':
	case 'A':
	case 75:
		//下一个地方等于空地或者是目的 能走
		if (map1[cas][i][j - 1] == 0 || map1[cas][i][j - 1] == 3)
		{
			//3+5=8 ：表示目的和人在一起
			//新地方(map[i-1][j])人（5）来了
			map1[cas][i][j - 1] = map1[cas][i][j - 1] + 5;
			//老地方(map[i][j])人（5）走了
			map1[cas][i][j] = map1[cas][i][j] - 5;
			//j+=5  j=j+5
			step_number++;
		}
		else if (map1[cas][i][j - 1] == 4 || map1[cas][i][j - 1] == 7)
		{
			//做箱子的下一个地方判断能不能走
			if (map1[cas][i][j - 2] == 0 || map1[cas][i][j - 2] == 3)
			{
				//新的地方箱子来了
				map1[cas][i][j - 2] += 4;
				//箱子的位置：箱子（-4）走了 人来（+5）
				map1[cas][i][j - 1] += 1;
				//原来的地方人走了
				map1[cas][i][j] -= 5;
				step_number++;
			}

		}

		break;
	case 'D':
	case 'd':
	case 77:
		//下一个地方等于空地或者是目的 能走
		if (map1[cas][i][j + 1] == 0 || map1[cas][i][j + 1] == 3)
		{
			//3+5=8 ：表示目的和人在一起
			//新地方(map[i-1][j])人（5）来了
			map1[cas][i][j + 1] += 5;
			//老地方(map[i][j])人（5）走了
			map1[cas][i][j] -= 5;
			step_number++;	//步速++ 
		}

		//下一个地方是箱子，判断箱子的下一个地方是不是目的和空地
		else if (map1[cas][i][j + 1] == 4 || map1[cas][i][j + 1] == 7)
		{
			//做箱子的下一个地方判断能不能走
			if (map1[cas][i][j + 2] == 0 || map1[cas][i][j + 2] == 3)
			{
				//新的地方箱子来了
				map1[cas][i][j + 2] += 4;
				//箱子的位置：箱子（-4）走了 人来（+5）
				map1[cas][i][j + 1] += 1;
				//原来的地方人走了
				map1[cas][i][j] -= 5;
				step_number++;
			}

		}
		break;
	case 'R':
	case 'r':
		Initialize();
		break;
	case 'u':
	case 'U':
		gameend();
		break;
	case 't':
	case 'T':
		Nextcas();
		break;
	case 'y':
	case 'Y':
		Lastcas();
		break;
	case 'x':
	case 'X':
		to_withdraw();
		break;
	case 'N':
	case 'n':
		play_music();
		break;
	case 'B':
	case 'b':
		exit_music();
		break;
	}
}
//胜负判断
//用什么判断胜负： 箱子到达目的的个数
int gameOver()
{
	int count = 0;
	//所有的地方找一遍
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < high; j++)
		{
			if (map1[cas][i][j] == 7)
				count++;
		}
	}
	return count;
}
void gameend() {
	printf("退出游戏成功........");
	exit(0);
}
void start() {
	int i = 0;
	printf("\n\n\n\n\n\n\n\n\t\t\t\t\t推箱子0.3 ver by:搞 ");
	Sleep(2000);
	system("cls");
	char str[] = "654321";
	while (str[i++] != '\0') {
		printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t游戏开始倒计时:%c", str[i]);
		Sleep(520);
		system("cls");
	}
}
void Nextcas() {
	if (cas + 1 < caslength)
		cas++;
	Initialize();
}
void Lastcas() {
	if (cas - 1 >= 0)
		cas--;
	Initialize();
}
void Endgame() {
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < high; j++)
		{
			if (j == 0)
				printf("\t\t\t\t");
			switch (map2[0][i][j])
			{

			case 0:
				Sleep(66);
				printf("  ");
				break;
			case 1:
				Sleep(66);
				printf("▓");
				break;
			}
		}
		printf("\n");
	}
	printf("恭喜你通关了游戏~\n\n\n\n\n\n\n\n\n\n");
}
void to_withdraw() {
	int n = 0;
	Initialize();
	while (gamekey[cas][n] != '\0') {
		drawMap();
		int i, j;
		for (i = 0; i < line; i++)
		{
			for (j = 0; j < high; j++)
			{
				if (map1[cas][i][j] == 5 || map1[cas][i][j] == 8)
				{
					break;
				}
			}
			if (map1[cas][i][j] == 5 || map1[cas][i][j] == 8)
			{
				break;
			}
		}
		char ch = gamekey[cas][n++];
		Sleep(200);
		switch (ch)
		{
		case 'w':
		case 'W':
		case 72:
			if (map1[cas][i - 1][j] == 0 || map1[cas][i - 1][j] == 3)
			{
				map1[cas][i - 1][j] += 5;
				map1[cas][i][j] -= 5;
				step_number++;
			}
			else if (map1[cas][i - 1][j] == 4 || map1[cas][i - 1][j] == 7)
			{
				if (map1[cas][i - 2][j] == 0 || map1[cas][i - 2][j] == 3)
				{
					map1[cas][i - 2][j] += 4;
					map1[cas][i - 1][j] += 1;
					map1[cas][i][j] -= 5;
				}

			}

			break;
		case 's':
		case 'S':
		case 80:
			if (map1[cas][i + 1][j] == 0 || map1[cas][i + 1][j] == 3)
			{
				map1[cas][i + 1][j] += 5;
				map1[cas][i][j] -= 5;
			}
			else if (map1[cas][i + 1][j] == 4 || map1[cas][i + 1][j] == 7)
			{
				if (map1[cas][i + 2][j] == 0 || map1[cas][i + 2][j] == 3)
				{
					map1[cas][i + 2][j] += 4;
					map1[cas][i + 1][j] += 1;
					map1[cas][i][j] -= 5;
				}

			}
			break;

		case 'a':
		case 'A':
		case 75:
			if (map1[cas][i][j - 1] == 0 || map1[cas][i][j - 1] == 3)
			{
				map1[cas][i][j - 1] = map1[cas][i][j - 1] + 5;
				map1[cas][i][j] = map1[cas][i][j] - 5;
				step_number++;
			}
			else if (map1[cas][i][j - 1] == 4 || map1[cas][i][j - 1] == 7)
			{
				if (map1[cas][i][j - 2] == 0 || map1[cas][i][j - 2] == 3)
				{
					map1[cas][i][j - 2] += 4;
					map1[cas][i][j - 1] += 1;
					map1[cas][i][j] -= 5;
				}

			}

			break;
		case 'D':
		case 'd':
		case 77:
			if (map1[cas][i][j + 1] == 0 || map1[cas][i][j + 1] == 3)
			{
				map1[cas][i][j + 1] += 5;
				map1[cas][i][j] -= 5;
			}
			else if (map1[cas][i][j + 1] == 4 || map1[cas][i][j + 1] == 7)
			{
				if (map1[cas][i][j + 2] == 0 || map1[cas][i][j + 2] == 3)
				{
					map1[cas][i][j + 2] += 4;
					map1[cas][i][j + 1] += 1;
					map1[cas][i][j] -= 5;
				}
			}
			break;
		}
		system("cls");
	}
	Initialize();
}
void graph_initialization() {
	initgraph(50 * 10, 50 * 10, SHOWCONSOLE);
	loadimage(&people,L"u=1004062630,309098072&fm=26&gp=0.JPG",50,50,true);
	loadimage(&Box, L"u=3130994940,1823265982&fm=26&gp=0.JPG", 50,50,true);
	loadimage(&Wall, L"u=2924072199,1355949992&fm=26&gp=0.JPG", 50,50,true);
	loadimage(&Road, L"road.JPG", 50,50,true);
	loadimage(&Basket, L"basket.JPG", 50,50,true);
	loadimage(&Baskets, L"u=195467851,24279554&fm=26&gp=0.JPG", 50,50,true);
	loadimage(&peoples, L"u=3326893948,1837007575&fm=26&gp=0.JPG", 50,50,true);

}
void play_music(){

	mciSendString(L"open taiBeautiful.mp3 alias bkmusic", NULL, 0, NULL);	//播放音乐
	mciSendString(L"play bkmusic repeat", NULL, 0, NULL);

}
void exit_music(){
	mciSendString(L"open taiBeautiful.mp3 alias bkmusic", NULL, 0, NULL);
	mciSendString(L"close bkmusic ", NULL, 0, NULL);
}