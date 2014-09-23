//
//  RecoverBinarySearchTree.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-23.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

//交换二叉搜索树的两个节点，相当于将一排排好顺序的数字交换两个，有两种情况:1)交换的是相邻的两个数字，2）交换的是不相邻的两个数字。

#include "leetcode_tree.h"

TreeNode *pre;
vector<TreeNode *>wrong;

void inorderTraverse(TreeNode *root){
    if (root == NULL) return;
    inorderTraverse(root->left);
    if (pre && (pre->val > root->val)) {
        wrong.push_back(pre);
        wrong.push_back(root);
    }
    pre = root;
    inorderTraverse(root->right);
}

void recoverTree(TreeNode *root) {
    pre = NULL;
    inorderTraverse(root);
    int len = (int)wrong.size();
    if (len == 0) return;
    if (len == 2) {
        int tmpVal = wrong[0]->val;
        wrong[0]->val = wrong[1]->val;
        wrong[1]->val = tmpVal;
    }
    if (len == 4) {
        int tmpVal = wrong[0]->val;
        wrong[0]->val = wrong[3]->val;
        wrong[3]->val = tmpVal;
    }
    return;
}

void testRecoverTree(){
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->right = new  TreeNode(1);
    recoverTree(root);
}


