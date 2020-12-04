/*Leetcode 

qsort char 排序
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int *PosCount;
int cmp(const void* a,const void* b){
	int deff = PosCount[*(const char*)b]-PosCount[*(const char*)a];
		if(deff==0)
			return *(const char*)a-*(const char*)b;		
	return deff;								//排序次数 
}
//int cmp(const char* a,const char* b){	
//	return *a-*b;
//}
int main(){

	char a[]="abcdadadasdga";
	char b[]="sadasfahiquwhruikbg";
	int Count[128]={0};	
	for(int i=0;i<strlen(a);i++){	//记录字符串出现次数 
		Count[b[i]]++;	
	}
	PosCount=Count;
//	qsort(a,strlen(a),sizeof(char),cmp);
	qsort(b,strlen(b),sizeof(char),cmp);
	printf("%s\n%s",a,b);
	return 0;
}
*/




/*快排 int
#include<stdio.h>
#include<stdlib.h>	// 函数包 里面 内置 qsort() 
int cmp(const void* a,const void* b){				//比较函数 
													// *a 放在 *b 前面 返回一个负数  用于从小到大排序 
	return *(const int *)a-*(const int *)b;			// *a  与  *b 相等 返回值为 0													 
}													// *b 放在 *a 前面 返回一个正数  用于从大到小排序  
int main(){
	
	int a[]={3,2,1,3,4,5,6,2,3,5};	
	qsort(a,10,sizeof(int),cmp);	//qsort 4个参数 第一个 待排元素数组 首地址 	
	for(int i=0;i<10;i++){			//           	第二个 待排元素元素 数量 
		printf("%d ",a[i]); 		//              第三个 待排元素 占用空间大小 可以有字符 整形... int char float double struct 
	}								//              第四个 int 类型比较函数  用于设置比较函数排序方式  
	return 0;
}
*/
/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int *PosCount;
int cmp(const void* a,const void* b){
	int deff = PosCount[*(const char*)b]-PosCount[*(const char*)a];
		if(deff==0)
			return *(const char*)a-*(const char*)b;		
	return deff;								//排序次数 
}
//int cmp(const char* a,const char* b){	
//	return *a-*b;
//}
int main(){

	char a[]="abcdadadasdga";
	char b[]="sadasfahiquwhruikbg";
	int Count[128]={0};	
	for(int i=0;i<strlen(a);i++){	//记录字符串出现次数 
		Count[b[i]]++;	
	}
	PosCount=Count;
//	qsort(a,strlen(a),sizeof(char),cmp);
	qsort(b,strlen(b),sizeof(char),cmp);
	printf("%s\n%s",a,b);
	return 0;
}
*/




#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void* a,const void* b){
	
	return *(const char*)a-*(const char*)b;		// 字符类型  从小到大排序  
}

int main(){
	char a[]="gaogaotwo";
	qsort(a,strlen(a),sizeof(char),cmp);
	printf("%s",a);
	return 0;
}






67



