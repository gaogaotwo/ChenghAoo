#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct students{
	char name[10];            //姓名
    int stu_id;               //学号
    char stu_class[15];       //班级
    float grade[3];           //三门课成绩   
}stu;
typedef struct LNode *PtrToAdjVNode;
struct LNode{
	stu s;                    //数据域
	struct LNode *next;       //指针域       
};
typedef PtrToAdjVNode List;

stu createStuScore();					//添加学生数据 
List Add_data();					    //添加链表节点 
List addToList(List L,List temp);       //头插法插入节点 
void Show_data(stu temp);				//显示数据 
void Show_Alldata(List L);			    //展示所有数据 
void Find(List L);					    //查询数据 
void After(List L);				    	//修改数据 
List Delete(List L);					//删除数据 
void sort(List L);					    //排序  
void menu();						    //主菜单 
void exit();						    //退出系统 
void filewriting(List L);				//文件存储 
List fileread(List L);					//文件读取

FILE *fp;                               //文件
stu people;								//学生临时节点 
 
int main()
{
	List head=NULL,temp;               //头节点初始化
	int choice;

	while(1)
	{
		menu();                        //菜单
		scanf("%d",&choice);
		switch(choice)
		{
		case 1://添加学生信息
				temp=Add_data();          //输入学生信息
				head=addToList(head,temp);//将学生信息添加进去链表
				break;
		
		case 2:Show_Alldata(head);break; 

		case 3:Find(head);break;		 
	
		case 4:After(head);break;		 

		case 5:head=Delete(head);break;	 

		case 6:sort(head);break;		  
			
		case 7:filewriting(head);break;   
		
		case 8:head=fileread(head);break;  

		case 0:exit();break;

		}
	}
}
stu createStuScore()			//学生信息创建 
{
	stu temp;
	printf("请输入学生姓名:\n"); 
	scanf("%s",temp.name);
	printf("请输入学生学号\n");
	scanf("%d",&temp.stu_id);
    printf("请输入学生班级\n");
    scanf("%s",temp.stu_class);
    printf("请分别输入学生三门课程成绩\n");
    scanf("%f %f %f",&temp.grade[0],&temp.grade[1],&temp.grade[2]);
	return temp;
}


List Add_data()					// 新建一个节点 并且完成对数据域的赋值 
{
	List Node;
	Node=(List)malloc(sizeof(LNode));	//节点分配内存
	Node->s=createStuScore();           //完成对学生信息赋值
	Node->next=NULL;	
	return Node;                        //返回节点地址
}

//将一个节点添加到列表中去，返回列表的头指针
List addToList(List L,List temp)
{
    /*采用头插法对链表的链接*/
	temp->next=L;    
	L=temp;
	return L;
}

//显示信息
void Show_data(stu temp)
{
	printf("学生姓名:%s\t学生学号:%d\t学生班级:%s\t学生三门课程成绩: %.2f %.2f %.2f\n",
    temp.name,temp.stu_id,temp.stu_class,temp.grade[0],temp.grade[1],temp.grade[2]);
}
//显示所有学生信息
void Show_Alldata(List L)
{
	if(L==NULL)
		printf("没有信息！"); 
	while(L)
	{
		Show_data(L->s);
		L=L->next;
	}
	getchar();getchar();
}

//查询函数
void Find(List L)
{
	int pos;
    /*我用的是学生学号查询，当然你可以用其他的查询条件*/
	printf("请输入查询学生学号编号:\n");
	scanf("%d",&pos);	
	while(L)
	{
		if(pos==L->s.stu_id){				//判断 条件	
			Show_data(L->s);
			printf("查询成功！\n");
			getchar();getchar();
			return; 
        }
		L=L->next;
	}
	printf("查询失败！\n");
    	getchar();getchar();
}

//修改程序函数
void After(List L)
{
	int pos;
    /*我用的是学生学号修改，当然你可以用其他的查询条件*/	
	printf("请想要修改学生学号:\n");
	scanf("%d",&pos);
	while(L)
	{
		if(pos==L->s.stu_id)
		{
			L->s=createStuScore();    //重新创建学生信息，并赋值
            printf("修改成功!\n");
            getchar();getchar();
			return; 
		}
		L=L->next;
	}
	printf("修改失败!\n");
	getchar();getchar();
}

