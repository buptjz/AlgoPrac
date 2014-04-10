//
//  PartitionList.cpp
//  LeetCode
//
//  Created by WangJZ on 14-2-23.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/partition-list/

#include "leetcode_list.h"
//2014.4.9日更新方法二：使用正常的思路，在原链表上做操作，注意的是要先找到第一个大于x的点，
//不然直接使用后一个while循环会有问题

ListNode *partition(ListNode *head, int x) {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *small_last = dummy,*cur = dummy;
    while (cur->next && cur->next->val < x) {//找到第一个大于x的点
        cur = cur->next;
        small_last = small_last->next;
    }
    while (cur->next) {
        if (cur->next->val >= x) {//大的不动
            cur = cur->next;
        }else{
            ListNode *temp = cur->next;
            cur->next = temp->next;
            temp->next = small_last->next;
            small_last->next = temp;
            small_last = small_last->next;
        }
    }
    return dummy->next;
}
//思路很重要，使用两个链表，大的串在一起，小的串在一起，再合并
ListNode *partition2(ListNode *head, int x) {
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







