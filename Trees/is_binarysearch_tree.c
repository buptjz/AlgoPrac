/*Implement a function to check if a binary tree is a binary search tree.
 *¡¶CICT¡· P86-4.5
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

int check_order(int key){
	static int last = -1;
	if(last > key) return -1;
	last = key;
	return 1;
}

int is_binary_search_tree(struct TreeNode *TN){
	if(TN == NULL) return 1;
	int result;
	result = is_binary_search_tree(TN->left);
	if (result == -1) return -1;
	result = check_order(TN->key);
	if (result == -1) return -1;
	result = is_binary_search_tree(TN->right);
	if (result == -1) return -1;
	return 1;
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
	int i,ibst;
    root = insert(1,root);
	for(i = 2;i < 10;i++){
        insert(i,root);
	}
	inorder_treewalk(root);
	ibst = is_binary_search_tree(root);
	printf("This is a binary search tree [%d]",ibst);
	return 1;
}

