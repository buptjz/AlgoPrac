//
//  BinaryTreeZigzagLevelOrderTraversal.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-22.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_tree.h"

vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> res;
    if (root == NULL) return res;
    bool fromLeftToRight = true;
    stack<TreeNode *> leftSt,rightSt;
    leftSt.push(root);
    while (!(leftSt.empty() && rightSt.empty())) {
        
        vector<int> curLevel;
        if (fromLeftToRight) {
            while (!leftSt.empty()) {
                TreeNode *tmp = leftSt.top();
                leftSt.pop();
                curLevel.push_back(tmp->val);
                if(tmp->left) rightSt.push(tmp->left);
                if(tmp->right) rightSt.push(tmp->right);
            }
        }else{
            while (!rightSt.empty()) {
                TreeNode *tmp = rightSt.top();
                rightSt.pop();
                curLevel.push_back(tmp->val);
                if(tmp->right) leftSt.push(tmp->right);
                if(tmp->left) leftSt.push(tmp->left);
            }
        }
        res.push_back(curLevel);
        curLevel.clear();
        fromLeftToRight = !fromLeftToRight;
    }
    return res;
}

void testZigzagLevelOrder(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    vector<vector<int>> a = zigzagLevelOrder(root);
}
