#include<stdio.h>
#include<stdlib.h>
#define MaxProc 9999
#define MaxWindow 100
typedef struct People ElementType;
struct People{
	int T;//顾客到达时间 
	int P;//顾客事务处理时间 
};
typedef int Position;

struct QNode{
	ElementType *Data;
	Position Front,Rear;
	int Maxsize;
};
typedef struct QNode *Queue;

Queue CreateQueue(int MaxSize);
bool IsFull(Queue Q);
bool IsEmpty(Queue Q);
bool AddQ(Queue Q,ElementType X);
ElementType DeleteQ(Queue Q);
void QueueingAtBank(Queue Q,int N);
void FindNextWindow(int W[],int K,int *waitTime);

int main(){
	int N;
	Queue Q;
	int i;
	ElementType X;
	scanf("%d", &N);
	Q=CreateQueue(N);
	
	for(i=0;i<N;i++){
		scanf("%d%d", &X.T, &X.P);
		AddQ(Q,X);
	}
	QueueingAtBank(Q,N);		
	return 0;
}
Queue CreateQueue(int MaxSize){
	
	Queue Q=(Queue)malloc(sizeof(struct QNode));
	Q->Data=(ElementType*)malloc(MaxSize*sizeof(ElementType));
	Q->Front=Q->Rear=-1;
	Q->Maxsize=MaxSize;
	return Q;
}
bool IsEmpty(Queue Q){
	
	return(Q->Front==Q->Rear);
}
bool IsFull(Queue Q){
	
	return((Q->Rear+1)%Q->Maxsize==Q->Front);
}
bool AddQ(Queue Q,ElementType X){
	
	if(IsFull(Q)){
		printf("队列满");
		return false;
	}
	else{
		Q->Rear=(Q->Rear+1)%Q->Maxsize;
		Q->Data[Q->Rear]=X; 
		return true;
	}	
}
ElementType DeleteQ(Queue Q){

	Q->Front=(Q->Front+1)%Q->Maxsize;
	return Q->Data[Q->Front]; 
//	}
}
void QueueingAtBank(Queue Q,int N){
	struct People Next;
	int K;					//窗口数 
	int TotalTime=0;		//总等待时间 
	int CurrentTime=0;		//当前时间 
	int Window[MaxWindow];	//营业窗口需要处理事务的时间长度 
	int WaitTime=0;			//相邻两次窗口空闲之间所等待的时间 
	int WinAvail;			//空闲窗口位置
	
	int temp[MaxWindow];
	//
	int MaxTime=0;	 		//最长等待时间 
	int FinishTime=0;		//最后完成时间 

	int i,j;
	
	scanf("%d",&K);//窗口数
	
	
	//	 T;//顾客到达时间 
	//	 P;//顾客事务处理时间
	// 1，	
	//当人数小于窗口数的时候 
	if(N<K){
	for(i=0;i<N;i++){
		if(FinishTime<Q->Data[i].P+Q->Data[i].T)
		FinishTime=Q->Data[i].P+Q->Data[i].T;  			//最后完成时间用户到达时间+顾客处理时间 
	}
		printf("平均等待时间 = %.1f minute(s)\n最长等待时间%d\n最后完成时间%d\n",0,0,FinishTime);
	for(i=0;i<N;i++)
	 	printf(" 1 ");
	 	printf(" 0 ");
	return;
}
						//当人数大于于窗口数的时候 
	for(i=0;i<K;i++){
		Window[i]=0;	//窗口初始化为0 
		temp[i]=0;
	}
//	MaxTime=0;
	
//	 T;//顾客到达时间 
//	 P;//顾客事务处理时间 
	//2，		
	while(!IsEmpty(Q)){
		
		FindNextWindow(Window,K,&WaitTime);		//寻找最佳时间窗口。 
		 
		CurrentTime+=WaitTime;					//更新当前时间； 
								
		Next=DeleteQ(Q);	
		if(CurrentTime>=Next.T)					//1，如果顾客到达 了 
			TotalTime+=(CurrentTime-Next.T);	//总等待时间 = 当前时间-用户到达时间  = 用户等待时间 
			
		if(MaxTime<CurrentTime-Next.T)			//寻找出最长的等待时间 
				MaxTime=CurrentTime-Next.T;
				 
			
		/*else*/   								//2，顾客还没有到达   刷新每个窗口，								 
		if(CurrentTime<Next.T){					 
			WaitTime=Next.T-CurrentTime;		//   刷新每个窗口时间=   顾客到达时间-当前时间；
			//刷新每个窗口等待时间 
			for(j=0;j<K;j++){
				Window[j]-=WaitTime;			//更新窗口   //可能有几种情况  一个窗口为0 两个窗口为0 三个窗口为0 
				if(Window[j]<0)
				Window[j]=0; 			
			}
			
			CurrentTime=Next.T;			   		//3 把当前时间调整成用户到达时间即可 
		}
		
		for(i=0;i<K;i++)				//记录窗口次数，并且记录用户处理时间 ，此时我们选择的是第一个为0窗口 
			if(Window[i]==0)
				break;
			temp[i]++; 
			Window[i]=Next.P;			//刚刚发现最佳窗口，等于用户事务处理时间；	
		
		if(FinishTime<CurrentTime+Next.P)	//最后完成时间	当前时间+顾客办理时间最长 
			FinishTime=CurrentTime+Next.P;
			
	}	
	printf("平均等待时间 = %.1f minute(s)\n最长等待时间 = %d minute(s)\n最后完成时间 = %d minute(s) \n",(double)TotalTime/(double)N,MaxTime,FinishTime);
	for(i=0;i<K;i++)
		printf("%d\t",temp[i]);
}
void FindNextWindow(int W[],int K,int *waitTime){
	int WinAvail;
	int MinW=MaxProc+1;
	int i;
	for(i=0;i<K;i++)//扫描每个窗口，寻找出窗口 最短时间 
	if(W[i]<MinW){
		MinW=W[i];
//		WinAvail=i;
	}
	*waitTime=MinW;//查找出最优窗口 
	
	for(i=0;i<K;i++)//更新每个窗口时间 
	W[i]-=MinW;
		
//	return WinAvail;
}
/*
6
0 20
0 15
0 30
0 2
1 60
3 10
3

5
0 3
0 4
1 2
4 5
5 5
3

9
0 20
1 15
1 60
2 10
10 5
10 3
30 18
31 25
31 2
3

*/
