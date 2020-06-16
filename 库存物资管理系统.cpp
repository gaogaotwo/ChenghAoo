#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Commodity{			//物品属性 
	char name[15];				//名字 
	char Manufacturer[15]; 			//生产厂家 
	char Model[10];				//型号
	char Specifiication[15];		//规格 
}Com;
struct Time{
	
	int Year;					//年 
	int month;					//月 
	int Day;					//日
	int hour;					//小时
	int minute;					//分钟 
};
typedef struct OtherProperties{
	
	int number;					//物品数量 
	char Warehousing_unit[30];	//入库单位 
	char Delivery_unit[30];		//出库单位 
	char Delivery_boy[15];		//送货员 
	char Pick_up_boy[15];		//提货员 
}Other;   
typedef struct LNode *PtrToAdjVNode;
struct LNode{
	Com c;
	Time t;					  //数据域
	Other s;                  
	struct LNode *next;       		  //指针域       
};
typedef PtrToAdjVNode List;

Com createComScore();					//添加信息 
Time createTimeScore();
Other createOtherScore();


List Add_data();				        //添加链表节点 
List addToList(List L,List temp);       		//头插法插入节点 
void Show_Alldata(List L);			    	//展示所有数据 
void Find(List L);					//查询数据 
void After(List L);				    	//修改数据 
List Delete(List L);					//删除数据

 
Com createComScore();
Time createTimeScore();
Other createOtherScore();

void Show_Commodity(Com temp);
void Show_Time(Time temp);
void Show_Other(Other temp);

void menu();							//主菜单 
void exit();							//退出系统 
void filewriting(List L);					//文件存储 
List fileread(List L);						//文件读取

FILE *fp1,*fp2,*fp3;                    //文件
Com C;									
Time T;									//临时全局节点
Other O;
 
int main()
{
	List head=NULL,temp;                //头节点初始化
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

		case 6:	break;		  
			
		case 7:filewriting(head);break;   
		
		case 8:head=fileread(head);break;  

		case 0:exit();break;

		}
	}
}
Com createComScore()			 
{
	printf("请输入物品名字: ");
	scanf("%s",C.name);
	printf("请输入物品生产厂家: ");
	scanf("%s",C.Manufacturer);
	printf("请输入物品型号: ");
	scanf("%s",C.Model);
	printf("请输入物品规格: ");
	scanf("%s",C.Specifiication); 
	return C;
}
Time createTimeScore(){
	
	printf("请输入物品入库时间 请按 年 月 日 小时 分钟\n");
	scanf("%d.%d.%d.%d.%d",&T.Year,&T.month,&T.Day,&T.hour,&T.minute);
	return T;	
}
Other createOtherScore(){

	printf("请输入物品数量: ");
	scanf("%d",&O.number);
	printf("请输入物品入库单位: ");
	scanf("%s",O.Warehousing_unit);
	printf("请输入物品出库单位: ");
	scanf("%s",O.Delivery_unit);
	printf("请输入送货员姓名: ");
	scanf("%s",O.Delivery_boy);
	printf("请输入提货员姓名: ");
	scanf("%s",O.Pick_up_boy);
	return O;
}

