#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<windows.h>
typedef struct student{
	int stuID;
	char stuName[10];
	int grade; 
}STUSCORE;
typedef struct StuScoreNode *Node;

struct StuScoreNode{
	STUSCORE stu;
	struct StuScoreNode *NEXT;
};
typedef Node List;

//创建学生信息的结构体
int stu1=0;
void start(){
	
	
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t\t\t学生课堂题目考核管理系统\n");
	printf("                               			\t	by  ");
	Sleep(2000);
	system("cls");
}
STUSCORE createStuScore()
{
	STUSCORE stu;
	
	stu.stuID=++stu1;
	
	printf("请输入学生的姓名:\n");
	scanf("%9s",stu.stuName);
	
	printf("请输入学生的成绩:\n");
	scanf("%d",&stu.grade);
	
	return stu;

}
//创建一个学生信息节点
List addStuScoreNode()
{
	List assn;
	assn=(List)malloc(sizeof(struct StuScoreNode));
	assn->stu=createStuScore();
	assn->NEXT=NULL;
	return assn;
}

//将一个节点添加到列表中去，返回列表的头指针
List addToList(List list,List stunode)
{
	stunode->NEXT=list;
	list=stunode;
	return list;
}

//显示信息
void showOneInfo2(STUSCORE ss)
{
		printf("%8d%8s%8d\n",ss.stuID,ss.stuName,ss.grade);
}

//显示所有学生信息
void showAllInfo(List list)
{
	List  p;
	p=list;
	printf("%8s%8s%8s\n","序号","姓名","成绩");

	while(p!=NULL)
	{
		showOneInfo2((*p).stu);
		p=p->NEXT;
	}
	
}

//查询成绩函数
void find_stu(List head)
{
	int i;
	List cha;
	cha=head;
	printf("请输入要查询成绩学生的序号\n");
	scanf("%d",&i);
	while(cha!=NULL)
	{
		if(i==cha->stu.stuID)
		{
			printf("%8s%8s%8s\n","序号","姓名","成绩");
			showOneInfo2(cha->stu);
		}
		cha=cha->NEXT;
	}
	getchar();
}
void extract_number(List L){
	int x,garde1;
	
	x=rand() %stu1+1;
	
	printf("请输入%d同学获得的分数\n",x);
    while(L!=NULL){
    	
        if(x==L->stu.stuID){
            scanf("%d",&garde1);
            L->stu.grade=L->stu.grade+garde1;
            break;
            }
        L=L->NEXT;
       }
}
void extract_number1(List L){
	
	char a[100];
    int garde1;
    printf("请输入抽取同学姓名\n");
    scanf("%s",a);
    while(L!=NULL){
        if(strcmp(a,L->stu.stuName)==0){
            printf("请输入%s同学获得的分数\n",a);
            scanf("%d",&garde1);
            L->stu.grade=L->stu.grade+garde1;
            break;
            }
         L=L->NEXT;
      }
}
int main()
{
	system("color 8E");
	start();
	List list=NULL,node;//list是列表的头指针，node为单节点的指针
	int choice;//choice是要选择的服务数字
	while(1)//让程序一直循环
	{
		system("cls");
		printf("\n\n\n\n\n");
		printf("\t\t\t\t-----------------------------------\n");
		printf("\t\t\t\t学生课堂题目考核管理系统\n");
        printf("\t\t\t\t1：添加信息  \n");
		printf("\t\t\t\t2：随机性的抽号  \n");
		printf("\t\t\t\t3：指明道姓地提问\n");
		printf("\t\t\t\t4：查询学生成绩,按序号查询\n");
		printf("\t\t\t\t5：查询全体学生成绩\n");
		printf("\t\t\t\t6：退出系统\n");
		printf("\t\t\t\t-----------------------------------\n");
		printf("输入选项代码:");
		scanf("%d",&choice);

		switch(choice)
		{
		case 1://添加学生信息
				node=addStuScoreNode();
				list=addToList(list,node);
				getchar();
			break;
		case 2:extract_number(list);getchar();break;
		
		case 3:extract_number1(list);getchar();break;
				
		case 4:find_stu(list);getchar();break;

		case 5:showAllInfo(list);getchar();getchar();break;
		

		case 6:
		printf("谢谢你的使用~~"); 
		exit(0);
		break; 

		}
	}
}
