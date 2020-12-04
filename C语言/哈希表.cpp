#include<stdio.h>
#include<string.h>
struct Entry{
	char data;	// value值 
	int count;	// 出现的次数 
};
void addOne(struct Entry *CountMap,char Num,int HashTableSize);			//Add Num
void FindHand(struct Entry *CountMap,char Value,int HashTableSize); 		//Find Num 
int Collision_Count=0; 	//碰撞 次数 
int main(){

	int HashTableSize = 10;    				//假设有10个空位子 	当然的你可以根据实际情况修改 
	struct Entry CountMap[HashTableSize];   //Map 
	for(int i=0;i<HashTableSize;i++){
		CountMap[i].count=0;				//20个位置 初始化次数都为 0
		CountMap[i].data =NULL;	
	}
	char a[]="gaogaotwo"; 					

	for(int i=0;i<strlen(a);i++){	
		addOne(CountMap,a[i],HashTableSize);	
	}
	
	for(int i=0;i<HashTableSize;i++){	//printf  
		printf("Data:%c Count:%d \n",CountMap[i].data,CountMap[i].count);
	}
	
	FindHand(CountMap,'o',HashTableSize);
//	printf("碰撞次数:%d",Collision_Count); 
	return 0;
}
void addOne(struct Entry *CountMap,char Num,int HashTableSize){	// 三个参数 第一个 Map字典  第二个 value值  第三个HashSize大小 

	int Hash = (Num % HashTableSize + HashTableSize) % HashTableSize;  // Key % 
	while(true){				  //总共有 3种可能性 					开放寻址法
		if(CountMap[Hash].count==0){ 	//第一种     表示此时这个位置"没有元素" 直接放置 	
		   CountMap[Hash].data = Num;	// 赋值 
		   CountMap[Hash].count = 1;	//次数为 1    
		   return;
		}								//第二种    表示该位置有元素 且元素值相等情况 
		if(CountMap[Hash].data==Num){
		   CountMap[Hash].count++;		//  元素出现次数 + 1
		   return; 
		}
										//第三种 否则就是该位置已被占据(冲突了)，且元素值不相等，就继续查询下一个位置一直到找到为准  
		Hash=(Hash+1)%HashTableSize;    //线性 探测  
//		Collision_Count++;				//计算碰撞次数    
	} 
}
void FindHand(struct Entry *CountMap,char Value,int HashTableSize){

	int Hash = (Value % HashTableSize + HashTableSize) % HashTableSize;	 //Key
	
	
	if(CountMap[Hash].data==Value){					//是否 是没有发生冲突的数 
		printf("id:%d 查询成功\n",Hash);
		return;
	}
	
	int temp = Hash+1;
	
	while(temp!=Hash){
		if(CountMap[temp].data==Value){
		printf("id:%d %d 查询成功\n",temp,Value);
		return;
		}
		temp=(temp+1)%HashTableSize;													
	}
	printf("查询失败\n");
	return;
} 
