//
//  ConvertSortedArraytoBinarySearchTree.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-21.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  https://oj.leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

#include "leetcode_tree.h"

TreeNode *helper(const vector<int> &num,int start,int end){
    if (start > end) return NULL;
    int mid = (start + end) / 2;
    TreeNode *retNode = new TreeNode(num[mid]);
    retNode->left = helper(num, start, mid -1);
    retNode->right = helper(num, mid + 1, end);
    return retNode;
}

TreeNode *sortedArrayToBST(vector<int> &num) {
    int end = (int)num.size() -1;
    return helper(num, 0, end);
}
