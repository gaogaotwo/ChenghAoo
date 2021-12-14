#include <bits/stdc++.h>
typedef struct task{
	int xh;	//作业编号 
	int sj;	//作业 最后完成时间	
	int kf;	//作业 逾期扣分 
}Ta;
/*
3
1 3 1
6 2 3
*/
int Num;	//表示作业个数 
int main(){
	
	Ta ta[101]; 
	int Sum = 0;
	scanf("%d",&Num);
	for(int i = 0; i < Num; i++){
		scanf("%d",&ta[i].sj);
		ta[i].xh = i + 1; 
	}
	for(int i = 0; i < Num; i++){
		scanf("%d",&ta[i].kf);
	}
	
	// 当前采用的是一个选择排序的方法 
	for(int i = 0; i < Num; i++){
		for(int j = i + 1; j < Num; j++){
			// 比较 若扣分情况相同的，则优先选择较快过期的那个 
			if(ta[i].kf == ta[j].kf){
				if(ta[i].sj > ta[j].sj){
					Ta temp = ta[i];
					ta[i] = ta[j];
					ta[j] = temp;
				}
			}
			else if(ta[i].kf < ta[i].kf){
				Ta temp = ta[i];
				ta[i] = ta[j];
				ta[j] = temp;
			}
		}
	}
	for(int i = 0; i < Num; i++){
		if(i + 1 > ta[i].sj){
			Sum += ta[i].kf; 
		}
	}
	for(int i = 0; i < Num; i++){
		printf("%d ",ta[i].xh);
	}
	printf("\n%d",Sum);	
	return 0;
} 
