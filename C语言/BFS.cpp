#include<cstdio>
#include<queue>
using namespace std;
#define ROW 5
#define COLS 4
struct Point{

	int x;
	int y;
	int length;
};
int EndX=3,EndY=2 ;
enum direct{_right,_down,_left,_up};
void Bfs(int MAP[ROW][COLS],bool Case[ROW][COLS]);
bool neeAdd(Point L,int MAP[ROW][COLS],bool Case[ROW][COLS]);
int main(){

	bool Case[ROW][COLS]={0};
	int Map[ROW][COLS]={
			{1,1,0,1},
		 	{1,1,1,1},
			{1,1,0,1},
			{1,0,1,1},
			{1,1,1,0},	
	};
	Bfs(Map,Case);
	
	return 0;
}
void Bfs(int MAP[ROW][COLS],bool Case[ROW][COLS]){

	queue<Point>p;
	Point Begin;

	Begin.length=0;
	Begin.x=0;
	Begin.y=0;
		
	Point Now,Next;
	p.push(Begin);
	Case[Begin.x][Begin.y]=true; 
	while(!p.empty()){
	
		Now=p.front();
		if(Now.x==EndX&&Now.y==EndY){		//终点 
			printf("找到了终点 ");
			printf("步长 %d",Now.length); 
			return;	
		}	
		for(int i=0;i<4;i++){
			switch(i){
			
				case _right:					
					Next.x=Now.x;
					Next.y=Now.y+1;
					Next.length=Now.length+1;
					break;
				case _down:
					Next.x=Now.x+1;
					Next.y=Now.y;
					Next.length=Now.length+1;
					break;
				case _left:
					Next.x=Now.x;
					Next.y=Now.y-1;
					Next.length=Now.length+1;
					break;
				case _up:
					Next.x=Now.x-1;
					Next.y=Now.y;
					Next.length=Now.length+1;
					break;	
			}
			if(neeAdd(Next,MAP,Case)){
				p.push(Next);
				printf("(%d:%d)",Next.x,Next.y); 
				Case[Next.x][Next.y]=true;		
			}		
		}
		p.pop();
	}
		return;
} 
bool neeAdd(Point L,int MAP[ROW][COLS],bool Case[ROW][COLS]){

	if(Case[L.x][L.y])	//走过 
		return false;
	if(MAP[L.x][L.y]==0)		//墙 
		return false;
	if(L.x<0||L.x>=ROW||L.y<0||L.y>=ROW)
		return false;	
	return true;
}
