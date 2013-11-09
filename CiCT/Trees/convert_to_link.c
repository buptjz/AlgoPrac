/*
 *将二茬搜索树转换成排好序的二叉链表
 * 精选微软等数据结构+算法面试100题 No.1
1.把二元查找树转变成排序的双向链表
题目: 输入一棵二元查找树,将该二元查找树转换成一个排序的双向链表。 要求不能创建任何新的结点,只调整指针的指向。
	 10
  	 /\ 
	6 14 
   / \/ \
  4 8 12 16 
  转换成双向链表 4=6=8=10=12=14=16。
 
*/

#include "stdio.h"
#include <stdlib.h>

/*定义二叉查找树的数据结构*/
struct BSTreeNode{
    struct BSTreeNode *left;
    struct BSTreeNode *right;
    int key;
};

/*需要全局变量，pHead表示双链表的表头
因为不允许新建节点，表头就是第一个第一个节点
current指示当前双链表的最后一个节点*/
struct BSTreeNode *pHead,*currentIndex;

/*将一个新的节点加入到双链表中*/
void append_to_list(struct BSTreeNode *current){
	if(current == NULL) return;
	current->left = currentIndex;
	if(currentIndex == NULL){//第一次进入该函数
		pHead = current;//要设置pHead
	}else{
		currentIndex ->right = current;
	}
	currentIndex = current;
}

/*插入节点*/
struct BSTreeNode* insert(int key,struct BSTreeNode *T){
	if(T != NULL){
		if(key < T->key){
			T->left = insert(key,T->left);
 		}else{
			T->right = insert(key,T->right);
		}
	}else{
		struct BSTreeNode *new_node = malloc(sizeof(struct BSTreeNode));
		if (new_node == NULL){
			//FatalError("Out of space");
			printf("Out of space");
		}else{
			new_node->left = new_node->right = NULL;
			new_node->key = key;
            T = new_node;
		}
	}
	return T;
}

/*中序遍历*/
void inorder_treewalk(struct BSTreeNode *T){
	if (T != NULL){
		inorder_treewalk(T->left);
		printf("%d\n",T->key);
		append_to_list(T);
		inorder_treewalk(T->right);
	}
}

int main(){
	struct BSTreeNode *root = NULL;
    int a[] = {9,4,7,3,2,8,6,5,1};
	int i;
    root = insert(a[0],root);
	for(i = 1;i < 9;i++){
        insert(a[i],root);
	}
	pHead = NULL;
	currentIndex = NULL;
	inorder_treewalk(root);
	
	return 1;
}