List Add_data()					// 新建一个节点 并且完成对数据域的赋值 
{
	List Node;
	Node=(List)malloc(sizeof(struct LNode));	//节点分配内存
	Node->c=createComScore();           		//完成对信息赋值
	Node->t=createTimeScore();
	Node->s=createOtherScore();
	
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
void Show_Commodity(Com temp){

	printf("货品名称: %s 生产厂家: %s 型号： %s 规格: %s",temp.name,temp.Manufacturer,temp.Model,temp.Specifiication);
}
void Show_Time(Time temp){

	printf(" 时间 %d.%d.%d.%d:%d",temp.Year,temp.month,temp.Day,temp.hour,temp.month);
}
void Show_Other(Other temp){

	printf(" 物品数量: %d 入库单位: %s 出库单位: %s 送货员: %s 提货员: %s\n",temp.number,temp.Warehousing_unit,temp.Delivery_unit,temp.Delivery_boy,temp.Pick_up_boy);
}
//显示所有学生信息
void Show_Alldata(List L)
{
	if(L==NULL)
		printf("没有信息！"); 
	while(L)
	{
		Show_Commodity(L->c);
		Show_Time(L->t);
		Show_Other(L->s);
		L=L->next;
	}
	getchar();getchar();
}

//查询函数
void Find(List L)
{
	int Pos;
	printf("请输入查询方式 1.商品名称查询	2.出入库日期查询\n");
	scanf("%d",&Pos);
	if(Pos==1){
		printf("请输入商品名称: \n");
		scanf("%s",C.name);
		while(L){
		
			if(strcmp(C.name,L->c.name)==0){
				Show_Commodity(L->c);
				Show_Time(L->t);
				Show_Other(L->s);
				getchar();getchar();
				return;			
			}
				L=L->next;		
		}
	
	}
	if(Pos==2){
		printf("请输入物品入库时间 请按 年 月 日 小时 分钟\n");
		scanf("%d.%d.%d.%d.%d",&T.Year,&T.month,&T.Day,&T.hour,&T.minute);
		while(L){
		
			if(L->t.Year==T.Year&&L->t.month==T.month&&L->t.Day==T.Day&&L->t.hour==T.hour&&L->t.minute==T.minute){
				Show_Commodity(L->c);
				Show_Time(L->t);
				Show_Other(L->s);
				getchar();getchar();
				return;			
			}
				L=L->next;		
		}
		printf("未查询数据");	
	}
		getchar();getchar();
}

//修改程序函数
void After(List L)
{
	char Temp[15]; 
    /*我用的是学生学号修改，当然你可以用其他的查询条件*/	
	printf("请输入的修改物品名称:\n");
	scanf("%s",Temp);
	while(L)
	{
		if(strcmp(Temp,L->c.name)==0)
		{
					L->c=createComScore();    //重新创建信息，并赋值
					L->t=createTimeScore();
					L->s=createOtherScore();					
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
	char Temp[15];

	List temp=L->next;    //注意我的写法
    List head=L;  
	printf("请输入删除物品名称\n");
	scanf("%s",Temp);
	/*先判断头节点信息*/
	if(strcmp(Temp,L->c.name)==0)
	{
		L=head->next;			//找到信息节点 等于找到信息节点 的下一个节点 实现地址变更 
		printf("删除成功!\n");
		getchar();getchar();
		return L;
	}
	else{
		
		while(temp)                    
		{
			if(strcmp(Temp,L->c.name)==0)           /*找到信息节点 temp=L->next   head=L */ 
			{                             
				head->next=temp->next;    	//找到信息节点 等于找到信息节点 的下一个节点 实现地址变更
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
void menu(){

		system("cls");
		printf("   	           库存物资管理系统            \n");
		printf("	====================================\n");
		printf("	|            1.录入物品信息	   |\n");
		printf("	|            2.显示所有信息	   |\n");
		printf("	|            3.查询物品信息	   |\n");
		printf("	|            4.修改物品信息	   |\n");
		printf("	|            5.删除物品信息	   |\n");
		printf("	|            7.物品信息存储	   |\n");
		printf("	|            8.物品信息读取	   |\n");
		printf("	|            0.退出系统    	   |\n");
		printf("	====================================\n");
		printf("请输入您的选择:");
}
void exit(){
	printf("退出系统成功!");
	exit(0);
}
void filewriting(List L){
	
	fp1 = fopen("商品.txt", "w");    //打开文件，并且把文件设置为可写状态
	fp2 = fopen("时间.txt", "w");
	fp3 = fopen("商品管理.txt", "w"); 
	while(L)
    {
            	fprintf(fp1,"%s %s %s %s\n",
                	L->c.name,
					L->c.Manufacturer,
					L->c.Model,
					L->c.Specifiication
				);
				fprintf(fp2,"%d %d %d %d %d\n",
                	L->t.Year,
					L->t.month,
					L->t.Day,
					L->t.hour,
					L->t.minute
				);
				fprintf(fp3,"%d %s %s %s %s\n",
                	L->s.number,
					L->s.Warehousing_unit,
					L->s.Delivery_unit,
					L->s.Delivery_boy,
					L->s.Pick_up_boy
				);
                                
            	L=L->next;    
    }
    		fclose(fp1);        //关闭文件
    		fclose(fp2);
    		fclose(fp3);
    	printf("写入文件成功!\n");	
    	getchar();getchar();
}

List fileread(List L){

	fp1 = fopen("商品.txt", "r");    //打开文件，并且把文件设置为可写状态
	fp2 = fopen("时间.txt", "r");
	fp3 = fopen("商品管理.txt", "r");
	while(!feof(fp1)&&!feof(fp2)&&!feof(fp3))				//feop 一直到文件信息最后 一个'/0' 
	{ 
				fscanf(fp1,"%s %s %s %s\n",
                	C.name,
					C.Manufacturer,
					C.Model,
					C.Specifiication
				);
				fscanf(fp2,"%d %d %d %d %d\n",
                	&T.Year,
					&T.month,
					&T.Day,
					&T.hour,
					&T.minute
				);
				fscanf(fp3,"%d %s %s %s %s\n",
                	&O.number,
					O.Warehousing_unit,
					O.Delivery_unit,
					O.Delivery_boy,
					O.Pick_up_boy
				);	
	
	
	
		List p=(List)malloc(sizeof(LNode));       //创建一个新节点
        	p->c=C;                               //对节点信息赋值
        	p->t=T;
        	p->s=O;
        	
        	p->next=NULL;							  
        	L=addToList(L,p);                         //头插法添加节点
	}
    	fclose(fp1);				          			//关闭文件
    	fclose(fp2);
    	fclose(fp3);
		printf("读取成功!");
		getchar();getchar(); 
    	return L;											
}