//删除成绩函数
List Delete(List L)
{
	int pos;
    /*我用的是学生学号删除，当然你可以用其他的查询条件*/
	List temp=L->next;    //注意我的写法
    List head=L;  
	printf("请输入删除学生学号\n");
	scanf("%d",&pos);
	/*先判断头节点信息*/
	if(pos==head->s.stu_id)
	{
		L=head->next;			//找到信息节点 等于找到信息节点 的下一个节点 实现地址变更 
		printf("删除成功!\n");
		getchar();getchar();
		return L;
	}
	else{
		
		while(temp)                    
		{
			if(pos==temp->s.stu_id)         /*找到信息节点 temp=L->next   head=L */ 
			{                             
				head->next=temp->next;    //找到信息节点 等于找到信息节点 的下一个节点 实现地址变更
                free(temp);
                printf("删除成功!\n");
                getchar();getchar();
				return L;
			}
			else
				temp=temp->next;
		}
	}
	printf("删除失败!\n");
    getchar();getchar();
    return L;
}

//排序
void sort(List L)//按从大到小排序 
{
	List big,small;	//头节点 大小节点 
	
	big=L;
	stu temp;               //学生信息临时节点
	int grade,grade1;
	
	
	while(big)
	{
		small=big;
		grade=small->s.grade[0]+small->s.grade[1]+small->s.grade[2];
		while(small)
		{
			grade1=small->s.grade[0]+small->s.grade[1]+small->s.grade[2];
			if(grade>grade1)		//从小到大 依次判断  若不符合则交换 
			{						//采用的是选择排序法 ！不知道的同学，选择排序我前面有讲解  
				temp=big->s;
				big->s=small->s;	//交换  学生信息 注意 交换的是一个整体！ 
				small->s=temp;
			}
			small=small->next;		//内层循环 
		}
		big=big->next;				//外层循环 
	}
	printf("排序成功!\n");
    getchar();getchar();
}
void menu(){

		system("cls");
		printf("              xx学生系统模板            \n\n");
		printf("=========================================\n");
		printf("|             1.添加信息                |\n");
		printf("|             2.显示所有信息            |\n");
		printf("|             3.查询信息                |\n");
		printf("|             4.修改信息                |\n");
		printf("|             5.删除信息                |\n");
		printf("|             6.成绩排序                |\n");
		printf("|             7.信息存储                |\n");
		printf("|             8.信息读取                |\n");
		printf("|             0.退出系统                |\n");
		printf("=========================================\n");
		printf("请输入您的选择:");
}
void exit(){
	printf("退出系统成功!");
	exit(0);
}
void filewriting(List L){
	
	fp = fopen("text.txt", "w");    //打开文件，并且把文件设置为可写状态
	while(L)
    {
            	fprintf(fp,"%s %d %s %.2f %.2f %.2f\n",
                L->s.name,
                L->s.stu_id,
                L->s.stu_class,
                L->s.grade[0],
                L->s.grade[1],
                L->s.grade[2]);//将链表里头的数据存储的 text.txt文件里去。 
                                
            	L=L->next;    
    }
    fclose(fp);        //关闭文件
}

List fileread(List L){

	fp = fopen("text.txt", "r");    //打开文件，并且把文件设置为可写状态
	while(!feof(fp))				//feop 一直到文件信息最后 一个'/0' 
	{ 
		fscanf(fp,"%s %d %s %f %f %f\n",    	//将文件里头的数据text.txt 存储到链表里去
                people.name,
                &people.stu_id,
                people.stu_class,
                &people.grade[0],
                &people.grade[1],
                &people.grade[2]
        );			
		List p=(List)malloc(sizeof(LNode));      //创建一个新节点
        p->s=people;                             //对节点学生信息赋值
        p->next=NULL;							  
        L=addToList(L,p);                        //头插法添加节点
	}
    fclose(fp);									//关闭文件
	printf("读取成功");
	getchar();getchar(); 
    return L;											
}

