//
//  BinaryTreePostorderTraversal.cpp
//  LeetCode
//
//  Created by WangJZ on 14-3-11.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/binary-tree-postorder-traversal/

#include "leetcode_tree.h"

void postorderTraversalHelper(TreeNode *root,vector<int> &retVec){
    if (root == NULL) {
        return;
    }
    postorderTraversalHelper(root->left, retVec);
    postorderTraversalHelper(root->right,retVec);
    retVec.push_back(root->val);
    
}
vector<int> postorderTraversal(TreeNode *root) {
    vector<int> retVec;
    postorderTraversalHelper(root, retVec);
    return retVec;
}

void testPostorderTraversal(){
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
    vector<int> res = postorderTraversal(root);
    printf("Finished");
}