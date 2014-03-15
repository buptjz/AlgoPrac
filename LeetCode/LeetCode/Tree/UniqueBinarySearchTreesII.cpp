//
//  UniqueBinarySearchTreesII.cpp
//  LeetCode
//
//  Created by WangJZ on 14-3-14.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/unique-binary-search-trees-ii/

/*
 
 思路：递归的去构建树
 
 */

#include "UniqueBinarySearchTreesII.h"
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

vector<TreeNode *> generateTreesHelper(int start,int end) {
    vector<TreeNode *>retVec;
    if (start > end) {
        retVec.push_back(NULL);
        return retVec;
    }
    if (start == end) {
        retVec.push_back(new TreeNode(start));
        return retVec;
    }
    vector<TreeNode *> left,right;
    for (int i = start; i <= end; i++) {
        left = generateTreesHelper(start, i - 1);
        right = generateTreesHelper(i + 1, end);
        for (int l = 0; l < (int)left.size(); l++) {
            for (int r = 0; r < (int)right.size(); r++) {
                TreeNode *root = new TreeNode(i);
                root->left = left[l];
                root->right = right[r];
                retVec.push_back(root);
            }
        }
    }
    return retVec;
}

vector<TreeNode *> generateTrees(int n) {
    vector<TreeNode *> empty;
    if (n == 0) {
        empty.push_back(NULL);
        return empty;
    }
    
    empty =  generateTreesHelper(1,n );
    return empty;
}

void testGenerateTrees(){
    vector<TreeNode *> x = generateTrees(0);
    printf("Finished with size %d\n",(int)x.size());
}
