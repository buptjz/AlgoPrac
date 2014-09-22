//
//  ConvertSortedListtoBinarySearchTree.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-22.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  https://oj.leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

//还是比较难理解

#include "leetcode_tree.h"

TreeNode* helper(ListNode *& root,int start,int end){
    if (start > end) return NULL;
    int mid = start + ((end - start) >> 1);
    TreeNode *leftChild = helper(root, start, mid - 1);
    TreeNode *parent = new TreeNode(root->val);
    parent->left = leftChild;
    root = root->next;
    parent->right = helper(root, mid + 1, end);
    return parent;
}

TreeNode *sortedListToBST(ListNode *head) {
    int length = 0;
    ListNode *saved_head = head;
    while (head != NULL) {
        length ++;
        head = head->next;
    }
    return helper(saved_head, 0, length - 1);
}

void testSortedListToBST(){
    ListNode *root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    TreeNode*ret = sortedListToBST(root);
    cout<<"Finished"<<endl;
}