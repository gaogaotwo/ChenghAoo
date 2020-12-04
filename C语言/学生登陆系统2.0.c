#include <stdio.h>
#include <string.h>	//C中字符串处理相关函数的头文件
#include <stdlib.h>
#include <conio.h>
#define LEN 20 
int Student = -1 ;	//默认学生人数为 -1 个 

struct student{
	int grade;
	char name[20];
};
int main()
{

	
	char password[LEN];		//用于存放密码

	char confirmation[LEN];		//用于保存确认密码

	int tryAgain = 0;				//重试的次数
	char opt;//菜单选项
	
	//1.创建管理系统

	do
	{
		printf("----------创建密码---------\n");
		printf("请输入你的管理密码：");
		scanf("%s", password);
		printf("请确认你的管理密码：");
		scanf("%s", confirmation);
	}while(strcmp(password, confirmation));	
			
		printf("密码设置成功！你的密码为%s\n", password);
		printf("按任意键开始登录系统.....\n");
		getch();	//阻塞函数，可以让程序停留在此，直到我们按下键盘上的某个按键

		system("cls");	//清屏	
	//2.登录系统
	printf("----------登录系统---------\n");
		printf("请输入密码：");
	
	while(scanf("%s", confirmation), strcmp(password, confirmation))
	{
		tryAgain++;	//累加密码重试的次数
		//密码重试的次数限制在三次以内
		if(tryAgain < 3)
			printf("错误%d次！请重新输入：", tryAgain);
		else
			break;	//输入密码次数大于等于三次，退出循环

	}
	//3.输出结果
	system("cls");
	//两种情况 ：1输入了三次错误的密码 2输入了正确的密码
	printf("----------输出结果---------\n");
	if(tryAgain >= 3)
	{		
		printf("对不起，3次密码错误，系统退出！\n");
		exit(-1); //退出程序
	}else{		
		printf("欢迎进入管理系统！\n");
	}
int Pos,Pos_1; 
int i,j;

struct student s[20]; // 分配20学生给它 

	while(1){
		main_menu();
		scanf("%d",&Pos);
		switch(Pos){
			case 1:				//学生录入信息 姓名 + 成绩 
			
				Student++; //学生人数增加1
				printf("请输入学生姓名\n");
					scanf("%s",s[Student].name);
				printf("请输入学生成绩\n");
					scanf("%d",&s[Student].grade);
				 	
				
				printf("录入成功 ！\n");
				getchar();getchar();			
				break;
			case 2:
				printf("请输入你查询的学生编号\n");
				scanf("%d",&Pos_1);
				if(Pos_1>=0&&Pos_1<=Student){
					printf("学生姓名:%s 成绩 : %d",s[Pos_1-1].name,s[Pos_1-1].grade);
					getchar();
				}else{
					printf("不存在该学生信息！\n");
					getchar(); 
				}
				getchar();	
				break;
			case 3:
				for(i=0;i<=Student;i++){
					for(j=i+1;j<=Student;j++){
						if(s[i].grade>s[j].grade){
							struct student temp= s[i];
							s[i] = s[j];
							s[j] = temp;
						}
					}
				} 
				printf("排序成功！");
				getchar();getchar();
				break;
			case 4:
				for(i=0;i<=Student;i++){
					printf("学生姓名:%s 成绩 : %d\n",s[i].name,s[i].grade);
				}
				break; 
				
				
			case 0:
				printf("退出系统成功 ！");
				getchar();getchar(); 
				exit(0);
				break;
				
				
		
		
		}	
	system("cls");	
	}	
	
	return 0;	
}

void  main_menu(){
	printf(".                                主菜单                               .\n");	
	printf(".......................................................................\n");	
	printf(".                             学生管理系统                            .\n"); 
	printf(".                             1.录入学生信息                          .\n");  
	printf(".                             2.查询学生信息                          .\n");
	printf(".                             3.排序学生成绩                          .\n");
	printf(".                             4.打印全体学生成绩                      .\n");
	printf(".                             0.退出                                  .\n");
	printf(".......................................................................\n");
}

