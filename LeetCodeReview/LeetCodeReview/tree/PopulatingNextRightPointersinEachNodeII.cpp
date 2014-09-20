//
//  PopulatingNextRightPointersinEachNodeII.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-20.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  https://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

#include "leetcode_tree.h"

void setNext(TreeLinkNode *parent,TreeLinkNode * const child){
    if (child == NULL) return;
    
    while (parent != NULL) {
        if (parent->left) {
            child->next = parent->left;
            break;
        }
        
        if(parent->right){
            child->next = parent->right;
            break;
        }
        parent = parent->next;
    }
}

static void helper(TreeLinkNode *root){
    if (root == NULL) return;
    //deal with right child
    setNext(root->next,root->right);
    helper(root->right);

    //deal with left child
    if (root->right && root->left) root->left->next = root->right;
    else setNext(root->next,root->left);
    helper(root->left);
}


void connect(TreeLinkNode *root) {
    if (root == NULL) return;
    helper(root);
}