//#include<stdio.h>
//#include<stdlib.h>
//struct Operation{
//
//	char operation[20];
//	int Status;						//进程状态	 
//	int Time_arrival;					//到达时间 
//	int Time_elapsed;					//运行时间 
//	int Time_Start;						//开始时间
//	int Time_Completion;					//完成时间
//	int Turnaround_time;	 				//周转时间
//	float _timeWeighted_Turnaround; 			//带权周转时间 
//	int Priority;						//优先级 
//};
//typedef struct VNode *PtrToAdjVNode;
//
//struct VNode{
//
//	Operation X;
//	struct VNode *Next;
//};
//typedef PtrToAdjVNode PCB;
//
//PCB CreatProcess(PCB P);
//void Process_Scheduling(PCB P);
//void Process_Short(PCB P);  
//
//int main(){
//	
//	
//	int Pos;
//	
//	PCB P1,P2;
//		
//	P2=CreatProcess(P2); 			//先来先服务法
//	Process_Scheduling(P2);
//	
//	P1=CreatProcess(P1);			//短作业优先法
//	Process_Short(P1);
//
//
//
//	return 0;
//}
//
//PCB CreatProcess(PCB Head){
//
//	int Pos;
//	
//	/*头结点分配内存
//	采用的是头结点不动，通过尾部指针的移动从而 对链表值进行变化 
//	*/
//	Head=(PCB)malloc(sizeof(struct VNode));
//	Head->Next=NULL;
//	PCB P1=NULL;
//	PCB P2=Head; 
//	
//	
//	printf("请依次输入作业名 进程状态 到达时间 运行时间 优先级\n");
//	scanf("%s %d %d %d %d",Head->X.operation,&Head->X.Status,&Head->X.Time_arrival,&Head->X.Time_elapsed,&Head->X.Priority); 
//	printf("是否继续插入 1 / 0\n");
//	scanf("%d",&Pos);
//	if(Pos==0)
//		return Head; 
//
//	while(1){	
//	P1=(PCB)malloc(sizeof(struct VNode));
//	/*对于p1 进行赋值操作*/
//	printf("请依次输入作业名 进程状态 到达时间 运行时间 优先级\n");
//	scanf("%s %d %d %d %d",P1->X.operation,&P1->X.Status,&P1->X.Time_arrival,&P1->X.Time_elapsed,&P1->X.Priority); 
//		
//	P2->Next=P1;		//更改尾指针 
//	P2=P1; 			
//
//	printf("是否继续插入 1 / 0\n");
//	scanf("%d",&Pos);
//	if(Pos==0)
//		break;
//}
//	/*插入完毕后 尾指针指向*/ 
//	P2->Next=NULL;
//	 
//	return Head;
//}
//void Process_Scheduling(PCB P){
//
//	PCB M=P;
//	int _Turnaround_time=0,sum=0;
//	float averageLy=0;
//	/*默认 第一个作业开始时间为 0
//		   并且周转时间,与完成时间等于运行时间
//		   并且带权周转时间为 1	
//	*/
//	M->X.Time_Start=0;		
//	M->X.Turnaround_time=M->X.Time_elapsed;
//	M->X.Time_Completion=M->X.Time_elapsed;
//	M->X._timeWeighted_Turnaround=1;
//	
//	averageLy+=M->X.Turnaround_time;
//	sum++;
//	
//	_Turnaround_time=M->X.Time_Completion;
//	
//	M=M->Next;
//	 
//	while(M){
//		M->X.Time_Start=_Turnaround_time;
//		M->X.Time_Completion=M->X.Time_Start+M->X.Time_elapsed;				//完成时间 等于 开始时间 + 运行时间 
//		M->X.Turnaround_time=M->X.Time_Completion-M->X.Time_arrival; 		//周转时间 等于 完成时间 - 到达时间
//		M->X._timeWeighted_Turnaround=M->X.Turnaround_time/(float)(M->X.Time_elapsed);	//带权周转时间 等于 周转时间 / 运行时间 
//		_Turnaround_time=M->X.Time_Completion;
//		/*平均周转时间*/		
//		averageLy+=M->X.Turnaround_time;
//		sum++;
//		
//		M=M->Next;
//	}
//	
//	printf("-----------------------------先来先服务法FCFS-----------------------\n");
//	printf("作业  到达时间  运行时间  开始时间  完成时间  周转时间  带权周转时间  \n");
//	while(P){	
//	printf("%s   %5d  	%5d   %5d  	   %5d    %5d  	%5.2f\n",P->X.operation,P->X.Time_arrival,P->X.Time_elapsed
//		,P->X.Time_Start,P->X.Time_Completion
//		,P->X.Turnaround_time,P->X._timeWeighted_Turnaround
//	);
//		P=P->Next;	
//	}
//	printf("平均周转时间为:%.2f\n",averageLy/(float)(sum)); 
//	printf("--------------------------------------------------------------------\n"); 
////	while(P){
////		printf("%s\n",P->X.operation);
////		P=P->Next;
////	} 	 
//}
//void Process_Short(PCB P){
//
//	PCB M1=P;
//	/*默认进程都是同时到达的 */
//	while(M1){
//		M1->X.Time_arrival=0; 
//		M1=M1->Next;
//	}
//	
//	PCB Small,Big=P;
//	Operation Temp; 
//	int Num1,Num2;
//	
//	/*采用的是选择排序的手法,先根据作业完成时间进行排序*/
//	while(Big){		
//		Num1=Big->X.Time_elapsed;
//		Small=Big;
//		while(Small){
//			Num2=Small->X.Time_elapsed;
//			if(Num1>Num2){
//				Temp=Big->X;			// 注意是用学生临时节点作为数据域	
//				Big->X=Small->X;
//				Small->X=Temp;
//			}
//			Small=Small->Next;
//		}
//		Big=Big->Next;
//	}
//	
//	PCB M=P;
//	int _Turnaround_time=0,sum=0;
//	float averageLy=0;
//	/*默认 第一个作业开始时间为 0
//		   并且周转时间,与完成时间等于运行时间
//		   并且带权周转时间为 1	
//	*/
//	M->X.Time_Start=0;		
//	M->X.Turnaround_time=M->X.Time_elapsed;
//	M->X.Time_Completion=M->X.Time_elapsed;
//	M->X._timeWeighted_Turnaround=1;
//	
//	averageLy+=M->X.Turnaround_time;
//	sum++;
//	
//	_Turnaround_time=M->X.Time_Completion;
//	
//	M=M->Next;
//	 
//	while(M){
//		M->X.Time_Start=_Turnaround_time;
//		M->X.Time_Completion=M->X.Time_Start+M->X.Time_elapsed;				//完成时间 等于 开始时间 + 运行时间 
//		M->X.Turnaround_time=M->X.Time_Completion-M->X.Time_arrival; 		//周转时间 等于 完成时间 - 到达时间
//		M->X._timeWeighted_Turnaround=M->X.Turnaround_time/(float)(M->X.Time_elapsed);	//带权周转时间 等于 周转时间 / 运行时间 
//		_Turnaround_time=M->X.Time_Completion;
//		/*平均周转时间*/		
//		averageLy+=M->X.Turnaround_time;
//		sum++;
//		
//		M=M->Next;
//	}
//	
//	printf("------------------------------短作业优先法SJF-----------------------------\n");
//	printf("作业  到达时间  运行时间  开始时间  完成时间  周转时间  带权周转时间  \n");
//	while(P){	
//	printf("%s   %5d  	%5d   %5d  	   %5d    %5d  	%5.2f\n",P->X.operation,P->X.Time_arrival,P->X.Time_elapsed
//		,P->X.Time_Start,P->X.Time_Completion
//		,P->X.Turnaround_time,P->X._timeWeighted_Turnaround
//	);
//		P=P->Next;	
//	}
//	printf("平均周转时间为:%.2f\n",averageLy/(float)(sum));
//	printf("--------------------------------------------------------------------\n");
//
//} 
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<unistd.h>
//#include<pthread.h>
//#include<semaphore.h>
//
//#define P sem_wait
//#define V sem_post
//#define apple_full &fullA
//#define orange_full &fullB
//#define empty &emptyA

