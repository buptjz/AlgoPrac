//
//  MinimumDepthofBinaryTree.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-21.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_tree.h"


int helper(TreeNode *root){
    if (!root->left && !root->right) {
        return 1;
    }else if (root->right && root->left) {
        int left = helper(root->left);
        int right = helper(root->right);
        return 1 + min(left,right);
    }else if(root->left){
        return 1 + helper(root->left);
    }else{
        return 1 + helper(root->right);
    }
}

int minDepth(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    return helper(root);
}