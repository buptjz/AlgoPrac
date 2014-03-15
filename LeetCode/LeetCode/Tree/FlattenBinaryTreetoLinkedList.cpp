//
//  FlattenBinaryTreetoLinkedList.cpp
//  LeetCode
//
//  Created by WangJZ on 14-3-12.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/flatten-binary-tree-to-linked-list/

/*
 思路：递归的去完成
 在每一个节点上，分四种情况进行讨论，递归，并保持递归子串的头尾指针，这样将左右两个子串串联起来即可
 令root的左为空，右为先序遍历的下一个节点！
 */

#include "FlattenBinaryTreetoLinkedList.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void flattenHelper(TreeNode *root,TreeNode *& head,TreeNode *& tail){
    TreeNode *lhead,*ltail,*rhead,*rtail;
    
    if (root->left == NULL && root->right == NULL) {
        head = root;
        tail = root;
        return;
    }else if(root->left == NULL){
        flattenHelper(root->right, rhead, rtail);
        root->right = rhead;
        root->left = NULL;
        head = root;
        tail = rtail;
    }else if(root->right == NULL){
        flattenHelper(root->left, lhead, ltail);
        root->right = lhead;
        root->left = NULL;
        head = root;
        tail = ltail;
    }else{
        flattenHelper(root->right, rhead, rtail);
        flattenHelper(root->left, lhead, ltail);
        root->left = NULL;
        root->right = lhead;
        ltail->right = rhead;
        head = root;
        tail = rtail;
    }
    
}
void flatten(TreeNode *root) {
    if (root == NULL) {
        return;
    }else{
        TreeNode *head,*tail;
        flattenHelper(root, head, tail);
    }
}

//2014.3.13日更新，思路非常清晰！

void flatten2(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    if(root->left == NULL){
        flatten(root->right);
        return;
    }
    TreeNode *left,*right;
    left = root->left;
    right = root->right;
    root->left = NULL;
    root->right = left;
    while(left->right){
        left = left->right;
    }
    left->right = right;
    flatten2(root->right);
}

void testFlattern(){
    TreeNode *root = new TreeNode(1);
    TreeNode *l = new TreeNode(2);
    TreeNode *r = new TreeNode(5);
    TreeNode *ll = new TreeNode(3);
    TreeNode *lr = new TreeNode(4);
    TreeNode *rr = new TreeNode(6);
    root->left = l;
    l->left = ll;
    l->right = lr;
    root->right = r;
    r->right = rr;
    flatten(root);
    printf("Finished");
}



