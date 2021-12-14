#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
/*
	����������ĳ��˾��40��Ա��������������ţ�����Ҫ���Ա�����ʽ��л��ܡ�Ҫ���̼��㣺
		1.ͳ��һ������Ա�����ܹ��ʼ�ƽ�����ʣ�
		2.ͳ��Ա��������ʵ��ܹ��ʼ�ƽ�����ʣ�
		3.����������Ա�����ʵ���
����������Ҫ��
��һ�����ݣ����ú��������֪ʶ����������Ա�����ʽ��л��ܡ�
������Ҫ�󣺹��̺����Ķ��塢������Ƕ�׵�����ݹ���õ��й�֪ʶ��
*/
typedef struct Staff{
	char Name[21];			// Ա������ 
	int Salary[3];			// Ա������	��Ϊ������ 3 �����͹���
	float Avg_salay;    	// Ա����ƽ������
	char department[20]; 	// Ա���������� 
} Sta[40];			//������ 40 ��Ա��

void Sector_wages();  //ͳ��һ������Ա�����ܹ��ʼ�ƽ�����ʣ�
void Employee_wages(struct Staff*); //ͳ��Ա��������ʵ��ܹ��ʼ�ƽ�����ʣ�
//���ÿ�������ķ��������Σ��ݹ���� 
int Pos(struct Staff*,int L,int R);
void Salay_Sort(struct Staff*,int L,int R);
// ����������幤��,�������� 
int Sum_a = 0, Alen = 0;
int Sum_b = 0, Blen = 0;
int Sum_c = 0, Clen = 0;
int Sum_d = 0, Dlen = 0;
int Sum_e = 0, Elen = 0;  
/*
	������5 �����ţ��ֱ�Ϊ A B C D E���ܼ�40���� 
	���� 2100 4200 3200 A
	ƤƤ 2130 4202 4204 A
	��� 2104 3421 5220 A
	���� 4104 3222 8220 A
	��ǿ 3104 3221 6220 A
	���� 3106 3441 2220 A
	���� 2104 3222 8220 A
	���� 1204 1231 6220 A
	���� 2100 4200 3200 B
	��Ƥ 2120 4202 4204 B
	���� 2134 3421 7220 B
	���� 4114 3222 8220 B
	��ǿ 3224 2221 6223 B
	���� 2434 1421 7222 B
	��Ƥ 4514 3222 8221 B
	���� 3624 2221 6225 B
	���� 2124 4221 3227 C
	��Ƥ 4120 4232 2234 C
	���� 5134 3421 1222 C
	���� 4614 3222 8322 C
	��ǿ 6122 3371 6221 C
	���� 2134 3421 7242 C
	���� 4614 3522 8272 C
	���� 2124 3271 6221 C
	���� 3100 4203 3200 D
	��Ƥ 4120 4202 4204 D
	���� 5134 3421 7220 D
	���� 6114 3232 8221 D
	��ǿ 6124 3223 6223 D
	���� 3124 3421 6210 D
	���� 3112 3232 5221 D
	���� 2124 3231 1233 D
	���� 3106 6200 3270 E
	��Ƥ 2124 2202 4224 E
	��� 2131 7421 7220 E
	���� 4123 4222 8260 E
	��ǿ 7129 2221 6271 E
	���� 2132 7441 7223 E
	��� 9313 4222 8262 E
	���� 2129 2221 6274 E
*/ 
int main()
{
	Sta s;	//Ա����Ϣ��ʼ�� ���� +  ������ 3 �����͹��ɹ��� + Ա����������
	for(int i = 0; i < 40; i++){
		printf("������� %d λԱ��������������ʹ��� �������ŷֱ�Ϊ:\n",i+1); 
		scanf("%s %d %d %d %s",s[i].Name,&s[i].Salary[0],&s[i].Salary[1],&s[i].Salary[2],s[i].department);
		s[i].Avg_salay = (s[i].Salary[0] + s[i].Salary[1] + s[i].Salary[2]) / 3.0;
		// strcmp �ַ����ȽϺ�����������ⷵ��ֵΪ0 
		if(strcmp(s[i].department,"A") == 0){
			Alen++;
			Sum_a += (s[i].Salary[0] + s[i].Salary[1] + s[i].Salary[2]);
		}
		else if(strcmp(s[i].department,"B") == 0){
			Blen++;
			Sum_b += (s[i].Salary[0] + s[i].Salary[1] + s[i].Salary[2]);
		} 
		else if(strcmp(s[i].department,"C") == 0){
			Clen++;
			Sum_c += (s[i].Salary[0] + s[i].Salary[1] + s[i].Salary[2]);
		} 
		else if(strcmp(s[i].department,"D") == 0){
			Dlen++;
			Sum_d += (s[i].Salary[0] + s[i].Salary[1] + s[i].Salary[2]);
		}
		else if(strcmp(s[i].department,"E") == 0){
			Elen++;
			Sum_e += (s[i].Salary[0] + s[i].Salary[1] + s[i].Salary[2]);
		}   
	}
	Sector_wages();
	Employee_wages(s);
	Salay_Sort(s,0,39);
	
	printf("\n A ����Ա�� ���ʵ�������Ϊ: \n");
	for(int i = 0; i < 40; i++){
		if(strcmp(s[i].department,"A") == 0){
			printf("����: %s �������: %d Ԫ/����� %d Ԫ/����� %d Ԫ/����� ���幤��: %d Ԫ/����� ƽ������: %.2f Ԫ�����\n",
			s[i].Name,s[i].Salary[0],s[i].Salary[1],s[i].Salary[2],
			(s[i].Salary[0] + s[i].Salary[1] + s[i].Salary[2]),(s[i].Salary[0] + s[i].Salary[1] + s[i].Salary[2])/3.0);		
		}
	}
	printf("\n B ����Ա�� ���ʵ�������Ϊ: \n");
	for(int i = 0; i < 40; i++){
		if(strcmp(s[i].department,"B") == 0){
			printf("����: %s �������: %d Ԫ/����� %d Ԫ/����� %d Ԫ/����� ���幤��: %d Ԫ/����� ƽ������: %.2f Ԫ�����\n",
			s[i].Name,s[i].Salary[0],s[i].Salary[1],s[i].Salary[2],
			(s[i].Salary[0] + s[i].Salary[1] + s[i].Salary[2]),(s[i].Salary[0] + s[i].Salary[1] + s[i].Salary[2])/3.0);		
		}
	}
	printf("\n C ����Ա�� ���ʵ�������Ϊ: \n");
	for(int i = 0; i < 40; i++){
		if(strcmp(s[i].department,"C") == 0){
			printf("����: %s �������: %d Ԫ/����� %d Ԫ/����� %d Ԫ/����� ���幤��: %d Ԫ/����� ƽ������: %.2f Ԫ�����\n",
			s[i].Name,s[i].Salary[0],s[i].Salary[1],s[i].Salary[2],
			(s[i].Salary[0] + s[i].Salary[1] + s[i].Salary[2]),(s[i].Salary[0] + s[i].Salary[1] + s[i].Salary[2])/3.0);		
		}
	}
	printf("\n D ����Ա�� ���ʵ�������Ϊ: \n");
	for(int i = 0; i < 40; i++){
		if(strcmp(s[i].department,"D") == 0){
			printf("����: %s �������: %d Ԫ/����� %d Ԫ/����� %d Ԫ/����� ���幤��: %d Ԫ/����� ƽ������: %.2f Ԫ�����\n",
			s[i].Name,s[i].Salary[0],s[i].Salary[1],s[i].Salary[2],
			(s[i].Salary[0] + s[i].Salary[1] + s[i].Salary[2]),(s[i].Salary[0] + s[i].Salary[1] + s[i].Salary[2])/3.0);		
		}
	}
	printf("\n E ����Ա�� ���ʵ�������Ϊ: \n");
	for(int i = 0; i < 40; i++){
		if(strcmp(s[i].department,"E") == 0){
			printf("����: %s �������: %d Ԫ/����� %d Ԫ/����� %d Ԫ/����� ���幤��: %d Ԫ/����� ƽ������: %.2f Ԫ�����\n",
			s[i].Name,s[i].Salary[0],s[i].Salary[1],s[i].Salary[2],
			(s[i].Salary[0] + s[i].Salary[1] + s[i].Salary[2]),(s[i].Salary[0] + s[i].Salary[1] + s[i].Salary[2])/3.0);		
		}
	}
    return 0;
}
void Sector_wages(){
	//���ÿ�����Ź���״�� 
		printf("\n\n\n��ǰ %c ���� Ա���ܹ���Ϊ: %d Ԫ/����� ƽ������Ϊ: %.2f Ԫ/�����\n",'A',Sum_a,Sum_a / (Alen * 1.0));
		printf("��ǰ %c ���� Ա���ܹ���Ϊ: %d Ԫ/����� ƽ������Ϊ: %.2f Ԫ/�����\n",'B',Sum_b,Sum_b / (Blen * 1.0));
		printf("��ǰ %c ���� Ա���ܹ���Ϊ: %d Ԫ/����� ƽ������Ϊ: %.2f Ԫ/�����\n",'C',Sum_c,Sum_c / (Clen * 1.0));
		printf("��ǰ %c ���� Ա���ܹ���Ϊ: %d Ԫ/����� ƽ������Ϊ: %.2f Ԫ/�����\n",'D',Sum_d,Sum_d / (Dlen * 1.0));
		printf("��ǰ %c ���� Ա���ܹ���Ϊ: %d Ԫ/����� ƽ������Ϊ: %.2f Ԫ/�����\n\n\n",'E',Sum_e,Sum_e / (Elen * 1.0));
}
void Employee_wages(struct Staff* s){
	for(int i = 0; i < 40; i++){
		printf("����: %s �������: %d Ԫ/����� %d Ԫ/����� %d Ԫ/����� ƽ������Ϊ: %.2f ����: %s\n",s[i].Name,s[i].Salary[0],s[i].Salary[1],s[i].Salary[2],s[i].Avg_salay,s[i].department);
	}
}
int Pos(struct Staff* s,int L,int R){
	struct Staff tep = s[L];
	while(L < R){
		while(L < R && s[R].Avg_salay >= tep.Avg_salay){
			R--;
		}
		s[L] = s[R];
		while(L < R && s[L].Avg_salay <= tep.Avg_salay){
			L++;
		}
		s[R] = s[L];
	}
	s[L] = tep;
	return L; 
}
void Salay_Sort(struct Staff* s,int L,int R){
	// �������� ͳһ�ӿ� �ݹ飬Ƕ�׵��� ��ÿ��������÷��εķ��� 
	if(L < R){
		int pos = Pos(s,L,R);
		Salay_Sort(s,L,pos-1);
		Salay_Sort(s,pos+1,R);	
	}
}

