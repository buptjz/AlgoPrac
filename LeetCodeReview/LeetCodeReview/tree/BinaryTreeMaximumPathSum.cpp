//
//  BinaryTreeMaximumPathSum.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-19.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_tree.h"

int maxVal = INT_MIN;

static int helper(TreeNode *root){
    if (root == NULL) return INT_MIN;
    int leftSingle = helper(root->left);
    int rightSingle = helper(root->right);
    
    
    int tmpBigWithoutRoot = max(leftSingle,rightSingle);
    int tmpBigWithRoot = root->val;
    if (leftSingle > 0) tmpBigWithRoot += leftSingle;
    if (rightSingle > 0) tmpBigWithRoot += rightSingle;

    int tmpBig = max(tmpBigWithRoot,tmpBigWithoutRoot);
    
    maxVal = max(maxVal,tmpBig);
    
    int bigger = leftSingle > rightSingle ? leftSingle : rightSingle;
    bigger = bigger > 0 ? bigger : 0;
    return root->val + bigger;
}

int maxPathSum(TreeNode *root) {
    helper(root);
    return maxVal;
}


