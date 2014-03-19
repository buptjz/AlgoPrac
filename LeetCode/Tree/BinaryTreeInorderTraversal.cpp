//
//  BinaryTreeInorderTraversal.cpp
//  Algorithms
//
//  Created by WangJZ on 14-3-19.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/binary-tree-inorder-traversal/


/*
 【注意】此题唯一需要注意的是英文单词  
 inorder == 中序
 preorder == 前序
 postorder == 后序
 */

#include "leetcode_tree.h"

void helper(vector<int> &a,TreeNode *root){
    if(root == NULL) return;
    helper(a,root->left);
    a.push_back(root->val);
    helper(a,root->right);
}
vector<int> inorderTraversal(TreeNode *root) {
    vector<int> v;
    if(root == NULL) return v;
    helper(v,root);
    return v;
}