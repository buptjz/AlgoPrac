//
//  SymmetricTree.cpp
//  LeetCode
//
//  Created by WangJZ on 3/10/14.
//  Copyright (c) 2014 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/symmetric-tree/

#include "leetcode_tree.h"

bool isSymmetricHelper(TreeNode *left,TreeNode *right) {
    if (!left && !right) {
        return true;
    }else if(!left || !right){
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