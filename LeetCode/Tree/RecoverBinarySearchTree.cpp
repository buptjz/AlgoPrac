//
//  RecoverBinarySearchTree.cpp
//  LeetCode
//
//  Created by WangJZ on 14-3-14.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/recover-binary-search-tree/

/*
 
 （原）1，2，3，4，5
 （误）2，1，3，4，5
 （误）3，2，1，3，5
 （误）4，2，3，1，5
 观察能够发现，交换两个数字产生错误，错误的情况会是上述三种情况之一
 
 1）只有一个数字比它前一个数小                 解决：（该数）<->(它的前一个数)
 2）有两个数字比它前一个数字小，并且是挨着的     解决：（第一个数的前一个数）<->（第二个数）
 3）有两个数字比它前一个数字小，不挨着            解决：（第一个数的前一个数）<->（第二个数）
 
 
 后两种情况可以合并
 
 思路是使用中序遍历，记录前一个节点，本节点和前一个节点进行比较，如果异常，将本数和前一个数（其实是TreeNode *）都放到全局数组里
 遍历结束后对全局数组做处理，分两种情况讨论即可！
 */

#include "leetcode_tree.h"

static vector<TreeNode *> treeVec;
static TreeNode *lastNode = NULL;
void in_order(TreeNode *root){
    if (root->left) in_order(root->left);//左节点

    //root节点的处理
    if (lastNode != NULL) {
        if (root->val < lastNode->val) {//遇到异常节点
            treeVec.push_back(lastNode);//把异常前后的两个节点都放进来
            treeVec.push_back(root);
        }
    }
    lastNode = root;
    if (root->right) in_order(root->right);
}
void recoverTree(TreeNode *root) {
    in_order(root);
    if ((int)treeVec.size() == 4) {
        int temp = treeVec[0]->val;
        treeVec[0]->val = treeVec[3]->val;
        treeVec[3]->val = temp;
    }
    if ((int)treeVec.size() == 2) {
        int temp = treeVec[0]->val;
        treeVec[0]->val = treeVec[1]->val;
        treeVec[1]->val = temp;
    }
}