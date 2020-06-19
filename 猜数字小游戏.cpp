#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	srand( (unsigned int)time(0));//初始化种子为随机值
	int i=0;
	int guess;
	int num = rand() % 10;//产生一一个0-9之间的数

for(;i <3;++i)
    {
    	printf("请输入一个数字,你还有%d次机会:\n",3-i);
         scanf("%d",&guess);
         if(guess>num)
         {
             printf("大了大了\n");
         }
         if(guess<num)
         {
             printf("小了小了\n");
         }
         if(guess==num)
         {
             printf("恭喜你猜对了！\n");
             break;				//假如说你前面两次输入正确了 要跳出for 
         }
    }
    printf("%d",i); 
    if(i==3&&guess!=num)		//判断两个条件 假如说3次都猜错了，并且此时 i==3 !! 并不是 4  
    {
        printf("\n你太笨了哟");
    }
 return 0;
}
