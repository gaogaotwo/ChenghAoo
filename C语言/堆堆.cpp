#include<stdio.h>
#include<stdlib.h>
int cmp(const void* a,const void* b){
	return *(const int *)a-*(const int *)b;
}
int main(){
	int N;
	scanf("%d",&N);
	int a[N];
	int Sum=0;
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);	//累加和 
		Sum+=a[i];	
	}
	qsort(a,N,sizeof(int),cmp);	//快速排序 
int Pos=Sum;
int S2;							
bool Pos_1=false;
	for(int i=N-1;i>=0;i--){    // i = N-1 下标 4 3 2 1 0  
		for(int j=0;j<=i;j++){	// j <= i下标   0 1 2 3 4  
			S2=Pos-a[j];        // Pos 初始值 Sum
//			printf("%d\n",S2);  
			if(Sum-2*S2>=0){		//  找到"第一个为正数"的情况	
				Pos_1 = true;
				break;
			}								
		}
		if(Pos_1==true){
			break;
		}
		Pos=Pos-a[i];		//隔板 1 2 3 4 | 5				
}	
printf("Sum=%d\nS1=%d\nS2=%d\nMin (S1*S1-S2*S2)=%d",Sum,Sum-S2,S2,Sum*(Sum-2*S2));
	return 0;
} 
