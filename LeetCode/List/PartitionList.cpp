//
//  PartitionList.cpp
//  LeetCode
//
//  Created by WangJZ on 14-2-23.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/partition-list/

#include "leetcode_list.h"

ListNode *partition(ListNode *head, int x) {
    ListNode *a,*b,*cur,*ah,*bh;
    a = new ListNode(0);
    b = new ListNode(0);
    ah = a;
    bh = b;
    cur = head;
    while (cur) {
        if (cur->val < x) {
            a->next = cur;
            a = a->next;
        }else{
            b->next = cur;
            b = b->next;
        }
        cur = cur->next;
    }
    //链接两个链表
    a->next = bh->next;
    
    return ah->next;
}

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





