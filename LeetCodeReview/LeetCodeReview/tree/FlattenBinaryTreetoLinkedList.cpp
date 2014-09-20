//
//  FlattenBinaryTreetoLinkedList.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-20.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  https://oj.leetcode.com/problems/flatten-binary-tree-to-linked-list/

//思路是后序遍历，遍历过程中，左侧指针指向末梢，把原来的做孩子塞到右孩子中间
// 有点ugly，回头看下别人咋写的

#include "leetcode_tree.h"

static void setNull(TreeNode *root){
    while (root != NULL) {
        root->left = NULL;
        root = root->right;
    }
}

static void helper(TreeNode *root){
    if (root->left) helper(root->left);
    if (root->right) helper(root->right);
    
    if (root->left && root->right) {
        TreeNode *leftEnd = root->left->left;
        TreeNode *rightEnd = root->right->left;
        leftEnd->right = root->right;
        root->right = root->left;
        root->left = rightEnd;
    }else if(root->right){
        TreeNode *rightEnd = root->right->left;
        root->left = rightEnd;
    }else if(root->left){
        TreeNode *leftEnd = root->left->left;
        root->right = root->left;
        root->left = leftEnd;
    }else{
        root->left = root;
    }
}

void flatten(TreeNode *root) {
    if (root == NULL) return;
    helper(root);
    setNull(root);
}
