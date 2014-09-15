//
//  InsertionSortList.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-15.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  https://oj.leetcode.com/problems/insertion-sort-list/

#include "leetcode_list.h"

ListNode *insertionSortList(ListNode *head) {
    if (head == NULL || head->next == NULL) return head;
    ListNode *dummy = new ListNode(INT_MIN);
    dummy->next = head;
    ListNode *pre = dummy,*current = pre->next,*run;
    while (current != NULL) {
        run = dummy;
        while (run != current) {
            if (run->val <= current->val && run->next->val > current->val) {
                pre->next = current->next;
                ListNode *temp = run->next;
                run->next = current;
                current->next = temp;
                current = pre;
            }else{
                run = run->next;
            }
        }
        pre = current;
        current = current->next;
    }
    return dummy->next;
}

void testInsertSortList(){
    ListNode *root = new ListNode(0);
    root->next = new ListNode(3);
    root->next->next = new ListNode(2);
    root->next->next->next = new ListNode(1);
    ListNode *res = insertionSortList(root);
    printf("finished\n");
}