//
//  BalancedBinaryTree.cpp
//  LeetCode
//
//  Created by WangJZ on 3/10/14.
//  Copyright (c) 2014 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/balanced-binary-tree/

#include "leetcode_tree.h"


bool isBalancedHelper(TreeNode *root,int &height) {
    if (root == NULL) {
        height = 0;
        return true;
    }
    int leftHeight,rightHeight;
    if (!isBalancedHelper(root->left,leftHeight)) return false;
    if (!isBalancedHelper(root->right,rightHeight)) return false;
    if (leftHeight - rightHeight > 1 || leftHeight - rightHeight < -1) return false;
    height = max(leftHeight,rightHeight) + 1;
    return true;
}
bool isBalanced(TreeNode *root) {
    int height = 0;
    return isBalancedHelper(root,height);
}

void testIsBalance(){
    TreeNode *root = new TreeNode(5);
    TreeNode *left = new TreeNode(5);
    TreeNode *right = new TreeNode(5);
    TreeNode *leftright = new TreeNode(5);
    TreeNode *leftrightright = new TreeNode(5);
    root->left = left;
    root->right = right;
    left->right = leftright;
    left->right->right = leftrightright;
    bool res = isBalanced(root);
    printf("Finished %d\n",res);
}