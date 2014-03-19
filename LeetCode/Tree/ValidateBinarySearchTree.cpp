//
//  ValidateBinarySearchTree.cpp
//  Algorithms
//
//  Created by WangJZ on 14-3-19.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_tree.h"

bool isValid(TreeNode *root,int maxVal,int minVal){
    if(root == NULL) return true;
    if(root->val >=maxVal || root->val <= minVal) return false;
    return isValid(root->left,root->val,minVal) && isValid(root->right,maxVal,root->val);
}

bool isValidBST(TreeNode *root) {
    return isValid(root,(numeric_limits<int>::max)(),(numeric_limits<int>::min)());
}