//sem_t fullA;
//sem_t fullB;
//sem_t emptyA;
//
//void * Father(void *p); 
//void * Mother(void *p);
//void *Daughter(void *p);
//void *Son(void *p);
//
//int sum=999;
//int Pos=0; 
//int main(){
//
//	sem_init(apple_full,0,0);
//	sem_init(orange_full,0,0);
//	sem_init(empty,0,1);
//	
//	pthread_t tcb0;		 
//	pthread_t tcb1;
//	pthread_t tcb2;
//	pthread_t tcb3;
//	
//	/*创建进程 父亲 母亲 女儿 儿子*/ 
//	pthread_create(&tcb0,NULL,Father,NULL);
//	pthread_create(&tcb1,NULL,Mother,NULL);
//	pthread_create(&tcb2,NULL,Daughter,NULL);
//	pthread_create(&tcb3,NULL,Son,NULL);
//	
//	
//	pthread_exit(0);
//	return 0;
//} 
//void * Father(void *p){
//
//	while(Pos<=sum){
//		P(empty);					//表示父亲苹果放入缓冲区		
//		printf("父亲向盘子放苹果\n%d 次\n",Pos);
//		V(apple_full);				//放入苹果
//		Pos++; 
//	}
//}
//void * Mother(void *p){
//
//	while(Pos<=sum){
//		P(empty);					//表示母亲水果放入缓冲区 
//		printf("母亲向盘子放橘子\n%d 次\n",Pos);
//		V(orange_full);
//		Pos++;
//	}
//}
//
//void *Daughter(void *p){
//
//	while(Pos<=sum){	
//		P(apple_full);				//表示 查看 苹果是否在 盘子中  
//		printf("女儿向盘子取苹果\n%d 次\n",Pos);
//		V(empty);					//女儿 取出苹果 
//		Pos++;
//	}
//
//} 
//void *Son(void *p){
//
//	while(Pos<=sum){
//	
//		P(orange_full);				//表示 查看 橘子是否在 盘子中
//		printf("儿子向盘子取橘子\n%d 次\n",Pos);
//		V(empty);					//儿子 取出橘子
//		Pos++; 
//	}
//} 
 
