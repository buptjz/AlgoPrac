//
//  PathSumII.cpp
//  LeetCode
//
//  Created by WangJZ on 3/9/14.
//  Copyright (c) 2014 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/path-sum-ii/

#include "PathSumII.h"
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void PathSumHelper(TreeNode *root, int sum,vector<vector<int>> &retVec,vector<int>&tmp){
    //case(1) a leaf
    if (root ->left == NULL && root->right == NULL) {
        if (sum == root->val) {
            tmp.push_back(sum);
            retVec.push_back(tmp);
            tmp.pop_back();
        }
        return;
    }
    //case(2) not a leaf
    tmp.push_back(root->val);
    if (root->left !=NULL)
        PathSumHelper(root->left,sum - root->val,retVec,tmp) ;
    if (root->right !=NULL)
        PathSumHelper(root->right,sum - root->val,retVec,tmp) ;
    tmp.pop_back();
}

vector<vector<int> > pathSum(TreeNode *root, int sum) {
    vector<vector<int> > retVec;
    vector<int> tmp;
    if (!root) {
        return retVec;
    }
    PathSumHelper(root, sum, retVec, tmp);
    return retVec;
}

