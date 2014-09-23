//
//  ReverseLinkedListII.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-23.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_list.h"

ListNode *reverseBetween(ListNode *head, int m, int n) {
    if (m == n) return head;
    
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    
    ListNode *pre = dummy;
    ListNode *cur = head;
    int index = 1;
    while (index < m) {
        pre = pre->next;
        cur = cur->next;
        index++;
    }
    while (index < n) {
        ListNode *tmp = cur->next;
        cur->next = tmp->next;
        tmp->next = pre->next;
        pre->next = tmp;
        index++;
    }
    return dummy->next;
}
