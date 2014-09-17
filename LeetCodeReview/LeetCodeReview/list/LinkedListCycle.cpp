//
//  LinkedListCycle.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-17.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  https://oj.leetcode.com/problems/linked-list-cycle/

#include "leetcode_list.h"

bool hasCycle(ListNode *head) {
    if (head == NULL) return false;
    ListNode *fast = head,*slow = head;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast) return true;
    }
    return false;
}
