//
//  PopulatingNextRightPointersinEachNode.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-2.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node/

//又见树的遍历，请画图仔细思考

#include "leetcode_tree.h"



void firstTraverse(TreeLinkNode *root){
    if (root == NULL) return;
    if (root->left) root->left->next = root->right;
    firstTraverse(root->left);
    firstTraverse(root->right);
}
void secondTraverse(TreeLinkNode *root){
    if (root == NULL) return;
    if (root->right && root->next) root->right->next = root->next->left;
    secondTraverse(root->left);
    secondTraverse(root->right);
}
void connect(TreeLinkNode *root) {
    //分两边递归，第一遍令左孩子的next指向兄弟t
    //第二遍改变所有右孩子的next，如果父节点的next是空的，那么,右孩子的next为空，如果不为空，那么
    //rightchild->next = parent->next->left;
    firstTraverse(root);
    secondTraverse(root);
}


