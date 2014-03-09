//
//  BinaryTreeMaximumPathSum.cpp
//  LeetCode
//
//  Created by WangJZ on 3/9/14.
//  Copyright (c) 2014 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/binary-tree-maximum-path-sum/


/*
 递归set value
1）本节点可用时候的最大值（包含左节点&&只包含一支）
2）本节点不可用时候的最大值（不包含左节点||左节点作为最高节点||包含左节点）
 上述第二点的第三个条件不好想到，其实意思是在左节点仍然可用的情况下，不用左节点
 我们的前提假设 cannotUse >= canUse
3） 递归返回的是当前最大的sum
 */
#include "BinaryTreeMaximumPathSum.h"
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxPathSumHelper(TreeNode *root,int &canUse,int &cannotUse) {
    int leftCanUse,rightCanUse;//左单最大值，右单最大值
    int leftCannotUse,rightCannotUse;
    int leftMax,rightMax;
    if (root == NULL) {
        canUse = -1000;
        cannotUse = -1000;
        return -1000;
    }
    leftMax = maxPathSumHelper(root->left,leftCanUse,leftCannotUse);
    rightMax = maxPathSumHelper(root->right,rightCanUse,rightCannotUse);
    int larger = max(leftCanUse,rightCanUse);
    canUse = larger > 0 ? root->val+larger : root->val;
    cannotUse = max(max(leftCannotUse,rightCannotUse),max(leftCanUse+rightCanUse+root->val,canUse));
    return max(cannotUse,canUse);
    
}

int maxPathSum(TreeNode *root) {
    int canUse,cannotUse;
    if (root ->left == NULL && root->right == NULL) {
        return root->val;
    }
    return maxPathSumHelper(root,canUse,cannotUse);
}

void testMaxPathSum(){
    TreeNode *a = new TreeNode(-1);
    TreeNode *b = new TreeNode(-3);
    a->left = b;
    int res = maxPathSum(a);
    printf("Finished %d\n",res);
 }