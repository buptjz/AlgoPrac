//
//  MaximumDepthofBinaryTree.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-21.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_tree.h"

static int helper(TreeNode *root){
    if (!root->left && !root->right) return 1;
    else if(root->left && root->right){
        int leftDepth = helper(root->left);
        int rightDepth = helper(root->right);
        return max(leftDepth,rightDepth) + 1;
    }else if(root->left){
        return helper(root->left) + 1;
    }else {
        return helper(root->right) + 1;
    }
}

int maxDepth(TreeNode *root) {
    if(root == NULL) return 0;
    return helper(root);
}
