//
//  SameTree.cpp
//  Algorithms
//
//  Created by WangJZ on 14-3-19.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/same-tree/

#include "leetcode_tree.h"

bool isSameTree(TreeNode *p, TreeNode *q) {
    if(p == NULL && q == NULL) return true;
    else if(p == NULL || q == NULL) {
        return false;
    }else{
        if(p->val != q->val) {
            return false;
        }else{
            return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        }
    }
}
