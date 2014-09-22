//
//  BinaryTreeLevelOrderTraversalII.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-22.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_tree.h"

static void helper(TreeNode *root,vector<vector<int>> &retVec){
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);
    vector<int> curLevel;
    while (!q.empty()) {
        TreeNode *cur = q.front();
        q.pop();
        if (cur == NULL) {
            retVec.push_back(curLevel);
            curLevel.clear();
            if (!q.empty()){
                q.push(NULL);
            }
        }else{
            curLevel.push_back(cur->val);
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
    }
}

static void reorder(vector<vector<int>> &result){
    int start = 0;
    int end = (int)result.size() - 1;
    while (start < end) {
        vector<int> tmp = result[start];
        result[start] = result[end];
        result[end] = tmp;
        start ++;
        end--;
    }
}

vector<vector<int> > levelOrderBottom(TreeNode *root) {
    vector<vector<int>> retVec;
    if (root == NULL) return retVec;
    helper(root,retVec);
    reorder(retVec);
    return retVec;
}

void testLevelOrderBottom(){
    TreeNode *root = new TreeNode(1);
    levelOrderBottom(root);
    cout<<"a"<<endl;
}
