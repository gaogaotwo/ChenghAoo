/*洗牌 
	4 个人 随机发牌
	4种花色
	2 - A
	按顺序发牌
	每人 13 张 
*/ 
#include<bits/stdc++.h>
#include<windows.h>
typedef struct card{
	
	char color[10];
	char value[10];
	int Pos;		// 表示1 - 52 
	int status;		// 表示状态 当前牌是否已取  0 表示还为取 1 表示已取
	int people; 
}poker[52];
void init(struct card*);
void Lice(struct card*);
void Print(struct card*); 
int main(){
	int pos;
	poker p;
	while(true){
		init(p);		// 初始化操作
		Lice(p);
		system("cls");
		printf("\n\n\t\t\t\t洗牌 1:洗牌 0:退出:\n\t\t\t\t"); 
		scanf("%d",&pos);
		switch(pos){
		case 1:
			Print(p);
			break;
		case 0:
			exit(0);
		}
		
	}
	return 0;
}
void init(struct card* p){
	
	for(int i = 0; i < 52; i++){
		p[i].status = 0;
		p[i].Pos = i + 1;	
		int colors = i % 4;
		if(colors == 0)  strcpy(p[i].color," ★");
		else if(colors == 1)  strcpy(p[i].color," ■");
		else if(colors == 2)  strcpy(p[i].color," ◆");
		else strcpy(p[i].color," ●");
	}
	for(int i = 0; i < 4; i++){
		strcpy(p[i].value,"A");
	}
	for(int i = 4; i < 8; i++){
		strcpy(p[i].value,"2");
	}
	for(int i = 8; i < 12; i++){
		strcpy(p[i].value,"3");
	}
	for(int i = 12; i < 16; i++){
		strcpy(p[i].value,"4");
	}
	for(int i = 16; i < 20; i++){
		strcpy(p[i].value,"5");
	}
	for(int i = 20; i < 24; i++){
		strcpy(p[i].value,"6");
	}
	for(int i = 24; i < 28; i++){
		strcpy(p[i].value,"7");
	}
	for(int i = 28; i < 32; i++){
		strcpy(p[i].value,"8");
	}
	for(int i = 32; i < 36; i++){
		strcpy(p[i].value,"9");
	}
	for(int i = 36; i < 40; i++){
		strcpy(p[i].value,"10");
	}
	for(int i = 40; i < 44; i++){
		strcpy(p[i].value,"J");
	}
	for(int i = 44; i < 48; i++){
		strcpy(p[i].value,"Q");
	}
	for(int i = 48; i < 52; i++){
		strcpy(p[i].value,"K");
	}
}
void Lice(struct card* p){
	int pos = 0; 
	srand((unsigned)time(NULL));
	for(int j = 0; j < 4; j++){
		for(int i = 0; i < 13; i++){
			while(true){
				pos++;
				int top = rand() % 52;
				if(p[top].status == 0){
					p[top].status = 1;
					p[top].people = j;
					break;
				}
			}
		}
	}
	printf("随机次数:%d",pos);
	getchar();
}
void Print(struct card* p){
	printf("选手A\n"); 
	for(int i = 0; i < 52; i++){
		if(p[i].people == 0){
			Sleep(100);
			printf("%5s",p[i].color);
		}
	}
	printf("\n");
	for(int i = 0; i < 52; i++){
		if(p[i].people == 0){
			Sleep(100); 
			printf("%5s",p[i].value);
		}
	}
	
	printf("\n选手B\n"); 
	for(int i = 0; i < 52; i++){
		if(p[i].people == 1){
			Sleep(50); 
			printf("%5s",p[i].color);
		}
	}
	printf("\n");
	for(int i = 0; i < 52; i++){
		if(p[i].people == 1){
			Sleep(50); 
			printf("%5s",p[i].value);
		}
	}
	printf("\n选手C\n"); 
	for(int i = 0; i < 52; i++){
		if(p[i].people == 2){
			Sleep(25); 
			printf("%5s",p[i].color);
		}
	}
	printf("\n");
	for(int i = 0; i < 52; i++){
		if(p[i].people == 2){
			Sleep(25); 
			printf("%5s",p[i].value);
		}
	}
	printf("\n选手D\n"); 
	for(int i = 0; i < 52; i++){
		if(p[i].people == 3){
			Sleep(10); 
			printf("%5s",p[i].color);
		}
	}
	printf("\n");
	for(int i = 0; i < 52; i++){
		if(p[i].people == 3){
			Sleep(10); 
			printf("%5s",p[i].value);
		}
	}
	printf("\n\n\n\n任意键返回....");
	getchar();getchar();
} 
