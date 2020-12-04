#include<stdio.h>

int Step=0;	//全局变量 记录步数 
void Move(int n,char x,char y,char z,int *Array);
int main(){
	int Dish_1;
	printf("请输入有几个盘子\n");
	
	scanf("%d",&Dish_1);
	int Dish[Dish_1+1];	//记录盘子标号 
	
	for(int i=0;i<Dish_1;i++)
		Dish[i]=i+1;
	Move(Dish_1,'A','B','C',Dish);

	return 0;
} 
void Move(int n,char x,char y,char z,int *Array){

	if(n==0){
		return; 
	}else{
		Move(n-1,x,z,y,Array);
		printf("第%d步:将%d号盘子从%c - > %c\n",++Step,Array[n-1],x,z);
		Move(n-1,y,x,z,Array);
	}
	return;
}
