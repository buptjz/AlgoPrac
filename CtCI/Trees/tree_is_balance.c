/*Implement a function to check if a binary tree is balanced.For the purpose
 * of this question,a balanced tree is defined to be a tree such that the
 * heights of the two subtrees of any node never differ by more than one.
 *¡¶CICT¡· P86
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


int check_height(struct TreeNode * TN){
	if(TN == NULL) return 0;
	int left_h,right_h;
	left_h = check_height(TN->left);
	if(left_h == -1) return -1;
	right_h = check_height(TN->right);
	if(right_h == -1) return -1;
	if(left_h-right_h > 1 || left_h - right_h < -1) return -1;
	else return 1+(left_h > right_h? left_h : right_h);
}

int is_balance(struct TreeNode *TN){
	int result;
	result = check_height(TN);
	if(result == -1) return 0;
	else return 1;
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
	int a[] = {5,3,7,1,4,6,8}; 
    root = insert(a[0],root);
	for(i = 1;i < 7;i++){
        insert(a[i],root);
	}
	inorder_treewalk(root);
	printf("%d",is_balance(root));
	
	return 1;
}
