/*《数据结构与算法分析-c语言描述版》
 *二叉查找树
 *中序号遍历
 * */

#include "stdio.h"
#include <stdlib.h>


struct TreeNode{
    struct TreeNode *left;
    struct TreeNode *right;
    int key;
};

struct TreeNode* make_empty(struct TreeNode * T){
	if(T != NULL){
		make_empty(T->left);
		make_empty(T->right);
		free(T);
	}
	return NULL;
}

struct TreeNode* insert(int key,struct TreeNode *T){
	if(T != NULL){
		if(key < T->key){
			T->left = insert(key,T->left);
		}else{
			T->right = insert(key,T->right);
		}
	}else{
		struct TreeNode *new_node = malloc(sizeof(struct TreeNode));
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

void inorder_treewalk(struct TreeNode *T){
	if (T != NULL){
		inorder_treewalk(T->left);
		printf("%d\n",T->key);
		inorder_treewalk(T->right);
	}
}

int main(){
	struct TreeNode *root = NULL;
	int i;
    root = insert(1,root);
	for(i = 2;i < 10;i++){
        insert(i,root);
	}
	inorder_treewalk(root);
	
	return 1;
}

