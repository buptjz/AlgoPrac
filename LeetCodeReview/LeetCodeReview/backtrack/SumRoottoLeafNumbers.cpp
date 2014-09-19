//
//  SumRoottoLeafNumbers.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-19.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_backtrack.h"

int total = 0;

static void backtrack(TreeNode *root,int cur){
    int accum = cur * 10 + root->val;
    if (root->left == NULL && root->right == NULL) {
        total += accum;
        return;
    }
    
    if (root->left != NULL) backtrack(root->left, accum);
    if (root->right != NULL) backtrack(root->right, accum);
}

int sumNumbers(TreeNode *root) {
    int cur = 0;
    
    if (root == NULL) return 0;
    
    backtrack(root,cur);
    return total;
}

void testSumNumbers(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(3);
    int x = sumNumbers(root);
    cout<< x << endl;
}