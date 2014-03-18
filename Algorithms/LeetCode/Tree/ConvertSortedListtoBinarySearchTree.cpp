//
//  ConvertSortedListtoBinarySearchTree.cpp
//  LeetCode
//
//  Created by WangJZ on 14-3-12.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

/*
 思路http://leetcode.com/2010/11/convert-sorted-list-to-balanced-binary.html
 讲解的非常好，注意参数
 ListNode *&list
 */

#include "ConvertSortedListtoBinarySearchTree.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *sortedListToBSTHelper(ListNode *&list,int start,int end){
    if (start > end) {
        return NULL;
    }
    int middle = start + ((end - start) >> 1);//avoid overflow
    TreeNode *left = sortedListToBSTHelper(list, start, middle - 1);
    TreeNode *parent = new TreeNode(list->val);
    parent->left = left;
    list = list->next;
    parent->right= sortedListToBSTHelper(list, middle + 1, end);
    return parent;
}
TreeNode *sortedListToBST(ListNode *head) {
    int length = 0;
    ListNode *h = head;
    while (head) {
        length++;
        head = head->next;
    }
    return sortedListToBSTHelper(h,0,length - 1);
}

void testSortedListToBST(){
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    ListNode *node6 = new ListNode(6);
    ListNode *node7 = new ListNode(7);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    TreeNode *myNode = sortedListToBST(node1);
    printf("Finished");
    
}