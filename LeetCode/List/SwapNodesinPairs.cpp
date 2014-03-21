//
//  SwapNodesinPairs.cpp
//  LeetCode
//
//  Created by WangJZ on 14-2-22.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/swap-nodes-in-pairs/

#include "leetcode_list.h"

/*--------------2014.3.21日更新，在网上找到了最好的版本---------------*/

ListNode *swapPairs(ListNode *h)
{
    ListNode dummy(0);
    dummy.next = h;
    ListNode *pre = &dummy;
    while (h && h->next)
    {
        ListNode *t = h->next->next;
        pre->next = h->next;
        h->next->next = h;
        h->next = t;
        pre = h;
        h = t;
    }
    return dummy.next;
}

ListNode* swapPairs2(ListNode *head)
{
    if (head == NULL) {
        return head;
    }
    
    ListNode *f,*s;
    f = head;
    s = f->next;
    if(s == NULL){
        return head;
    }
    f->next = s->next;
    s->next = f;
    head = s;
    while (f->next && f->next->next) {//下两个节点都存在
        f = f->next;
        s = s->next;
        s->next = f->next;
        s = f->next;
        f->next = s->next;
        s->next = f;
    }
    return head;
}
void testSwapPairs(){
    
}