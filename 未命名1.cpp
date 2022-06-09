#include<bits/stdc++.h>
#define MAXSIZE 10001  					//控制职工最大人数
typedef struct People{
    long long Worker_id;  	 			//职工号 
    char Name[12];			    		//姓名
	char Sex[12];						//性别 
    int  Age;							//年龄 
    char Edu[20];			        	//学历
    float Salary;						//工作
    /*
	...
	*/
}peo;
//顺序表的构建
typedef struct LNode *PtrToAdjVNode;

struct LNode{
    int last;				        //指向最后一个元素下标 
    peo *array;						//职工指针数组 
};
typedef PtrToAdjVNode List;
 
peo temp;   							        //职工全局变量     

//排序功能
int Pos(List L,int Left,int Right);				//顺序表的排序
void Age_Sort(List L,int Left,int Right);

List MakeEmpty();									//顺序表的初始化
void Meum();									 
void Insert(List L,People value);					//顺序表的插入 
void Delete(List L); 								//顺序表的删除 
void Find(List L);									//顺序表的查询 
void Show(List L);									//展示信息 
void After(List L);									//顺序表的修改 
void login();							        	//界面信息 
void input();							        	//输入职工信息 
void fileWrite(List L);     						//写入文件
void fileRead(List L);      						//读取文件
FILE *fp;                   						//文件变量


int main(){
	
	Meum();
	return 0;
}
List MakeEmpty(){
	// 顺序表初始化
	List L;
	L = (List)malloc(sizeof(peo) * MAXSIZE);
	L->last = -1;
	return L;
}
void Meum(){
	printf("\n\n\t\t\t职工信息管理系统\n");
	printf("\t\t\t1、职工信息录入\n");
	printf("\t\t\t2、显示所有职工信息\n");
	printf("\t\t\t3、统计\n");
	printf("\t\t\t4、查询\n");
	printf("\t\t\t5、排序\n");
	printf("\t\t\t6、修改\n");
	printf("\t\t\t7、删除\n");
	printf("\t\t\t8、退出系统\n");
	getchar();getchar();
}
void Insert(List L,People value){
	
	
}
void Delete(List L){
	
	
}
void Find(List L){
	
	
}
void Show(List L){
	
	
}
void After(List L){
	
	
}
void login(){

	
}

void input(){
	
	
}

void fileWrite(List L){
	
	
}

void fileRead(List L){
	
	
}
int Pos(List L,int Left,int Right){
	
	int tmp = L->array[Left].Age;
	while(Left < Right){
			while(Left < Right && L->array[Right].Age >= tmp){
				Right--;
			}
			L->array[Left] = L->array[Right];
			
			while(Left < Right && L->array[Left].Age <= tmp){
				Left++;
			}
			L->array[Right] = L->array[Left];
	}	
	L->array[Left].Age = tmp;
	return Left; 
}
void Age_Sort(List L,int Left,int Right){
	
	if(Left < Right){
		int pos = Pos(L,Left,Right);
		Age_Sort(L,Left,pos - 1);
		Age_Sort(L,pos + 1,Right);
	}
	
}
