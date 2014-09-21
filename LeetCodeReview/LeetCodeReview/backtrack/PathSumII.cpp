//
//  PathSumII.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-21.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_backtrack.h"

int total_sum;
static void backtrack(vector<vector<int>> &result,TreeNode *root, int cur_sum,vector<int> &cur_vec){
    cur_sum += root->val;
    cur_vec.push_back(root->val);
    if (!root->left && !root->right) {
        if (cur_sum == total_sum) result.push_back(cur_vec);
    }
    if (root->left) backtrack(result, root->left, cur_sum, cur_vec);
    if (root->right) backtrack(result, root->right, cur_sum, cur_vec);
    
    cur_vec.pop_back();
}

vector<vector<int> > pathSum(TreeNode *root, int sum) {
    vector<vector<int>> result;
    if (root == NULL) return result;
    
    total_sum = sum;
    vector<int> cur;
    backtrack(result, root, 0, cur);
    return result;
}