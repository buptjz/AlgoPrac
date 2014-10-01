//
//  RemoveDuplicatesfromSortedList.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-1.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_list.h"

ListNode *deleteDuplicates(ListNode *head) {
    if (head == NULL) return NULL;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    while (head->next != NULL) {
        if (head->val == head->next->val) {
            ListNode *tmp = head->next;
            head->next = head->next->next;
            free(tmp);
        }else{
            head = head->next;
        }
    }
    head = dummy->next;
    free(dummy);
    return head;
}
