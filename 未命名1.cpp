#include<bits/stdc++.h>
#define MAXSIZE 10001  					//����ְ���������
typedef struct People{
    long long Worker_id;  	 			//ְ���� 
    char Name[12];			    		//����
	char Sex[12];						//�Ա� 
    int  Age;							//���� 
    char Edu[20];			        	//ѧ��
    float Salary;						//����
    /*
	...
	*/
}peo;
//˳���Ĺ���
typedef struct LNode *PtrToAdjVNode;

struct LNode{
    int last;				        //ָ�����һ��Ԫ���±� 
    peo *array;						//ְ��ָ������ 
};
typedef PtrToAdjVNode List;
 
peo temp;   							        //ְ��ȫ�ֱ���     

//������
int Pos(List L,int Left,int Right);				//˳��������
void Age_Sort(List L,int Left,int Right);

List MakeEmpty();									//˳���ĳ�ʼ��
void Meum();									 
void Insert(List L,People value);					//˳���Ĳ��� 
void Delete(List L); 								//˳����ɾ�� 
void Find(List L);									//˳���Ĳ�ѯ 
void Show(List L);									//չʾ��Ϣ 
void After(List L);									//˳�����޸� 
void login();							        	//������Ϣ 
void input();							        	//����ְ����Ϣ 
void fileWrite(List L);     						//д���ļ�
void fileRead(List L);      						//��ȡ�ļ�
FILE *fp;                   						//�ļ�����


int main(){
	
	Meum();
	return 0;
}
List MakeEmpty(){
	// ˳����ʼ��
	List L;
	L = (List)malloc(sizeof(peo) * MAXSIZE);
	L->last = -1;
	return L;
}
void Meum(){
	printf("\n\n\t\t\tְ����Ϣ����ϵͳ\n");
	printf("\t\t\t1��ְ����Ϣ¼��\n");
	printf("\t\t\t2����ʾ����ְ����Ϣ\n");
	printf("\t\t\t3��ͳ��\n");
	printf("\t\t\t4����ѯ\n");
	printf("\t\t\t5������\n");
	printf("\t\t\t6���޸�\n");
	printf("\t\t\t7��ɾ��\n");
	printf("\t\t\t8���˳�ϵͳ\n");
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
