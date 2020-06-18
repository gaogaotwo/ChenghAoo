#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
#define N 6		//假设班级有6个人		/*你可以自行的修改*/ 
#define M 3 	//假设有3门成绩 		//依次对应  math english C 
 
typedef struct student{
    int stu_number;  	 				//学号 
    char stu_name[12];			        //姓名 
    float grade[M];						//成绩
}stu;
//顺序表的构建
typedef struct LNode *PtrToAdjVNode;
struct LNode{
    int last;				                //指向最后一个元素下标 
    stu *array;								//学生指针数组 
};
typedef PtrToAdjVNode List;
 
stu temp;   							        //学生全局变量
FILE *fp;        
List MakeEmpty();								//顺序表的初始化 
void AllInsert(List L);							//逐步输入学生信息 
void Show(List L);								//展示整体信息
void FILeWrite(List L);							//学生信息保存
void After(List L);								//顺序表的按序号修改  
void Sort(List L);								//按学号 或学生成绩进行排序
void AchieveMent_statistics(List L);  			//成绩统计 

void login();							        //界面信息 

	  
                   
int main(){

	List L=MakeEmpty(); //顺序表的初始化 
	int option;	
	while(1){
		login();				//显示界面 
		scanf("%d",&option); 	
		system("cls");			        //清屏函数 	
		switch(option)
		{
			case 1:
				AllInsert(L); 				
				break; 
			case 2:
				Show(L);
               	break;
			case 3:
				FILeWrite(L);
				break;
			case 4:
                Sort(L);
				break;
			case 5:
                After(L);				
				break;
            case 6:
  				AchieveMent_statistics(L);
  				break;
  				
			case 7:
            	exit(0);
				break;
			default:
				printf("输入格式错误！！！\n按任意键继续...\n"); 
				getchar();
				break;
			 
		} 
		system("cls");
	}  
    return 0;
} 
List MakeEmpty(){
	List L;
		L=(List)malloc(sizeof(struct LNode));		//给指针分配内存 
    	L->array=(stu*)malloc(sizeof(stu)*MAXSIZE);	//给学生数组分配空间 
    	L->last=-1;									//此时还没有学生,即初始值指向-1 
	return L;  
}

