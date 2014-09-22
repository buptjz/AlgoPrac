//
//  ValidateBinarySearchTree.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-22.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_tree.h"

static bool helper(TreeNode *root,int high,int low){
    if (root == NULL) return true;
    if (root->val <= low || root->val >= high) return false;
    return helper(root->left, root->val, low) && helper(root->right, high, root->val);
}

static bool isValidBST(TreeNode *root) {
    return helper(root, INT_MAX, INT_MIN);
}

