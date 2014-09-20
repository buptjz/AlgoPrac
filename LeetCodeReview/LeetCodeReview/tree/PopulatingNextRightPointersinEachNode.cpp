//
//  PopulatingNextRightPointersinEachNode.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-20.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_tree.h"


static void helper(TreeLinkNode *root){
    //base case
    if (root->left == NULL) return;
    
    root->left->next = root->right;
    if (root->next) root->right->next = root->next->left;
    helper(root->left);
    helper(root->right);
}

static void connect(TreeLinkNode *root) {
    if (root == NULL) return;
    helper(root);
}
