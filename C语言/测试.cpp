#include<stdio.h>
#include<stdlib.h>
typedef struct Tree *ptrToAdjVNode;
struct Tree{
	char data;
	struct Tree *Left,*right;
};
typedef ptrToAdjVNode BinaryTree;

void CreatBinaryTree(BinaryTree &T);
void preorderTraversaL(BinaryTree T);
void InorderTraversaL(BinaryTree T);
void PostorderTraversaL(BinaryTree T);
int main(){
	BinaryTree T;
	
	CreatBinaryTree(T);
	printf("\n");
	preorderTraversaL(T);
	printf("\n");1
	InorderTraversaL(T);
	printf("\n");
	PostorderTraversaL(T);
	return 0;
}
void CreatBinaryTree(BinaryTree &T){

	char pos;
	scanf("%c",&pos);
	if(pos=='#')
		T=NULL;
	else{
		T=(BinaryTree)malloc(sizeof(Tree));
		T->data=pos;
		CreatBinaryTree(T->Left);
		CreatBinaryTree(T->right);
	}
}
void preorderTraversaL(BinaryTree T){

	if(T){
		printf("%2c",T->data);
		preorderTraversaL(T->Left);
		preorderTraversaL(T->right);
	}
}
void InorderTraversaL(BinaryTree T){
	if(T){
		InorderTraversaL(T->Left);
		printf("%2c",T->data);
		InorderTraversaL(T->right);
	}
}
void PostorderTraversaL(BinaryTree T){
	if(T){
		PostorderTraversaL(T->Left);
		PostorderTraversaL(T->right);
		printf("%2c",T->data);
	}
}
