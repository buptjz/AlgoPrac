//
//  BinaryTreeInorderTraversal.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-15.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_tree.h"

static void helper(TreeNode*root, vector<int> &vec){
    if (root == NULL) return;
    helper(root->left, vec);
    vec.push_back(root->val);
    helper(root->right, vec);
    
}

vector<int> inorderTraversal(TreeNode *root) {
    vector<int> retVec;
    if (root == NULL) return retVec;
    helper(root,retVec);
    return retVec;
}