#include <iostream>
using namespace std; 
//全局变量定义
int Available[100]; 	  //可利用资源数目 
int Max[50][100];   	  //第M个进程 最大资源需求  
int Allocation[50][100];  //第M个进程 分配的资源数 
int Need[50][100];        //第 M个进程还需要N类资源的资源量
int Request[50][100];     //第 M个进程发出请求N类 资源的资源量
int Finish[50];
int p[50];				  //记录安全序列 
int m,n;   				  //M个进程,N类资源
//安全性算法
int SecuritY()                      
{
    int i,j,l=0;
    int Work[100]; //可利用资源数组
    
    for (i=0;i<n;i++)
        Work[i]=Available[i];
        
    for (i=0;i<m;i++)
        Finish[i]=0;
     
	/*通过 i 对应的M个遍历进程 看是否进程处于安全状态*/    
    for (i=0;i<m;i++)	 
    {
        if (Finish[i]==1)	
        continue;
        else
        {
            for (j=0;j<n;j++)
            {
                if (Need[i][j]>Work[j])
                    break;
            }
            if (j==n)
            {
                Finish[i]=1;
                for(int k=0;k<n;k++)
                    Work[k]+=Allocation[i][k];
                p[l++]=i;
                i=-1;
            }
            else continue;
        }
    }
    if (l==m)
        {
            cout<<"系统是安全的"<<'\n';
            cout<<"系统安全序列是:\n";
            for (i=0;i<l;i++)
            {
                cout<<p[i];
                if (i!=l-1)
                    cout<<"-->";
            }
            cout<<'\n';
            return 1;
        }
    else{
		cout<<"系统是不安全的"<<'\n';
		cout<<'\n';
		return 0; 
	}
}
//银行家算法
int main()
{
    int i,j,mi;
    cout<<"输入进程的数目:\n";
    cin>>m;
    cout<<"输入资源的种类:\n";
    cin>>n;
    cout<<"输入每个进程最多所需的各类资源数,按照"<<m<<"x"<<n<<"矩阵输入\n";
    for (i=0;i<m;i++)
        for(j= 0;j<n;j++)
            cin>>Max[i][j];
    cout<<"输入每个进程已经分配的各类资源数,按照"<<m<<"x"<<n<<"矩阵输入\n";
    for (i=0;i<m;i++){ 
        for(j=0;j<n;j++){       
            cin>>Allocation[i][j];
            Need[i][j]=Max[i][j]-Allocation[i][j];	//第 i 个资源需要的进程数 
            if (Need[i][j]<0){  					//判断是否输入正确 
                cout<<"你输入的第"<<i+1<<"个进程所拥有的第"<<j+1<<"个资源错误，请重新输入:\n";
                j--;
                continue;
            }
        }
    }
    cout<<"请输入各个资源现有的数目:\n";
    for (i=0;i<n;i++)
    	cin>>Available[i];
    SecuritY();
    
    while (1)
    {
        cout<<"输入要申请的资源的进程号：（第一个进程号为0，第二个进程号为1，依此类推）\n";
        cin>>mi;
        cout<<"输入进程所请求的各个资源的数量\n";
        for (i=0;i<n;i++)
        cin>>Request[mi][i];		
        for (i=0;i<n;i++)
        {

            if (Request[mi][i]>Need[mi][i])
            {
                cout<<"所请求资源数超过进程的需求量！\n";
                return 0;
            }
            if (Request[mi][i]>Available[i])
            {
                cout<<"所请求资源数超过系统所有的资源数！\n";
                return 0;
            }
        }
        for (i=0;i<n;i++)
        {
            Available[i]-=Request[mi][i];
            Allocation[mi][i]+=Request[mi][i];
            Need[mi][i]-=Request[mi][i];
        }
        if (SecuritY())
            cout<<"同意分配请求\n";
        else
        {
            cout<<"你的请求被拒绝…\n";
            for (i=0;i<n;i++)
            {
                Available[i]+=Request[mi][i];
                Allocation[mi][i]-=Request[mi][i];
                Need[mi][i]+=Request[mi][i];
            }
        }
        for (i=0;i<m;i++) 
            Finish[i]=0;
        char Flag;       //标志位
        cout<<"是否再次请求分配？是请按Y/y，否请按N/n";
        while (1)
        {
            cin>>Flag;
            if (Flag=='Y'||Flag=='y'||Flag=='N'||Flag=='n')
            break;
            else
            {
                cout<<"请按要求重新输入:\n";
                continue;
            }
        }
        if (Flag=='Y'||Flag=='y')
        continue;
        else break;
    }
}

