#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
/*------------------------------------------------------------*/
//{ 	//一维序列 动态分配内存  初始化
// 
///* 	 
//  calloc malloc 都是给 空指针 分配内存 区别calloc 默认会将值 设为 0     
//*/		 
//	int Len=6;
//	int *array=(int *)malloc(sizeof(int)*Len);
//	memset(array,0,sizeof(int)*Len);
///*int *array=(int *)calloc(Len,sizeof(int));*/	
//	for(int i=0;i<Len;i++){
//		printf("%d ",array[i]);
//	} 
//} 
/*------------------------------------------------------------*/
//printf("\n");
//{
//	//二维序列  动态分配内存 初始化 
//	int Len=6;		
//	int **Array=(int**)malloc(sizeof(int*)*Len);		
//	for(int i=0;i<Len;i++){	
//		Array[i]=(int*)calloc(Len,sizeof(int)); 
//	}
//	for(int i=0;i<Len;i++){
//		for(int j=0;j<Len;j++){
//			printf("%d ",Array[i][j]);
//		}
//		printf("\n");
//	}
//	
//}


	int Len=6;
	int *a=(int *)malloc(sizeof(int)*Len);
	memset(a,0,sizeof(int)*Len);

	int *b=(int *)realloc(a,sizeof(int)*(Len/2)); //给序列a  Len /2;	
	printf("\n*a首地址%d *b首地址%d",a,b);
	
	
	












 







	
	return 0;
}

 
