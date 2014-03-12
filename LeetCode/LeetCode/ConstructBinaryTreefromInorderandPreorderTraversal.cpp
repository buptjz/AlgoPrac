//
//  ConstructBinaryTreefromInorderandPostorderTraversal.cpp
//  LeetCode
//
//  Created by WangJZ on 14-3-11.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

#include "ConstructBinaryTreefromInorderandPostorderTraversal.h"
#include <vector>
/*
 Given inorder and preorder traversal of a tree, construct the binary tree.
 
 Note:
 You may assume that duplicates do not exist in the tree.
 */
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void buildTree2Helper(vector<int> &inorder, vector<int> &preorder,TreeNode *root,int in_s,int in_e,int po_s,int po_e){
    int index = in_s;
    root->val = preorder[po_s];
    for (; index <= in_e; index++) {
        if (inorder[index] == preorder[po_s]) {
            break;
        }
    }
    if (index > in_s) {//说明index左侧有值，有左子树！
        TreeNode *left = new TreeNode(0);
        root->left = left;
        int length = (index-1)-in_s;
        buildTree2Helper(inorder,preorder,left,in_s,index-1,po_s+1,po_s+1+length);//后两组数之差相等
    }
    if (index < in_e) {//index右侧有值，有右子树
        TreeNode *right = new TreeNode(0);
        root->right = right;
        int length = in_e - (index+1);
        buildTree2Helper(inorder, preorder, right, index+1, in_e, po_e - length, po_e);
    }
    
}


TreeNode *buildTree2( vector<int> &preorder,vector<int> &inorder) {
    if (inorder.size() != preorder.size() || inorder.size() == 0) {
        return new TreeNode(0);
    }
    int length = (int)inorder.size();
    TreeNode *root = new TreeNode(0);
    buildTree2Helper(inorder, preorder, root, 0, length - 1, 0, length - 1);
    return root;
}

void testBuildTree(){
//    vector<int> postOrder = {79,-49,-59,6,-83,-96,-36,85,-50,20,23,92,55,72,-6,-76,14,41,64,17,-73,-85,30,-52,75,88,-37,87,59,-27,80,1,-81,-55,44,-42,-14,19,-46,-60,-34,-87,31,91,-10,-18,38,-25,74,86,5,42,-90,-7,22,-72,32,56,50,-71,-13,-24,60,-20,34,58,-4,78,-16,-21,-54,27,-89,53,49,83,-1,21,81,40,-29,89,-92,-22,11,47,-23,-19,-3,-48,-99,61,-95,48,-79,-100,54,-70,39,-9,-82,-41,94,-30,15,-63,-15,-97,43,97,-64,51,-43,-98,4,67,84,82,-58,77,16,96,36,35,-69,65,28,-5,-74,57,18,-88,0,37,-94,66,24,9,-61,76,29,3,-39,90,-65,-44,2,-26,95,69,-17,-84,-78,93,-66,-40,99,-57,-68,26,7,73,46,62,-8,12,-47,-67,-2,-51,-86,10,45,-35,-93,-38,-31,-77,63,71,-91,-28,-56,-33,-32,70,-11,-62,-45,-53,52,8,-75,-12,33,68};
//    vector<int> inOrder = {16,79,-59,-49,-50,-83,6,-96,85,-36,77,20,55,23,92,72,-58,-6,14,-76,-46,41,-37,17,64,88,-73,-85,-52,30,75,19,-42,-55,87,80,59,-27,-81,1,44,-14,84,-10,-60,-34,91,-87,31,42,5,-18,38,86,-25,74,22,-7,-90,56,-72,32,-24,50,-13,-71,83,60,34,-20,49,58,53,-4,-89,78,27,-21,-16,-54,67,-1,21,11,-22,81,40,-92,-29,89,-95,-48,47,-23,-3,-19,61,-99,4,48,-63,-79,-30,-100,54,-70,94,39,-9,-41,-82,15,-98,-15,-97,-43,-64,43,97,51,82,68,96,-5,36,28,35,-69,65,24,-74,57,66,-94,-88,18,37,0,29,9,76,-61,33,69,-39,3,-44,90,-65,95,-26,2,93,-78,-84,-17,-12,-66,-75,-40,99,73,-57,7,26,-68,8,12,-8,62,46,-51,-67,-47,-2,52,-77,-86,10,-38,-93,-35,45,-31,-91,63,71,-28,-53,-56,-32,-33,-45,70,-62,-11};
//    TreeNode *root = buildTree(inOrder, postOrder);
//    printf("Finished \n");
}





