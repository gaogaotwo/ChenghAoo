/*Hash表，采用数组实现*/ 
#include<stdio.h>
#define DataType int
#define M 15
 
typedef struct HashNode    
{
    DataType data;    //存储值 
    int isNull;           //标志该位置是否已被填充 
}HashTable;

HashTable hashTable[M];
void initHashTable()     //对hash表进行初始化 
{
    int i;
    for(i = 0; i<M; i++)
    {
        hashTable[i].isNull = 1;    //初始状态为空 
    }
}
int getHashAddress(DataType key)    //Hash函数 
{
    return key % 14;     //Hash函数为 key%29 
}
int insert(DataType key)    //向hash表中插入元素 
{
    int address = getHashAddress(key);       
    if(hashTable[address].isNull == 1)  //没有发生冲突 
    {
        hashTable[address].data = key;
        hashTable[address].isNull = 0;
    }
    else    //当发生冲突的时候 
    {
        while(hashTable[address].isNull == 0 && address<M)
        {
            address++;     //采用线性探测法，步长为1 
        }
        if(address == M)    //Hash表发生溢出 
            return -1;
        hashTable[address].data = key;
        hashTable[address].isNull = 0;
    }
    return 0;
}
int find(DataType key)      //进行查找 
{
    int address = getHashAddress(key);
    while( !(hashTable[address].isNull == 0 && hashTable[address].data == key && address<M))
    {
        address++;
    } 
    if( address == M)
        address = -1;
    return address;
}
int main(int argc, char *argv[])
{
    int key[]={1,2,3,4,5,6,7,8,10,15,11,12,13,14,15};
    int i;
    initHashTable();
    for(i = 0; i<15; i++)
    {
        insert(key[i]);
    }
    
    for(i = 0; i<15; i++)
    {
        int address;
        address = find(key[i]);
        printf("%d %d\n", key[i],address);
    }
    return 0;
}