//顺序表的按序号查询
void  Find(List L){
	//我只是写按序号查询，当然你们可以按名字 学号等查询 
        int index;
        printf("请输入你要查询学生的编号:\n");
        scanf("%d",&index);
        if(index>=0&&index<=L->last){
	printf("学号:%d 姓名:%s 成绩: Math English C %.2f %.2f %.2f\n",
		L->array[index].stu_number,
		L->array[index].stu_name,
		L->array[index].grade[0],
		L->array[index].grade[1],
		L->array[index].grade[2]
		);
	}
	else{
		printf("查询失败");
		getchar();getchar();
		return; 		   
		}
        getchar();getchar();
} 
//顺序表的显示
void Show(List L)
{
	for(int i=0;i<=L->last;i++){
		printf("学号:%d 姓名:%s Math: %.2f English: %.2f C: %.2f\n",
		L->array[i].stu_number,
		L->array[i].stu_name,
		L->array[i].grade[0],
		L->array[i].grade[1],
		L->array[i].grade[2]
		);
	}
	getchar();getchar();
}   
//顺序表的修改    
void After(List L){
	//我只是写按序号修改，当然你们可以按名字 学号等查询
	int index;
	stu Temp;
		printf("请输入学号: "); 
		scanf("%d",&Temp.stu_number); 
		printf("请输入姓名:"); 
		scanf("%s",Temp.stu_name); 
		printf("请输入成绩: 请依次输入 Math English C \n");
		scanf("%f %f %f",&Temp.grade[0],&Temp.grade[1],&Temp.grade[2]);
		
		printf("请输入你要修改学生的编号:");
        scanf("%d",&index);
    if(index>=0&&index<=L->last){ 
        L->array[index]=Temp;
        printf("修改成功！！");
    } 
        
    else{
        printf("修改失败");
	return; 		   
	}
   	getchar();getchar(); 
}
//学生管理系统显示界面                  
void login()
{
	printf("\n		欢迎来到班级成绩管理系统\n");
	printf("	=====================================\n");
	printf("	|  1、成绩录入                      |\n");
	printf("	|                                   |\n");
	printf("	|  2、成绩显示                      |\n");
	printf("	|                                   |\n");
	printf("	|  3、成绩保存                      |\n");
	printf("	|                                   |\n");
	printf("	|  4、成绩排序                      |\n");
	printf("	|                                   |\n");
	printf("	|  5、成绩修改                      |\n");
	printf("	|                                   |\n");
   	printf("	|  6、成绩统计                      |\n");
   	printf("	|                                   |\n");
	printf("	|  7、退出系统                      |\n");
	printf("	=====================================\n");
	printf("\n\n请输入你的操作：");
}
void Sort(List L){
							// 注意 我是按照学生总成绩进行排序 
	int i,j;
	float temp1,temp2;
	for(i=0;i<=L->last;i++){
			temp1=(L->array[i].grade[0]+L->array[i].grade[1]+L->array[i].grade[2]);
		for(j=i+1;j<=L->last;j++){
			temp2=(L->array[j].grade[0]+L->array[j].grade[1]+L->array[j].grade[2]);
			if(temp1>temp2){	//我选择的是按照选择排序进行的	
				temp=L->array[i];
				L->array[i]=L->array[j];
				L->array[j]=temp;		
			} 
	}	
}
	printf("排序成功\n");
	for(i=0;i<=L->last;i++){
		temp1=L->array[i].grade[0]+L->array[i].grade[1]+L->array[i].grade[2];
		printf("学号:%d 姓名:%s 总成绩:%.2f\n",
		L->array[i].stu_number,
		L->array[i].stu_name,
		temp1
		);
	}
	getchar();getchar();
}
void AllInsert(List L){

	int i,j;
	if(L->last==N-1){
		printf("全部学生成绩已经录取完毕\n");
		getchar();getchar();
		return;
	}
	for(j=0;j<N;j++){
		++L->last;
		printf("请输入第%d个学生信息\n",j+1);		
		printf("请输入学号：\n"); 
		scanf("%d",&L->array[L->last].stu_number); 
		printf("请输入姓名：\n"); 
		scanf("%s",L->array[L->last].stu_name); 
		printf("请输入成绩：请依次输入 Math English C\n");
		scanf("%f %f %f",&L->array[L->last].grade[0],&L->array[L->last].grade[1],&L->array[L->last].grade[2]);
		system("cls");	
	} 
	printf("添加成绩信息完毕！\n");
	getchar();getchar();
} 
void FILeWrite(List L){
	int i;
	/*写入文件过程*/
    if(L->last==-1){            		//说明此时没有学生数据
        printf("存储学生信息失败");
        getchar();getchar(); 
        return;
        }
        
    fp = fopen("text.txt", "w");     	//打开文件，并且把它设置为可写状态
    for(i=0;i<=L->last;i++){     	//依次把所有学生信息存入text.txt
        fprintf(fp,"学号: %d 姓名: %s Math: %.2f English: %.2f C: %.2f\n",
            L->array[i].stu_number,
            L->array[i].stu_name,
            L->array[i].grade[0],
            L->array[i].grade[1],
            L->array[i].grade[2]);
    }
        fclose(fp);                  	//关闭文件
        printf("存储学生信息成功!");
        getchar();getchar(); 

}
void AchieveMent_statistics(List L){

	int i,Pos,temp1=0,temp2=0,temp3=0,index1,index2,index3;
	float average1=0,average2=0,average3=0,Highest1=-99999,Highest2=-99999,Highest3=-99999;	
	for(i=0;i<=L->last;i++){
		
		average1+=L->array[i].grade[0];
		average2+=L->array[i].grade[1];			//平均成绩 
		average3+=L->array[i].grade[2];
		
		if(L->array[i].grade[0]>Highest1){
			Highest1=L->array[i].grade[0];	
			index1=i;
		}
		if(L->array[i].grade[1]>Highest2){		//最高成绩 
			Highest2=L->array[i].grade[1];
			index2=i;
		}
		if(L->array[i].grade[2]>Highest3){
			Highest1=L->array[i].grade[2];
			index3=i;
		}   
	
	}
		average1=average1/6.0;					//课程Math总体平均成绩
		average2=average3/6.0;					//课程English总体平均成绩
		average3=average3/6.0;					//课程C总体平均成绩
		
		for(i=0;i<=L->last;i++){
			
			if(L->array[i].grade[0]>average1)	//高于平均分 人数 
				temp1++;
			if(L->array[i].grade[1]>average2)	
				temp2++;
			if(L->array[i].grade[2]>average3)	
				temp3++;				
		}		 	
	printf("请输入成绩统计内容:\n1, 显示每门课程成绩最高的学生的基本信息\n2, 显示每门课程的平均成绩\n3,显示超过某门课程平均成绩的学生人数: \n");
		scanf("%d",&Pos);
		if(Pos==1){
				printf("Math最高成绩人信息 学号:%d 姓名:%s 成绩: Math English C %.2f %.2f %.2f\n",
				L->array[index1].stu_number,
				L->array[index1].stu_name,
				L->array[index1].grade[0],
				L->array[index1].grade[1],
				L->array[index1].grade[2]
				);
				printf("English最高成绩人信息 学号:%d 姓名:%s 成绩: Math: %.2f English: %.2f C: %.2f\n",
				L->array[index2].stu_number,
				L->array[index2].stu_name,
				L->array[index2].grade[0],
				L->array[index2].grade[1],
				L->array[index2].grade[2]
				);
				printf("C语言最高成绩人信息 学号:%d 姓名:%s 成绩: Math English C %.2f %.2f %.2f\n",
				L->array[index3].stu_number,
				L->array[index3].stu_name,
				L->array[index3].grade[0],
				L->array[index3].grade[1],
				L->array[index3].grade[2]
				);	
		}
		if(Pos==2){
				printf("每一门课平均成绩分别为Math: %.2f English: %.2f C: %.2f",average1,average2,average3);	
		}
		if(Pos==3){
				printf("超过每门课程平均成绩的人数分别为 Math: %d English: %d C: %d",temp1,temp2,temp3);		
		} 
		
	getchar();getchar();
} 
