//
//  SumRoottoLeafNumbers.cpp
//  Algorithms
//
//  Created by WangJZ on 14-3-31.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_tree.h"


static int total;
void sumNumbersHelper(TreeNode *root,int cur){
    if (!root->left && !root->right) {
        total += cur;
        return;
    }
    if (root->left) sumNumbersHelper(root->left, cur*10+root->left->val);
    if (root->right) sumNumbersHelper(root->right, cur*10+root->right->val);
}

int sumNumbers(TreeNode *root) {
    total = 0;
    if (!root) return 0;
    sumNumbersHelper(root, root->val);
    return total;
}
