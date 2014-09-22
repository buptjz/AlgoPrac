//
//  UniqueBinarySearchTreesII.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-22.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_tree.h"

static vector<TreeNode *> helper(int start,int end){
    vector<TreeNode *> retVec;
    if (start > end) {
        retVec.push_back(NULL);
        return retVec;
    }
    for (int i = start; i <= end; i++) {
        vector<TreeNode *> leftVec = helper(start,i - 1);
        vector<TreeNode *> rightVec = helper(i + 1,end);
        for (int left = 0; left < (int)leftVec.size(); left++) {
            for (int right = 0; right < (int)rightVec.size(); right++) {
                TreeNode *root = new TreeNode(i);
                root->left = leftVec[left];
                root->right = rightVec[right];
                retVec.push_back(root);
            }
        }
    }
    return retVec;
}

vector<TreeNode *> generateTrees(int n) {
    return helper(1, n);
}