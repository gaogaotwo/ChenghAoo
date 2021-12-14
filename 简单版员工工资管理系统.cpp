#include <stdio.h>
#include <stdlib.h> 
typedef struct Staff{
	char Name[21];	// Ա������ 
	int Salary;		// Ա������ 
} Sta[6];	//������6 ��Ա��

float Avg = 0.0; //Ա����ƽ������
int Sum = 0; // Ա���ܹ��Ĺ���

void menu();						//�˵� 
void Avg_salary(struct Staff*);		//����Ա��ƽ������ 
void Sum_salary(struct Staff*);		//����Ա���ܹ����� 
void Sort_salary(struct Staff*); 	//��Ա�����ʽ�������

/*
��һ�����ݣ�
���һ��ϵͳ��ͨ��ѡ��ͬ�Ĳ˵�������ɲ�ͬ�Ĺ��ܣ���ѡ��1��2��3�ֱ����Ա�����ʵ�ƽ�����ʺ��ܹ��ʡ��Թ��ʽ������������������ֽ������㡣
����1�����һ���˵�����menu( )����ʾ����ϵͳ���пɹ�ѡ��Ĺ�����Ϣ��
����2�����һ������������Ա����ƽ�����ʡ�
����3�����һ������������Ա�����ܹ��ʡ�
����4�����һ����������Ա�����ʽ�������
��������һ������main(  )�������������������4��������
*/ 
int main()
{
	// Ա�� ���� ���ʳ�ʼ������ 
    Sta S = {
		{"����Ӣ",5400},
		{"�ź�",6500},
		{"����",8500},
		{"������",5600},
		{"����",6700},
		{"��˫",8400}
	};
	int Pos;
	while(1){
		system("cls"); // ��������,��Ҫ�⺯��stdlib.h 
		menu();
		scanf("%d",&Pos); 
		switch(Pos){
			case 1:
				Avg_salary(S);
				break;
			case 2:
				Sum_salary(S);
				break;
			case 3:
				Sort_salary(S);
				break;
			case 4:
				printf("�˳�Ա������ϵͳ�ɹ���"); 
				return -1;
				break;
			default:
				printf("��������ȷ��ţ�");
				getchar();
				break; 
		}
	}
	 
    
    return 0;
}
void menu(){
	printf("\n\n\t\t\t��ӭ���� Ա������ϵͳ�������빦�����:\n");
	printf("\t\t\t1������Ա��ƽ������\n");
	printf("\t\t\t2������Ա���ܹ���\n");
	printf("\t\t\t3����Ա�����ʽ�������\n");
	printf("\t\t\t4���˳�ϵͳ\n"); 
}
void Avg_salary(struct Staff* S){
	
	//Ա��ƽ������ע���ʼ�� �� 
	Avg = 0.0;
	for(int i = 0; i < 6; i++){
		printf("Ա������:%s ���� %d Ԫ/�����\n",S[i].Name,S[i].Salary);
		Avg += S[i].Salary; 
	}
	printf("\n��ǰԱ��ƽ������Ϊ: %.2f Ԫ/�����",Avg / 6.0);
	getchar();getchar();  
}
void Sum_salary(struct Staff* S){
	//Ա�����幤��ע���ʼ�� �� 
	Sum = 0.0;
	for(int i = 0; i < 6; i++){
		printf("Ա������:%s ���� %d Ԫ/�����\n",S[i].Name,S[i].Salary);
		Sum += S[i].Salary; 
	}
	printf("\nԱ���ܹ�����Ϊ: %d Ԫ/�����",Sum);
	getchar();getchar(); 
}
void Sort_salary(struct Staff* S){
	// ��ǰ���õ���ѡ������ķ�����ÿ�α���ѡȡһ���� i ���ֵ��Ϊ����һ��֮���� 
	for(int i = 0; i < 6; i++){
		for(int j = i + 1; j < 6; j++){
			if(S[i].Salary < S[j].Salary){
				// ���� һ��Ҫע�⽻������ һ�����壡 
				struct Staff pos = S[i];
				S[i] = S[j];
				S[j] = pos;
			}
		}
	}
	printf("���ڹ�������֮��Ľ��(���չ����ɴ�С����)\n"); 
	for(int i = 0; i < 6; i++){
		printf("Ա������:%s ���� %d Ԫ/�����\n",S[i].Name,S[i].Salary);
	} 
	getchar();getchar(); 
}

