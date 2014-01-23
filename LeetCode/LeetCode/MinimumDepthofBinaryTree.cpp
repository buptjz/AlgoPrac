//
//  MinimumDepthofBinaryTree.cpp
//  LeetCode
//
//  Given a binary tree, find its minimum depth.

//  The minimum depth is the number of nodes along the
//  shortest path from the root node down to the nearest leaf node.
//  http://oj.leetcode.com/problems/minimum-depth-of-binary-tree/
//

#include "MinimumDepthofBinaryTree.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int min(int a,int b){
    return a < b ? a : b;
}

int minDepth(TreeNode *root) {
    if (root == NULL) return 0;
    return 1+ min(minDepth(root->left),minDepth(root->right));
}
