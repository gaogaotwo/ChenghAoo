#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
/*
	Name: 测试xi模板
	Copyright: 
	Author: 搞搞
	Date: 01/01/20 22:16
	Description: 
*/

typedef struct students{
	
	int data; 
	char name[10];//scanf("%s",&name);
}stu;
typedef struct LNode *PtrToAdjVNode;
struct LNode{
	stu s;
	struct LNode *next;
};
typedef PtrToAdjVNode List;

stu createStuScore();					//创建数据 
List Add_data();					//添加链表节点 
List addToList(List list,List temp);			//头插法？ 
void Show_data(stu temp);				//显示数据 
void Show_Alldata(List list);				//展示所有数据 
void inquire(List L);					//查询数据 
void Modify(List L);					//修改数据 
List  Delete(List L);					//删除数据 
void sort(List L);					//排序 
void menu();						//菜单 
void exit();						//退出 
void filewriting(List L);				//文件存储 
void fileread(List L);					//文件读取

void author(); 
FILE *fp;
 
int main()
{
	List head=NULL,temp;
	int choice;
	author();
	while(1)
	{
		menu();
		scanf("%d",&choice);
		switch(choice)
		{
		case 1://添加学生信息
				temp=Add_data();
				head=addToList(head,temp);
				break;
		
		case 2:Show_Alldata(head);break;

		case 3:inquire(head);break;

		case 4:Modify(head);break;

		case 5:head=Delete(head);getchar();getchar();break;

		case 6:sort(head);break;
			
		case 7:filewriting(head);break;
		
		case 8:fileread(head);break;

		case -1:exit();break;

		}
	}
}
stu createStuScore()
{
	stu temp;

	printf("输入data:\n"); 
	scanf("%d",&temp.data);
	printf("name data_\n");
	scanf("%s",temp.name);	
	return temp;
}


List Add_data()
{
	List Node;
	Node=(List)malloc(sizeof(LNode));
	
	Node->s=createStuScore();
	Node->next=NULL;
	
	return Node;
}

//将一个节点添加到列表中去，返回列表的头指针
List addToList(List list,List temp)
{
	temp->next=list;
	list=temp;
	return list;
}

//显示信息
void Show_data(stu temp)
{
		printf("测试数据%d   %s\n",temp.data,temp.name);
		
}

//显示所有学生信息
void Show_Alldata(List list)
{
	
//	printf("data _______\n");
	while(list!=NULL)
	{
		Show_data(list->s);
		list=list->next;
	}
	getchar();getchar();
}

//查询函数
void inquire(List L)
{
	int i;

	printf("测试_____-data\n编号:\n");
	scanf("%d",&i);
	
	while(L!=NULL)
	{
		if(i==L->s.data)
		{
			printf("测试___________data\n");
			Show_data(L->s);
		}
		L=L->next;
	}
	getchar();getchar();
}

//修改程序函数
void Modify(List L)
{
	int i;
	
	printf("_____________data\n编号:\n");
	scanf("%d",&i);
	while(L!=NULL)
	{
		if(i==L->s.data)
		{
			L->s=createStuScore();
			break;
		}
		L=L->next;
	}
	printf("修改成功");
	getchar();getchar();
}

//删除成绩函数
List  Delete(List L)
{
	int i;
	List temp=L->next,head=L;
	printf("____________data\n编号:\n");
	scanf("%d",&i);
	
	if(i==head->s.data)
	{
		head=head->next;
		printf("删除成功");
		return head;
	}
	else{
		while(temp!=NULL)
		{
			if(i==temp->s.data)
			{
				head->next=temp->next;
				break;
			}
			else
				temp=temp->next;
		}
	}
	printf("删除成功");
	return head;
}

//排序
void sort(List L)//按从大到小排序 
{
	List big,small,head;	//头节点 大小节点 
	
	head=L;
	
	stu temp;
	int a,b;
	
	big=head;
	while(big!=NULL)
	{
		small=big;
		a=small->s.data;		
		while(small!=NULL)
		{
			b=small->s.data;
			if(b<a)					//从大到小，从小到大？ 
			{
				temp=small->s;
				small->s=big->s;
				big->s=temp;
				a=b;
			}
			small=small->next;
		}
		big=big->next;
	}
	printf("成功排序");getchar();getchar();
}
void menu(){

		system("cls");
		printf("\t\t\t\t\t*********----------测试系统模板********\n");
		printf("\t\t\t\t\t1.添加信息\n");
		printf("\t\t\t\t\t2.显示所有信息\n");
		printf("\t\t\t\t\t3.查询信息\n");
		printf("\t\t\t\t\t4.修改信息\n");
		printf("\t\t\t\t\t5.删除信息\n");
		printf("\t\t\t\t\t6.排序(还待测试中)\n");
		printf("\t\t\t\t\t7.信息存储\n");
		printf("\t\t\t\t\t8.信息读取  (ps你读取多少数据 前提你必须要新建多少节点存放它)\n");
		printf("\t\t\t\t\t请输入您的选择:");
}
void exit(){
	printf("--------------------");
	exit(0);
}
void filewriting(List L){
	
	fp = fopen("text.txt", "w");
	while(L)
    {
            	fprintf(fp,"%d %s\n",L->s.data,L->s.name);//将链表里头的数据存储的 text.txt文件里去。 
            	L=L->next;
        
    }
//    getchar();
    fclose(fp);
}

void fileread(List L){

	fp = fopen("text.txt", "r");
	while(L)
	{
		fscanf(fp,"%d %s",&L->s.data,L->s.name);			//将文件里头的数据text.txt 存储到链表里去？ 
		L=L->next;
	}
//	getchar();
    fclose(fp);
}
void author(){
	system("color 8E");
	printf("\n\n\n\n\n\n\n\t\t\t\t测试系统模板 链表实现:\n\t\t\t\t\t功能有 添加数据，查询数据 修改数据 排序数据 存储数据 读取数据  \n\n\t\t\t\t\t\tby 搞");
	Sleep(5000);
	system("cls");
} 
