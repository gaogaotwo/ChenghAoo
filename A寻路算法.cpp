#include<stdio.h>
#include<vector>
#include<stdlib.h>
#include <memory.h> 
#include<windows.h>
using namespace std;
#define ROW 10
#define COLS 10
#define linear_cost 10	//直线代价 
#define slash_cost 14	//斜线代价 
struct Mypoint{
	int Row;
	int Cols;
	int F;	 
	int G;	 // 到周围节点代价 
	int H;	 // 终点到当前节点代价 
	void f(){
		F=G+H;
	}
};

struct TreeNode{
	Mypoint Pos;				//坐标 
	TreeNode* Parents; 			//父亲节点 
};

enum direct{_up,_down,_left,_right,up_l,up_r,down_l,down_r};	//枚举 方向 
void DrawMap(int drawMap[ROW][COLS],TreeNode* LNode);			//绘图 
int GetH(Mypoint endPos,Mypoint Pos);							//获取 H 代价值  
bool NeeAdd(Mypoint Pos,int MAP[ROW][COLS],bool Auxiliary_Maps[ROW][COLS]);	//判断 当前节点是否符合情况 
TreeNode* A_Algorithms(int Map[ROW][COLS],bool Auxiliary_Maps[ROW][COLS],Mypoint BeginPos,Mypoint EndPos);	//A* 
 
