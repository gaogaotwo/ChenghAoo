#include <stdio.h>
#include <stdlib.h> 
typedef struct Staff{
	char Name[21];	// 员工姓名 
	int Salary;		// 员工工资 
} Sta[6];	//假设有6 名员工

float Avg = 0.0; //员工的平均工资
int Sum = 0; // 员工总共的工资

void menu();						//菜单 
void Avg_salary(struct Staff*);		//计算员工平均工资 
void Sum_salary(struct Staff*);		//计算员工总共工资 
void Sort_salary(struct Staff*); 	//对员工工资进行排序

/*
（一）内容：
设计一个系统，通过选择不同的菜单项来完成不同的功能，如选择1、2、3分别计算员工工资的平均工资和总工资、对工资进行排序，输入其他数字结束计算。
任务1：设计一个菜单函数menu( )，显示工资系统所有可供选择的功能信息。
任务2：设计一个函数，计算员工的平均工资。
任务3：设计一个函数，计算员工的总工资。
任务4：设计一个函数，对员工工资进行排序。
最后还需设计一个包含main(  )函数的主程序调用以上4个函数。
*/ 
int main()
{
	// 员工 姓名 工资初始化操作 
    Sta S = {
		{"宋晓英",5400},
		{"张浩",6500},
		{"赵宇",8500},
		{"于文延",5600},
		{"熊炎",6700},
		{"刘双",8400}
	};
	int Pos;
	while(1){
		system("cls"); // 清屏函数,需要库函数stdlib.h 
		menu();
		scanf("%d",&Pos); 
		switch(Pos){
			case 1:
				Avg_salary(S);
				break;
			case 2:
				Sum_salary(S);
				break;
			case 3:
				Sort_salary(S);
				break;
			case 4:
				printf("退出员工工资系统成功！"); 
				return -1;
				break;
			default:
				printf("请输入正确序号！");
				getchar();
				break; 
		}
	}
	 
    
    return 0;
}
void menu(){
	printf("\n\n\t\t\t欢迎来到 员工工资系统，请输入功能序号:\n");
	printf("\t\t\t1，计算员工平均工资\n");
	printf("\t\t\t2，计算员工总工资\n");
	printf("\t\t\t3，对员工工资进行排序\n");
	printf("\t\t\t4，退出系统\n"); 
}
void Avg_salary(struct Staff* S){
	
	//员工平均工资注意初始化 ！ 
	Avg = 0.0;
	for(int i = 0; i < 6; i++){
		printf("员工姓名:%s 工资 %d 元/人民币\n",S[i].Name,S[i].Salary);
		Avg += S[i].Salary; 
	}
	printf("\n当前员工平均工资为: %.2f 元/人民币",Avg / 6.0);
	getchar();getchar();  
}
void Sum_salary(struct Staff* S){
	//员工总体工资注意初始化 ！ 
	Sum = 0.0;
	for(int i = 0; i < 6; i++){
		printf("员工姓名:%s 工资 %d 元/人民币\n",S[i].Name,S[i].Salary);
		Sum += S[i].Salary; 
	}
	printf("\n员工总共工资为: %d 元/人民币",Sum);
	getchar();getchar(); 
}
void Sort_salary(struct Staff* S){
	// 当前采用的是选择排序的方法，每次遍历选取一个第 i 大的值作为遍历一遍之后结果 
	for(int i = 0; i < 6; i++){
		for(int j = i + 1; j < 6; j++){
			if(S[i].Salary < S[j].Salary){
				// 这里 一定要注意交换的是 一个整体！ 
				struct Staff pos = S[i];
				S[i] = S[j];
				S[j] = pos;
			}
		}
	}
	printf("对于工资排序之后的结果(按照工资由大到小排列)\n"); 
	for(int i = 0; i < 6; i++){
		printf("员工姓名:%s 工资 %d 元/人民币\n",S[i].Name,S[i].Salary);
	} 
	getchar();getchar(); 
}

