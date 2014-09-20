//
//  PathSum.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-20.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_backtrack.h"

/*determine if the tree has a root-to-leaf path such that adding up 
 all the values along the path equals the given sum.
 
 难点在于理题意！
 */

int total_sum = 0;
bool success = false;

static void backtrack(TreeNode *root,int cur_sum){
    cur_sum += root->val;
    if (!root->left && !root->right) {
        if (cur_sum  == total_sum) success = true;
        return;
    }
    
    if (root->left) backtrack(root->left, cur_sum);
    if (success) return;
    if (root->right) backtrack(root->right, cur_sum);
}

bool hasPathSum(TreeNode *root, int sum) {
    if (root == NULL) return false;
    total_sum = sum;
    backtrack(root, 0);
    return success;
}


