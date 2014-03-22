//
//  RemoveDuplicatesfromSortedList.cpp
//  Algorithms
//
//  Created by WangJZ on 14-3-22.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_list.h"

//  Given a sorted linked list, delete all duplicates such that each element appear only once
//  http://oj.leetcode.com/problems/remove-duplicates-from-sorted-list/

ListNode *deleteDuplicates(ListNode *head) {
    if (head == NULL) {
        return NULL;
    }
    ListNode *first,*second;
    first = head;
    second = head->next;
    while (second) {
        if (first->val == second->val) {
            first->next = second->next;
            free(second);
            second = first->next;
        }else{
            first = first->next;
            second = second->next;
        }
    }
    return head;
}