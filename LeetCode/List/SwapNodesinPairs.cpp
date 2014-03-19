//
//  SwapNodesinPairs.cpp
//  LeetCode
//
//  Created by WangJZ on 14-2-22.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/swap-nodes-in-pairs/

#include "leetcode_list.h"

ListNode* swapPairs(ListNode *head)
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