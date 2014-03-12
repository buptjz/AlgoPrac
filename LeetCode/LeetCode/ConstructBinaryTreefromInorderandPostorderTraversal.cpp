//
//  ConstructBinaryTreefromInorderandPostorderTraversal.cpp
//  LeetCode
//
//  Created by WangJZ on 14-3-12.
//  Copyright (c) 2014年 WangJZ. All ri/Volumes/HDD/developer/AlgoPrac/LeetCode/LeetCode/ConstructBinaryTreefromInorderandPostorderTraversal.cppghts reserved.
//  http://oj.leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

/*
 
 思路  与中序+先序 的思路是一样的
 
 */

#include "ConstructBinaryTreefromInorderandPostorderTraversal.h"
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void buildTreeHelper(vector<int> &inorder, vector<int> &postorder, TreeNode *root,int in_s,int in_e,int po_s,int po_e){
    //思路：当前postorder的最后一个值是当前节点的值，在inorder中查询，inorder中左侧是左节点，右侧是有节点，递归下去构建树
    root->val = postorder[po_e];
    int ind = in_s;
    for (; ind <= in_e; ind++) {
        if (inorder[ind] == root->val) {
            break;
        }
    }
    if (ind < in_e) {//说明右子树有值
        TreeNode *rightNode = new TreeNode(0);
        root->right = rightNode;
        int length = in_e - (ind + 1);
        buildTreeHelper(inorder, postorder, rightNode, ind+1, in_e, po_e - 1 - length, po_e - 1);
    }
    if (ind > in_s) {//有左子树
        TreeNode *leftNode = new TreeNode(0);
        root->left = leftNode;
        int length = ind - 1 - in_s;
        buildTreeHelper(inorder, postorder, leftNode, in_s, ind - 1, po_s, po_s + length);
    }
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    if (inorder.size() == 0) {
        return NULL;
    }
    if (inorder.size() != postorder.size() || inorder.size() == 0) {
        return new TreeNode(0);
    }
    int length = (int)inorder.size();
    TreeNode *root = new TreeNode(0);
    buildTreeHelper(inorder, postorder, root, 0, length - 1, 0, length - 1);
    return root;
}
