#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h> 
typedef struct people{
	char name[15];			//名字 
	char card_id[10];		//账号id
	char peo_id[20];		//身份证id
	char phone_num[10];		//手机号码
	float account;			//账户余额	   
}peo;
//typedef struct time{
//	int year[10];	
//	int month[10];
//	int day[10];
//	int hour[10];
//	int minutes[10];
//	int second[10];
//	char behavior[10];
//}Time;

typedef struct LNode *PtrToAdjVNode;
struct LNode{
	//Time t;				  	//时间 
	peo p;                    			//数据域
	struct LNode *next;       			//指针域       
};
typedef PtrToAdjVNode List;

peo createStuScore();					//添加储户数据 
List Add_data();				        //添加链表节点 
List addToList(List L,List temp);       		//头插法插入节点 
void Show_data(peo temp);				//显示数据 
void Show_Alldata(List L);			 	//交易明细 
void Find(List L);					//查询数据 
void After(List L);				    	//储户存款 
List Delete(List L);					//销户用户 
void After_1(List L);					//储户取款 
void menu();						//主菜单 
void exit();						//退出系统 
void filewriting(List L);				//文件存储 
List fileread(List L);					//文件读取

FILE *fp;                           			//文件
peo Temp;						//储户临时节点 
//	  time_t timep;					//时间函数节点 
//    struct tm *q;
 
int main()
{
	system("color 8E");
	List head=NULL,temp;                		//头节点初始化
	int choice; 
	while(1)
	{
		menu();                        		//菜单
		scanf("%d",&choice);
		switch(choice)
		{
		case 1://添加储户信息
			temp=Add_data();          	//输入储户信息
			head=addToList(head,temp);	//将储户信息添加进去链表
			break;
		
		case 6:Show_Alldata(head);break; 

		case 5:Find(head);break;		 
	
		case 3:After(head);break;		 

		case 2:head=Delete(head);break;	 

		case 4:After_1(head);break;		  
			
		case 7:filewriting(head);break;   
		
		case 8:head=fileread(head);break;  

		case 0:exit();break;

		} 
	}
}
peo createStuScore()					//储户信息创建 
{
	peo temp_1;
	printf("请输入储户姓名:\n"); 
	scanf("%s",temp_1.name);
	
	printf("请输入储户账号 （6位）\n");
	while(strlen(temp_1.card_id)!=6){		//6 位数的哟 
		scanf("%s",temp_1.card_id);
	}
	
	printf("请输入储户身份证号码（18位）\n");
	while(strlen(temp_1.peo_id)!=18){   		//18 位数的哟 	
    	scanf("%s",temp_1.peo_id);
    } 
    printf("请输入储户联系电话\n");
    	scanf("%s",temp_1.phone_num);
		
		temp_1.account=0;						//开户默认账户为0
									 
	return temp_1;
}


