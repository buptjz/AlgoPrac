//
//  PathSum.cpp
//  LeetCode
//
//  Created by WangJZ on 3/9/14.
//  Copyright (c) 2014 WangJZ. All rights reserved.
//

#include "PathSum.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool hasPathSumHelper(TreeNode *root, int sum){
    //case(1) a leaf
    if (root ->left == NULL && root->right == NULL) {
        if (sum == root->val) {
            return true;
        }else{
            return false;
        }
    }
    //case(2) not a leaf
    if (root->left !=NULL && hasPathSumHelper(root->left,sum - root->val)) return true;
    if (root->right !=NULL && hasPathSumHelper(root->right,sum - root->val)) return true;
    return  false;
}

bool hasPathSum(TreeNode *root, int sum) {
    if (root == NULL) {
        return false;
    }
    return hasPathSumHelper(root,sum);
}