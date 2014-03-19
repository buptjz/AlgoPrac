//
//  MaximumDepthofBinaryTree.cpp
//  Algorithms
//
//  Created by WangJZ on 14-3-19.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_tree.h"

int maxDepth(TreeNode *root) {
    if(root == NULL) return 0;
    return 1+max(maxDepth(root->left),maxDepth(root->right));
}