List Add_data()					// 新建一个节点 并且完成对数据域的赋值 
{
	List Node;
	Node=(List)malloc(sizeof(LNode));	//节点分配内存
	Node->p=createStuScore();           	//完成对储户信息赋值
	Node->next=NULL;	
	return Node;                        	//返回节点地址
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
void Show_data(peo temp)
{
	printf("储户姓名:%s 储户账号: %s 身份证号 : %s 联系电话: %s 账号余额: %.3f\n",temp.name,temp.card_id,temp.peo_id,temp.phone_num,temp.account);
	  
}
//显示所有储户信息
void Show_Alldata(List L)
{
	if(L==NULL)
		printf("没有信息！"); 
	while(L)
	{
		Show_data(L->p);
		L=L->next;
	}
	getchar();getchar();
}

//查询函数
void Find(List L)
{
	char pos[10];
    /*我用的是储户学号查询，当然你可以用其他的查询条件*/
	printf("请输入查询储户卡号:\n");
	scanf("%s",pos);	
	while(L)
	{
		if(!strcmp(L->p.card_id,pos)){				//判断 条件	
			Show_data(L->p);
			printf("查询成功！\n");
			getchar();getchar();
			return; 
        }
		L=L->next;
	}
	printf("查询失败！\n");
    	getchar();getchar();
}

//储户存款函数
void After(List L)
{
	char pos[10];
	float money;
    /*我用的是储户账号，当然你可以用其他的查询条件*/
    
//    time(&timep);
//    q =localtime(&timep); //此函数获得的tm结构体的时间，是已经进行过时区转化为本地时间
	
		
	printf("请想要储户账号:\n");
	scanf("%s",pos);
	while(L)
	{
		if(!strcmp(L->p.card_id,pos))
		{
			printf("请输入存款额度\n");
				scanf("%f",&money);
				L->p.account+=money;				
//				L->t.day[]=1900+q->tm_year;
//				L->t.month=1+q->tm_mon;
//				L->t.day=q->tm_mday;
//				L->t.hour=q->tm_hour;
//				L->t.minutes=q->tm_min;
//				L->t.second=q->tm_sec;
				printf("存款成功\n");							 
            	getchar();getchar();
				return; 
		}
		L=L->next;
	}
	printf("存储失败!\n");
	getchar();getchar();
}

//删除成绩函数
List Delete(List L)
{
	char pos[10];
    /*我用的是储户学号删除，当然你可以用其他的查询条件*/
	List temp=L->next;    //注意我的写法
    List head=L;  
	printf("请输入销户账号\n");
	scanf("%s",pos);
	/*先判断头节点信息*/
	if(!strcmp(head->p.card_id,pos))
	{
		L=head->next;			//找到信息节点 等于找到信息节点 的下一个节点 实现地址变更 
		printf("销户成功!\n");
		getchar();getchar();
		return L;
	}
	else{
		
		while(temp)                    
		{
			if(!strcmp(L->p.card_id,pos))           /*找到信息节点 temp=L->next   head=L */ 
			{                             
				head->next=temp->next;    //找到信息节点 等于找到信息节点 的下一个节点 实现地址变更
                		free(temp);
                		printf("销户成功!\n");
                		getchar();getchar();
				return L;
			}
			else
			temp=temp->next;
		}
	}
	printf("销户失败!\n");
    	getchar();getchar();
    	return L;
}

//储户取款函数
void After_1(List L)//按从大到小排序 
{
	char pos[10];
	float money;
    /*我用的是储户账号，当然你可以用其他的查询条件*/
    
//    time(&timep);
//    q =localtime(&timep); //此函数获得的tm结构体的时间，是已经进行过时区转化为本地时间
	
		
	printf("请想要取款储户账号:\n");
	scanf("%s",pos);
	while(L)
	{
		if(!strcmp(L->p.card_id,pos))
		{
			printf("请输入取款额度\n");
				scanf("%f",&money);
				if(L->p.account-money>0){ 
					L->p.account-=money;
					printf("取款成功");
				}					
//				L->t.day[]=1900+q->tm_year;
//				L->t.month=1+q->tm_mon;
//				L->t.day=q->tm_mday;
//				L->t.hour=q->tm_hour;
//				L->t.minutes=q->tm_min;
//				L->t.second=q->tm_sec;
				else
					printf("取款失败");								 
            getchar();getchar();
			return; 
		}
		L=L->next;
	}
	printf("存储失败!\n");
	getchar();getchar();
}
void menu(){

		system("cls");
		printf("             活期储存账目管理系统       \n");
		printf("=========================================\n");
		printf("|             1.储户开户                |\n");
		printf("|             2.储户销户           	|\n");
		printf("|             3.储户存款             	|\n");
		printf("|             4.储户取款                |\n");
		printf("|             5.余额查询              	|\n");
		printf("|             6.交易明细             	|\n");
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
            	fprintf(fp,"%s %s %s %s %f\n",
                	L->p.name,
                	L->p.card_id,
                	L->p.peo_id,
                	L->p.phone_num,
               	    L->p.account);//将链表里头的数据存储的 text.txt文件里去。				                        
            		L=L->next;    
    }
    		printf("存储信息成功"); 
    		fclose(fp);        //关闭文件
}

List fileread(List L){

	fp = fopen("text.txt", "r");    //打开文件，并且把文件设置为可写状态
	while(!feof(fp))				//feop 一直到文件信息最后 一个'/0' 
	{ 
		fscanf(fp,"%s %s %s %s %f\n",    	//将文件里头的数据text.txt 存储到链表里去
               		Temp.name,
                	Temp.card_id,
                	Temp.peo_id,
                	Temp.phone_num,
               	   &Temp.account
        );			
		List pe=(List)malloc(sizeof(LNode));       //创建一个新节点
        	pe->p=Temp;                              //对节点储户信息赋值
        	pe->next=NULL;							  
        	L=addToList(L,pe);                         //头插法添加节点
	}
    	fclose(fp);				          //关闭文件
	printf("读取信息成功");
	getchar();getchar(); 
    	return L;											
}

