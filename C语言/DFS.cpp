#include<cstdio>
#define ROW 5
#define COLS 4 
using namespace std;

//struct Point{	
//	int row;
//	int cols;
//	Point* Parents; 
//}
int EndPosx=3,EndPosy=2,min=999999999;
	int Map[ROW][COLS]={
		{1,1,0,1},
	 	{1,1,1,1},
		{1,1,0,1},
		{1,0,1,1},
		{1,1,1,0},	
};		 
bool Case[ROW][COLS]={0};
enum direct{_right,_down,_left,_up};
 
void dfs(int x,int y,int Step);
int main(){
	dfs(0,0,0);
	printf("Min=%d",min);
	return 0;
} 
void dfs(int x,int y,int Step){

	if(x==EndPosx&&y==EndPosy){	
		if(Step<min)
			min=Step;
		return;
	}
	for(int i=0;i<4;i++){		//考虑越界的情况 0 越界 
		switch(i){		
			case _right:
				if(Map[x][y+1]==1&&Case[x][y+1]==false){	//表示能走 
					Case[x][y+1]=true;
					dfs(x,y+1,Step+1);
					Case[x][y+1]=false;			
				}
					break;
			case _down:
				if(Map[x+1][y]==1&&Case[x+1][y]==false){	//表示能走 
					Case[x+1][y]=true;
					dfs(x+1,y,Step+1);
					Case[x+1][y]=false;			
				}
					break;
			case _left:
				if(Map[x][y-1]==1&&Case[x][y-1]==false){	//表示能走 
					Case[x][y-1]=true;
					dfs(x,y-1,Step+1);
					Case[x][y-1]=false;			
				}
					break;
			case _up:
				if(Map[x-1][y]==1&&Case[x-1][y]==false){	//表示能走 
					Case[x-1][y]=true;
					dfs(x-1,y,Step+1);
					Case[x-1][y]=false;			
				}
					break;		 
		}
	}
	return ;
} 
