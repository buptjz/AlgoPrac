//
//  SymmetricTree.cpp
//  LeetCode
//
//  Created by WangJZ on 3/10/14.
//  Copyright (c) 2014 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/symmetric-tree/

#include "SymmetricTree.h"

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSymmetricHelper(TreeNode *left,TreeNode *right) {
    if (left == NULL && right == NULL) {
        return true;
    }else if(left == NULL){
        return false;
    }else if(right == NULL){
        return false;
    }else{
        if (left->val != right->val) {
            return false;
        }else{
            return isSymmetricHelper(left->right, right->left) && isSymmetricHelper(left->left, right->right);
        }
    }
}

bool isSymmetric(TreeNode *root) {
    if (root == NULL) {
        return true;
    }else{
        return isSymmetricHelper(root->left, root->right);
    }
}