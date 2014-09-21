//
//  BalancedBinaryTree.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-21.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

//有疑问
/*
             1
            / \
           2   4
          /   / \
         3   5   6
                  \
                   7

 这算平衡二叉树？
 For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 虽然看起来满足这个要求！
 
 */



#include "leetcode_tree.h"

bool helper(TreeNode *root,int &depth){
    int leftDep = 0,rightDep = 0;
    bool leftBal = true,rightBal = true;
    
    if(root->left && root->right){
        leftBal = helper(root->left, leftDep);
        rightBal = helper(root->right, rightDep);
    }else if(root->left){
        leftBal = helper(root->left, leftDep);
    }else if(root->right){
        rightBal = helper(root->right, rightDep);
    }
    
    if (!leftBal || !rightBal) return false;
    if (leftDep - rightDep > 1 || leftDep - rightDep < -1) return false;
    
    depth = max(leftDep,rightDep) + 1; //这里取max为何？
    return true;
}

bool isBalanced(TreeNode *root) {
    if (root == NULL) return true;
    int depth = 0;
    return helper(root,depth);
}