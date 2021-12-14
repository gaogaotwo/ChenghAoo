#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
/*
	（二）任务：某公司有40个员工（包括五个部门），现要求对员工工资进行汇总。要求编程计算：
		1.统计一个部门员工的总工资及平均工资；
		2.统计员工若干项工资的总工资及平均工资；
		3.输出排序后部门员工工资单。
二、内容与要求
（一）内容：运用函数的相关知识根据条件对员工工资进行汇总。
（二）要求：巩固函数的定义、函数的嵌套调用与递归调用的有关知识。
*/
typedef struct Staff{
	char Name[21];			// 员工姓名 
	int Salary[3];			// 员工工资	分为若干项 3 个类型构成
	float Avg_salay;    	// 员工的平均工资
	char department[20]; 	// 员工所属部门 
} Sta[40];			//假设有 40 名员工

void Sector_wages();  //统计一个部门员工的总工资及平均工资；
void Employee_wages(struct Staff*); //统计员工若干项工资的总工资及平均工资；
//采用快速排序的方法，分治，递归调用 
int Pos(struct Staff*,int L,int R);
void Salay_Sort(struct Staff*,int L,int R);
// 五个部门总体工资,部门人数 
int Sum_a = 0, Alen = 0;
int Sum_b = 0, Blen = 0;
int Sum_c = 0, Clen = 0;
int Sum_d = 0, Dlen = 0;
int Sum_e = 0, Elen = 0;  
/*
	假设有5 个部门，分别为 A B C D E，总计40个人 
	张三 2100 4200 3200 A
	皮皮 2130 4202 4204 A
	李二 2104 3421 5220 A
	李三 4104 3222 8220 A
	李强 3104 3221 6220 A
	李五 3106 3441 2220 A
	李六 2104 3222 8220 A
	李七 1204 1231 6220 A
	王三 2100 4200 3200 B
	王皮 2120 4202 4204 B
	王二 2134 3421 7220 B
	王三 4114 3222 8220 B
	王强 3224 2221 6223 B
	王叁 2434 1421 7222 B
	王皮 4514 3222 8221 B
	王杨 3624 2221 6225 B
	梁三 2124 4221 3227 C
	梁皮 4120 4232 2234 C
	梁二 5134 3421 1222 C
	梁三 4614 3222 8322 C
	梁强 6122 3371 6221 C
	梁八 2134 3421 7242 C
	梁七 4614 3522 8272 C
	梁五 2124 3271 6221 C
	伏三 3100 4203 3200 D
	伏皮 4120 4202 4204 D
	伏二 5134 3421 7220 D
	伏三 6114 3232 8221 D
	伏强 6124 3223 6223 D
	伏七 3124 3421 6210 D
	伏刘 3112 3232 5221 D
	伏五 2124 3231 1233 D
	杨三 3106 6200 3270 E
	杨皮 2124 2202 4224 E
	杨二 2131 7421 7220 E
	杨三 4123 4222 8260 E
	杨强 7129 2221 6271 E
	杨刘 2132 7441 7223 E
	杨八 9313 4222 8262 E
	杨七 2129 2221 6274 E
*/ 
int main()
{
	Sta s;	//员工信息初始化 姓名 +  若干项 3 个类型构成工资 + 员工所属部门
	for(int i = 0; i < 40; i++){
		printf("请输入第 %d 位员工姓名，若干项工资构成 所属部门分别为:\n",i+1); 
		scanf("%s %d %d %d %s",s[i].Name,&s[i].Salary[0],&s[i].Salary[1],&s[i].Salary[2],s[i].department);
		s[i].Avg_salay = (s[i].Salary[0] + s[i].Salary[1] + s[i].Salary[2]) / 3.0;
		// strcmp 字符串比较函数，若相等这返回值为0 
		if(strcmp(s[i].department,"A") == 0){
			Alen++;
			Sum_a += (s[i].Salary[0] + s[i].Salary[1] + s[i].Salary[2]);
		}
		else if(strcmp(s[i].department,"B") == 0){
			Blen++;
			Sum_b += (s[i].Salary[0] + s[i].Salary[1] + s[i].Salary[2]);
		} 
		else if(strcmp(s[i].department,"C") == 0){
			Clen++;
			Sum_c += (s[i].Salary[0] + s[i].Salary[1] + s[i].Salary[2]);
		} 
		else if(strcmp(s[i].department,"D") == 0){
			Dlen++;
			Sum_d += (s[i].Salary[0] + s[i].Salary[1] + s[i].Salary[2]);
		}
		else if(strcmp(s[i].department,"E") == 0){
			Elen++;
			Sum_e += (s[i].Salary[0] + s[i].Salary[1] + s[i].Salary[2]);
		}   
	}
	Sector_wages();
	Employee_wages(s);
	Salay_Sort(s,0,39);
	
	printf("\n A 部门员工 工资单排序结果为: \n");
	for(int i = 0; i < 40; i++){
		if(strcmp(s[i].department,"A") == 0){
			printf("姓名: %s 工资组成: %d 元/人民币 %d 元/人民币 %d 元/人民币 总体工资: %d 元/人民币 平均工资: %.2f 元人民币\n",
			s[i].Name,s[i].Salary[0],s[i].Salary[1],s[i].Salary[2],
			(s[i].Salary[0] + s[i].Salary[1] + s[i].Salary[2]),(s[i].Salary[0] + s[i].Salary[1] + s[i].Salary[2])/3.0);		
		}
	}
	printf("\n B 部门员工 工资单排序结果为: \n");
	for(int i = 0; i < 40; i++){
		if(strcmp(s[i].department,"B") == 0){
			printf("姓名: %s 工资组成: %d 元/人民币 %d 元/人民币 %d 元/人民币 总体工资: %d 元/人民币 平均工资: %.2f 元人民币\n",
			s[i].Name,s[i].Salary[0],s[i].Salary[1],s[i].Salary[2],
			(s[i].Salary[0] + s[i].Salary[1] + s[i].Salary[2]),(s[i].Salary[0] + s[i].Salary[1] + s[i].Salary[2])/3.0);		
		}
	}
	printf("\n C 部门员工 工资单排序结果为: \n");
	for(int i = 0; i < 40; i++){
		if(strcmp(s[i].department,"C") == 0){
			printf("姓名: %s 工资组成: %d 元/人民币 %d 元/人民币 %d 元/人民币 总体工资: %d 元/人民币 平均工资: %.2f 元人民币\n",
			s[i].Name,s[i].Salary[0],s[i].Salary[1],s[i].Salary[2],
			(s[i].Salary[0] + s[i].Salary[1] + s[i].Salary[2]),(s[i].Salary[0] + s[i].Salary[1] + s[i].Salary[2])/3.0);		
		}
	}
	printf("\n D 部门员工 工资单排序结果为: \n");
	for(int i = 0; i < 40; i++){
		if(strcmp(s[i].department,"D") == 0){
			printf("姓名: %s 工资组成: %d 元/人民币 %d 元/人民币 %d 元/人民币 总体工资: %d 元/人民币 平均工资: %.2f 元人民币\n",
			s[i].Name,s[i].Salary[0],s[i].Salary[1],s[i].Salary[2],
			(s[i].Salary[0] + s[i].Salary[1] + s[i].Salary[2]),(s[i].Salary[0] + s[i].Salary[1] + s[i].Salary[2])/3.0);		
		}
	}
	printf("\n E 部门员工 工资单排序结果为: \n");
	for(int i = 0; i < 40; i++){
		if(strcmp(s[i].department,"E") == 0){
			printf("姓名: %s 工资组成: %d 元/人民币 %d 元/人民币 %d 元/人民币 总体工资: %d 元/人民币 平均工资: %.2f 元人民币\n",
			s[i].Name,s[i].Salary[0],s[i].Salary[1],s[i].Salary[2],
			(s[i].Salary[0] + s[i].Salary[1] + s[i].Salary[2]),(s[i].Salary[0] + s[i].Salary[1] + s[i].Salary[2])/3.0);		
		}
	}
    return 0;
}
void Sector_wages(){
	//输出每个部门工作状况 
		printf("\n\n\n当前 %c 部门 员工总工资为: %d 元/人民币 平均工资为: %.2f 元/人民币\n",'A',Sum_a,Sum_a / (Alen * 1.0));
		printf("当前 %c 部门 员工总工资为: %d 元/人民币 平均工资为: %.2f 元/人民币\n",'B',Sum_b,Sum_b / (Blen * 1.0));
		printf("当前 %c 部门 员工总工资为: %d 元/人民币 平均工资为: %.2f 元/人民币\n",'C',Sum_c,Sum_c / (Clen * 1.0));
		printf("当前 %c 部门 员工总工资为: %d 元/人民币 平均工资为: %.2f 元/人民币\n",'D',Sum_d,Sum_d / (Dlen * 1.0));
		printf("当前 %c 部门 员工总工资为: %d 元/人民币 平均工资为: %.2f 元/人民币\n\n\n",'E',Sum_e,Sum_e / (Elen * 1.0));
}
void Employee_wages(struct Staff* s){
	for(int i = 0; i < 40; i++){
		printf("姓名: %s 工资组成: %d 元/人民币 %d 元/人民币 %d 元/人民币 平均工资为: %.2f 部门: %s\n",s[i].Name,s[i].Salary[0],s[i].Salary[1],s[i].Salary[2],s[i].Avg_salay,s[i].department);
	}
}
int Pos(struct Staff* s,int L,int R){
	struct Staff tep = s[L];
	while(L < R){
		while(L < R && s[R].Avg_salay >= tep.Avg_salay){
			R--;
		}
		s[L] = s[R];
		while(L < R && s[L].Avg_salay <= tep.Avg_salay){
			L++;
		}
		s[R] = s[L];
	}
	s[L] = tep;
	return L; 
}
void Salay_Sort(struct Staff* s,int L,int R){
	// 快速排序 统一接口 递归，嵌套调用 ，每次排序采用分治的方法 
	if(L < R){
		int pos = Pos(s,L,R);
		Salay_Sort(s,L,pos-1);
		Salay_Sort(s,pos+1,R);	
	}
}

