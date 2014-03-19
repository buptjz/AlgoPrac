//
//  ValidateBinarySearchTree.cpp
//  Algorithms
//
//  Created by WangJZ on 14-3-19.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/validate-binary-search-tree/

/*
 判断一棵树是否是BST
 
 题目的基本思想是递归的去看一个节点的左右子树是否都是在正确的范围内，范围在每次递归的调用时候也会修改
 修改原则是：
 1）先查询本节点，如果本节点在范围内，跳转到步骤2
 2）修改上届，令上届等于根节点，查询左子树
 3）修改下届，令下届等于根节点，查询右子树
 
 【注意】此题涉及到初值设置的问题，在第一次调用的时候，是不知道上下界的，我这里用到的是整数最大和最小，其实意思就是没有上下界，也可以用一个bool变量来说明目前为止是否有了上届和下届
 */

#include "leetcode_tree.h"

bool isValid(TreeNode *root,int maxVal,int minVal){
    if(root == NULL) return true;
    if(root->val >=maxVal || root->val <= minVal) return false;
    return isValid(root->left,root->val,minVal) && isValid(root->right,maxVal,root->val);
}

bool isValidBST(TreeNode *root) {
    return isValid(root,(numeric_limits<int>::max)(),(numeric_limits<int>::min)());
}