int main(){

			Mypoint BeginPos={1,1};				 
			Mypoint EndPos={1,8};
			
		int MAP[ROW][COLS]={
			{1,1,1,1,1,1,1,1,1,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,1,1,1,1,1,1,1,1,1},
		};
				
		bool Auxiliary_Maps[ROW][COLS]={0};			//记录是否走过						
		Auxiliary_Maps[BeginPos.Row][BeginPos.Cols]=true;	
		TreeNode *Start=A_Algorithms(MAP,Auxiliary_Maps,BeginPos,EndPos);
		if(Start)		 	
			DrawMap(MAP,Start);
		
		free(Start);								//释放Start	
	return 0;
}
void DrawMap(int drawMap[ROW][COLS],TreeNode* LNode){
	
	while(LNode){
		
		drawMap[LNode->Pos.Row][LNode->Pos.Cols]=2;
		for(int i=0;i<ROW;i++){
		for(int j=0;j<COLS;j++){		
			if(drawMap[i][j]==1)
				printf("#");
			if((i==LNode->Pos.Row&&j==LNode->Pos.Cols)||drawMap[i][j]==2)
				printf("*");
			if(drawMap[i][j]==0)
				printf(" ");
		}
		printf("\n");	
	}			
		LNode=LNode->Parents;
		Sleep(100);
		system("cls");	
}
	for(int i=0;i<ROW;i++){
		for(int j=0;j<COLS;j++){
			if(drawMap[i][j]==0)
				printf(" ");
			if(drawMap[i][j]==1)
				printf("#");
			if(drawMap[i][j]==2)
				printf("*");
		}
		printf("\n");
	}
	
	getchar();getchar();
}
// 计算H 值到达 终点距离 
int GetH(Mypoint endPos,Mypoint Pos){ 				//采用的是哈夫曼距离直线当前终点到坐标代价值 
													//注意正负数情况 
	int x= endPos.Cols > Pos.Cols ? endPos.Cols - Pos.Cols : Pos.Cols - endPos.Cols;
	int y= endPos.Row > Pos.Row ? endPos.Row - Pos.Row : Pos.Row - endPos.Row;
	return (x+y)*linear_cost;
}
//地图限定条件 
bool NeeAdd(Mypoint Pos,int MAP[ROW][COLS],bool Auxiliary_Maps[ROW][COLS]){
	if(Pos.Row>=ROW|| Pos.Row<0||Pos.Cols>=COLS|| Pos.Cols<0) 	//地图边界 
		return false;
	if(MAP[Pos.Row][Pos.Cols]==1)								//墙 
		return false;
	if(Auxiliary_Maps[Pos.Row][Pos.Cols])						//已走过 
		return false;	
	return true;									 

}
TreeNode* A_Algorithms(int Map[ROW][COLS],bool Auxiliary_Maps[ROW][COLS],Mypoint BeginPos,Mypoint EndPos){
	
		
		TreeNode* Pcurrent= new TreeNode;		//父亲节点 
		memset(Pcurrent ,0, sizeof(TreeNode));		
		Pcurrent->Pos=BeginPos;					//记录开始位置 
		
		vector<TreeNode*>Buff;					//装孩子的容器 
		TreeNode* pChild = NULL;				//孩子节点 
		
		//迭代器 
		vector<TreeNode*>::iterator it;
		vector<TreeNode*>::iterator itMin;
		bool IsFind =false;
		while(true){
				
			for(int i=0;i<8;i++){
				// 上下左右 斜上下左右 节点代价计算 
				pChild=new TreeNode;	
				memset(pChild ,0, sizeof(TreeNode));	
				pChild->Pos=Pcurrent->Pos;
				
				switch(i){
					case _up:
						pChild->Pos.Row--;			//坐标变化 
						pChild->Pos.G+=linear_cost;	
						break;
					case _down:
						pChild->Pos.Row++;
						pChild->Pos.G+=linear_cost;	
						break;
					case _left:
						pChild->Pos.Cols--;
						pChild->Pos.G+=linear_cost;	
						break;
					case _right:
						pChild->Pos.Cols++;
						pChild->Pos.G+=linear_cost;	
						break;
					case up_l:
						pChild->Pos.Row--;
						pChild->Pos.Cols--;
						pChild->Pos.G+=slash_cost;	
						break;
					case up_r:
						pChild->Pos.Row--;
						pChild->Pos.Cols++;
						pChild->Pos.G+=slash_cost;	
						break;
					case down_l:
						pChild->Pos.Row++;
						pChild->Pos.Cols--;
						pChild->Pos.G+=slash_cost;	
						break;
					case down_r:
						pChild->Pos.Row++;
						pChild->Pos.Cols++;
						pChild->Pos.G+=slash_cost;	
						break;		
				}
				//边界情况判断 去除没有 边界 不符合的节点 
				if(pChild->Pos.Row==-1||pChild->Pos.Row==-1||pChild->Pos.Row==10||pChild->Pos.Row==10){
					delete pChild;
					continue;
				}
				
				//获取 H 终点到达 当前节点的代价 
				pChild->Pos.H=GetH(EndPos,pChild->Pos);
				pChild->Pos.f();
				
				// 查询是否符合的节点 并将符合的节点放入容器中 	
				if(NeeAdd(pChild->Pos , Map , Auxiliary_Maps)){			
//					Pcurrent->Childs.push_back(pChild);		
					pChild->Parents=Pcurrent;
					
					Buff.push_back(pChild);		// 放入一个容器 Buff中 
					Auxiliary_Maps[pChild->Pos.Row][pChild->Pos.Cols]=true; //边界该节点位置已走 
				}
				//不符合的  已经走过 或者 说 限制条件 墙 
				else{	
					delete pChild;
				}
						
			}
		 
		// 找出  Buff 容器中代价值最小的一个点 
		itMin=Buff.begin();										//假设第一个节点 就是最小值 
		for(it=Buff.begin();it!=Buff.end();it++)
			itMin=(*itMin)->Pos.F>(*it)->Pos.F ? it : itMin;	//选择最小的
 
			/* 当然你也可以这样写
				if((*itMin)->Pos.F>(*it)->Pos.F)
					itMin=it;		
			*/
			 	
			Pcurrent=*itMin;					// 选择代价值 最小的一个节点 作为当前节点  
			//delete itMin    		 	
			Buff.erase(itMin);
		// 结束条件 当前节点 的坐标值 等于 查询节点 
		if(Pcurrent->Pos.Row==EndPos.Row&&Pcurrent->Pos.Cols==EndPos.Cols)	
		{
			IsFind = true;
			break;
		}
//		if(Buff.empty()) 
//			break;			
	} 	
		if(IsFind)
			return Pcurrent;
		else{
			printf("无路径");
			return Pcurrent; 
		}	
}	


