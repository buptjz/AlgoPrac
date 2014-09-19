//
//  SameTree.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-19.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  https://oj.leetcode.com/problems/same-tree/

//奇虎360 面试题 用非递归的方法
#include "leetcode_tree.h"

bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == NULL && q == NULL) return true;
    stack<TreeNode *> st1,st2;
    st1.push(p);
    st2.push(q);
    while (!st1.empty()) {
        p = st1.top();
        q = st2.top();
        st1.pop();
        st2.pop();
        if (p == NULL && q == NULL) {
            continue;
        }
        
        if ((p == NULL && q != NULL)
            || (q == NULL && p != NULL)
                || (p->val != q->val)) {
            return false;
        }

        st1.push(p->left);
        st1.push(p->right);
        st2.push(q->left);
        st2.push(q->right);

    }
    return true;
}
