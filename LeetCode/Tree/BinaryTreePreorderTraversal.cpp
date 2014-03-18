//
//  BinaryTreePreorderTraversal.cpp
//  LeetCode
//
//  Created by WangJZ on 14-3-11.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/binary-tree-preorder-traversal/

#include "leetcode_tree.h"

void preorderTraversalHelper(TreeNode *root,vector<int> &retVec){
    if (root == NULL) {
        return;
    }
    retVec.push_back(root->val);
    preorderTraversalHelper(root->left, retVec);
    preorderTraversalHelper(root->right,retVec);
    
}
vector<int> preorderTraversal(TreeNode *root) {
    vector<int> retVec;
    preorderTraversalHelper(root, retVec);
    return retVec;
}

void testPreorderTraversal(){
    TreeNode *root = new TreeNode(0);
    TreeNode *l = new TreeNode(1);
    TreeNode *r = new TreeNode(2);
    TreeNode *ll = new TreeNode(3);
    TreeNode *lr = new TreeNode(4);
    TreeNode *lrr = new TreeNode(5);
    root->left = l;
    root->right = r;
    l->right = lr;
    l->right->right = lrr;
    l->left = ll;
    vector<int> res = preorderTraversal(root);
    printf("Finished");
}