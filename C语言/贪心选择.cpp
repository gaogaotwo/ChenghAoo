#include <bits/stdc++.h>
typedef struct task{
	int xh;	//��ҵ��� 
	int sj;	//��ҵ ������ʱ��	
	int kf;	//��ҵ ���ڿ۷� 
}Ta;
/*
3
1 3 1
6 2 3
*/
int Num;	//��ʾ��ҵ���� 
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
	
	// ��ǰ���õ���һ��ѡ������ķ��� 
	for(int i = 0; i < Num; i++){
		for(int j = i + 1; j < Num; j++){
			// �Ƚ� ���۷������ͬ�ģ�������ѡ��Ͽ���ڵ��Ǹ� 
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
