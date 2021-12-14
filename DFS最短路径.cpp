//#include <bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 52
//using namespace std;
/*�������������������������m��n (0<m,n<=50)�ķ��������У�
ָ��һ��������е�a����һ��������е�b������Ҫ���ҳ�a��b����̲��߷�����
����ʱֻ����ֱ�߻�ֱ�ǣ�������б�ߡ�Ϊ�˱�����·�ཻ���Ѳ����ߵķ������˷�����ǣ�������·���������������ķ���
��������������һ�У�������m��n�����������Ϊ������ǵ㣬��00����������������������յ����ꡣ
��������������·�����Ⱥ����·�����ꡣ������������
���뷽���СM��N:5 6
�����ϰ�������x��y:(����00����)
1 6
2 3
3 4
3 5
5 1
0 0
�����������:2 1
�����յ�����:4 6�����������
���·���ĳ���Ϊ:7���·������Ϊ:

�������� 
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

int Next[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};	// ��� ��������ѡ�� 
int Flag[N][N];  	// ���·���Ƿ����� 
int Map[N][N];	 	// ��ͼ 
int Step_min = N;	 //������Ĭ�ϳ�ʼ���ֵ 
int Step_Map[N][N];  //���·����ͼ 
int m,n;
int sx,sy,ex,ey;	//����������յ����� 
int k = 0;			//��ǰջ��ջ��ָ�� 

void dfs(int x,int y,int step); 
int main()
{
	int zx,zy;
	scanf("%d %d",&n,&m);
	// ��ʼ������ 
	memset(Map,0,sizeof(Map));
	memset(Flag,0,sizeof(Flag));
	
	while(true){
		scanf("%d %d",&zx,&zy);
		if(zx == 0 && zy == 0)  break;
		Map[zx][zy] = 2; 	// 2 ��ʾ�ϰ��� 
	}
	
	printf("�����������: ");
	scanf("%d %d",&sx,&sy);
	printf("�����յ�����: ");
	scanf("%d %d",&ex,&ey);
	
	dfs(sx,sy,0);
	printf("���·������Ϊ:%d\n",Step_min);
	printf("���·������Ϊ:\n"); 
	for(int i = 0; i < Step_min; i++){
		printf("%d %d\n",min_[i].x,min_[i].y);
	}
	return 0; 
}
void dfs(int x,int y,int step){
	if(x == ex && y == ey){		//�������յ㣬�Ƚϲ������ȣ��������� 
		if(step < Step_min){	// �Ƚϲ��� 
			Step_min = step;
			memset(min_,0,sizeof(min_));
			for(int i = 0; i < Step_min; i++){
				min_[i] = Tmp[i];
			} 
		}
		return;	
	}
	if(Map[x][y] == 2)  return;	// �����ϰ�������ֱ�ӷ��ؼ��� 
	
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
				//��ǰ�ݹ�����ע����ݣ� 
				Flag[nx][ny] = 0;
				k--;				
			}
		}
	}	
}

