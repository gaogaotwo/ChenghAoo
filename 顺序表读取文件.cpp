#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#define MAXSIZE 100

typedef struct Prize{
    char prizeArray[10];
    int money;
}pr;
typedef struct LNode *PtrToAdjVNode;
struct LNode{
    int last;				        //指向最后一个元素下标 
    pr *array;						//prize数组 
};
typedef PtrToAdjVNode List;

List MakeEmpty();    //程序初始化 
void fileWrite(List L);  // 文件写入 
void fileRead(List L);   // 文件读取
void Show(List L); 
FILE *fp, *fq, *fr;


int main()
{
    List L = MakeEmpty();
    fileRead(L);
    fileWrite(L); 
	Show(L);
    return 0;
}

List MakeEmpty(){
	List L;
	L=(List)malloc(sizeof(struct LNode));				//给指针分配内存 
    L->array=(pr*)malloc(sizeof(pr)*MAXSIZE);		    //给Prize数组分配空间 
    L->last=-1;						                    //此时还没有读取数据,即初始值指向-1 
	return L;
}
void fileRead(List L){
    /*读取文件过程*/ 
    fp = fopen("GameDateconfig.txt", "r");        //打开文件，并且把它设置为可写状态
    
    if(fp==NULL){                       //判断文件是否为空
        printf("读取配置信息失败!");
        getchar();getchar(); 
        return;
    }
    
    /*读取条件必须按照 scanf 里内容读取 且格式 内容必须依依对应，并且不能超过数组最大容量*/
    while(!feof(fp)&&L->last<MAXSIZE){			//feof() 函数的意思 就是 一直读取到文件 最后一个'/0' 
	    ++L->last;						        //添加数据 此时数组下标+1 
        fscanf(fp,"%[^:]:%d\n",			        //逐行的读取数据 
         L->array[L->last].prizeArray,
	 	&L->array[L->last].money);
     }
        fclose(fp);                  			//关闭文件
        printf("读取配置信息成功!");
        getchar();getchar();
}
void fileWrite(List L){
	    /*读取文件过程*/ 
    fp = fopen("GameData.txt", "r");        //打开文件，并且把它设置为可写状态
    fq = fopen("result.txt", "w");
    fr = fopen("resultw.txt", "w");
    if(fp==NULL){                       //判断文件是否为空
        printf("读取配置信息失败!");
        getchar();getchar(); 
        return;
    } 
    while(!feof(fp)){
	    char strDate[100];
	    char strPrize[100];
	    int prize = 0; // 默认中奖数值为 0 
	    fscanf(fp,"%s %s\n",
		    strDate,
		    strPrize
		);
		for(int i = 0; i < 40; i += 2){
		    char ndate[3];
		    char nprize[2];
		    strncpy(ndate, &strDate[i], 2);
		    strncpy(nprize, &strPrize[i / 2], 1);
		    ndate[2] = '\0';
		    nprize[1] = '\0';
		    // 中奖 1 倍
		    printf("%s %s读取\n", ndate, nprize);
		    if(strstr(ndate, "YQ") != NULL){
			    for(int j = 0; j <= L->last; j++){
				    if(strstr(nprize, L->array[j].prizeArray) != NULL){
					    prize += L->array[j].money;
					}
				}
			// 中奖 2 倍 
			}else if(strstr(ndate, "EQ") != NULL){
				for(int j = 0; j <= L->last; j++){
				    if(strstr(nprize, L->array[j].prizeArray) != NULL){
					    prize += (2 * L->array[j].money);
					}
				}
			// 中奖 3 倍 
			}else if(strstr(ndate, "SQ") != NULL){
				for(int j = 0; j <= L->last; j++){
				    if(strstr(nprize, L->array[j].prizeArray) != NULL){
					    prize += (3 * L->array[j].money);
					}
				}
			// 未中奖 
			}else{
			    prize += 0;
			}
		}
		if(prize != 0){
	    	fprintf(fq, "%s %s 中奖%d元\n",
		    	strDate,
		    	strPrize,
		    	prize
			);
		}else{
		    fprintf(fr, "%s %s 未中奖\n",
		    	strDate,
		    	strPrize
			);
		}		
	}
	fclose(fq);
	fclose(fp);
	fclose(fr);
	printf("存储信息成功!");
    getchar();getchar();  
}
void Show(List L)
{
    int i;
	for(i = 0; i <= L->last; i++){
		printf("%s:%d\n",
		L->array[i].prizeArray,
		L->array[i].money);
	}
}  
