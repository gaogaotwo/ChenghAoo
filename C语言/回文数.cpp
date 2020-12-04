#include<stdio.h>
int main(){
	
	int j;
	int num=0;
	for(int i=900;i<=1100;i++){
		int a[4];	// 每次 最多存四个元素；0-9999范围内 
		j=0;		// 位数 
		int temp=i;
/*--------------------------------------------------*/	
		while(temp!=0){	//取每一位数值 
			a[j++]=temp%10;		
			 temp=temp/10;	
		}
//		for(int i=0;i<4;i++){
//			printf("%d",a[i]);
//		}
//		printf("%d",j);
//		printf("a");
		bool Istrue = true;	
		//需要进行奇数 偶数的判断 
/*--------------------------------------------------*/		
		if(j%2==1){ 	//奇数 
		for(int n=0,temp1=j-1;n!=temp1;n++,temp1--){
			if(a[n]!=a[temp1]){		//双指标 头尾相比较		
				Istrue=false;		//假设不满足情况 就跳出了 
				break;
			}
		}
		if(Istrue){
			printf("%d ",i);	//回文数;
			num++; 
		}
	}
/*--------------------------------------------------*/	
		else{		//偶数情况下 	注意我的结束条件 
			for(int n=0,temp1=j-1;n!=temp1+1;n++,temp1--){
			if(a[n]!=a[temp1]){			//双指标 头尾相比较
				Istrue=false;
				break;
			}
		}
		if(Istrue){
			printf("%d ",i);	//回文数;
			num++; 
		}	
	} 
/*------------------------换行------------------------*/	
		if(num==8){
			printf("\n");
			num=0;
		}
			
	} 

	return 0;
} 

