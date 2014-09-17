//
//  LinkedListCycleII.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-17.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  https://oj.leetcode.com/problems/linked-list-cycle-ii/



#include "leetcode_list.h"

ListNode *detectCycle(ListNode *head) {
    if (head == NULL) return NULL;
    ListNode *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) break;
    }
    
    if (fast == NULL || fast->next == NULL) return NULL;
    while (head != slow) {
        head = head->next;
        slow = slow->next;
    }
    return head;
}
