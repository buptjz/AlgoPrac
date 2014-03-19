//
//  MinimumDepthofBinaryTree.cpp
//  LeetCode
//
//  Given a binary tree, find its minimum depth.

//  The minimum depth is the number of nodes along the
//  shortest path from the root node down to the nearest leaf node.
//  http://oj.leetcode.com/problems/minimum-depth-of-binary-tree/
//

/*
 【注意】此题看似简单，其实有陷阱！树的最小深度的意思是“从根节点到叶子节点的最短路径”
 其中叶子节点是不包含左右孩子的节点，所以要分别做判断，当一个节点没有左节点的时候，要去看它的又孩子的长度
 
 下文的写法非常简练，网上没有发现比这个简单的目前^_^
 */

#include "leetcode_tree.h"

int minDepth(TreeNode *root) {
    if (root == NULL) return 0;
    if (root->left == NULL) return 1+minDepth(root->right);
    if (root->right == NULL) return 1+minDepth(root->left);
    return 1+ min(minDepth(root->left),minDepth(root->right));
}