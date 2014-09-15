//
//  SortList.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-15.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  https://oj.leetcode.com/problems/sort-list/

#include "leetcode_list.h"


ListNode* merge(ListNode *first,ListNode *second){
    if (first == NULL) return second;
    if (second == NULL) return first;
    ListNode *dummy = new ListNode(0);
    ListNode *current = dummy;
    while (first != NULL && second != NULL) {
        if (first->val < second->val) {
            current->next = first;
            first = first->next;
        }else{
            current->next = second;
            second = second->next;
            
        }
        current = current->next;
    }
    if (first != NULL) current->next = first;
    if (second != NULL) current->next = second;
    current = dummy->next;
    delete dummy;
    return current;
}


ListNode *sortList(ListNode *head){
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode *slow = head,*fast = head->next;
    while (true) {
        if(fast == NULL || fast->next == NULL) {
            
            ListNode *temp = slow;
            slow = slow->next;
            temp->next = NULL;
            break;
        }else{
            fast = fast->next->next;
            slow = slow->next;
        }
    }
    ListNode *first = sortList(head);
    ListNode *second = sortList(slow);
    return merge(first, second);
}

void testSortList(){
    ListNode *root = new ListNode(0);
    root->next = new ListNode(3);
    root->next->next = new ListNode(2);
//    root->next->next->next = new ListNode(1);
    ListNode *res = sortList(root);
    printf("finished\n");
}




