//#include <bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 52
//using namespace std;
/*【问题描述】布线问题就是在m×n (0<m,n<=50)的方格阵列中，
指定一个方格的中点a，另一个方格的中点b，问题要求找出a到b的最短布线方案。
布线时只能沿直线或直角，不能走斜线。为了避免线路相交，已布过线的方格做了封锁标记，其他线路不允许穿过被封锁的方格。
【输入描述】第一行，两个数m、n。随后若干行为封锁标记点，以00结束。最后两行输入起点和终点坐标。
【输出描述】最短路径长度和最佳路径坐标。【输入样例】
输入方阵大小M，N:5 6
输入障碍物坐标x，y:(输入00结束)
1 6
2 3
3 4
3 5
5 1
0 0
输入起点坐标:2 1
输入终点坐标:4 6【输出样例】
最短路径的长度为:7最佳路径坐标为:

测试样例 
5 6
1 6
2 3
3 4
3 5
5 1
0 0
2 1
4 6
*/
struct st{
	int x;
	int y;
}min_[N],Tmp[N];

int Next[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};	// 标记 上下左右选择 
int Flag[N][N];  	// 标记路径是否已走 
int Map[N][N];	 	// 地图 
int Step_min = N;	 //步数，默认初始最大值 
int Step_Map[N][N];  //最短路径地图 
int m,n;
int sx,sy,ex,ey;	//起点坐标与终点坐标 
int k = 0;			//当前栈顶栈顶指针 

void dfs(int x,int y,int step); 
int main()
{
	int zx,zy;
	scanf("%d %d",&n,&m);
	// 初始化操作 
	memset(Map,0,sizeof(Map));
	memset(Flag,0,sizeof(Flag));
	
	while(true){
		scanf("%d %d",&zx,&zy);
		if(zx == 0 && zy == 0)  break;
		Map[zx][zy] = 2; 	// 2 表示障碍物 
	}
	
	printf("输入起点坐标: ");
	scanf("%d %d",&sx,&sy);
	printf("输入终点坐标: ");
	scanf("%d %d",&ex,&ey);
	
	dfs(sx,sy,0);
	printf("最短路径长度为:%d\n",Step_min);
	printf("最佳路径坐标为:\n"); 
	for(int i = 0; i < Step_min; i++){
		printf("%d %d\n",min_[i].x,min_[i].y);
	}
	return 0; 
}
void dfs(int x,int y,int step){
	if(x == ex && y == ey){		//若到达终点，比较步数长度，更新坐标 
		if(step < Step_min){	// 比较步长 
			Step_min = step;
			memset(min_,0,sizeof(min_));
			for(int i = 0; i < Step_min; i++){
				min_[i] = Tmp[i];
			} 
		}
		return;	
	}
	if(Map[x][y] == 2)  return;	// 遇到障碍物的情况直接返回即可 
	
	int nx,ny;
	for(int i = 0; i < 4; i++){
		nx = x + Next[i][0];
		ny = y + Next[i][1];
		if(nx > 0 && ny > 0 && nx <= n && ny <= m){
			if(Map[nx][ny] == 0 && Flag[nx][ny] == 0){
				Tmp[k].x = nx;
				Tmp[k].y = ny;
				Flag[nx][ny] = 1;
				k++;
				dfs(nx,ny,step + 1);
				//当前递归层完后，注意回溯！ 
				Flag[nx][ny] = 0;
				k--;				
			}
		}
	}	
}

