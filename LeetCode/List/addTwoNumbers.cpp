//
//  addTwoNumbers.cpp
//  LeetCode
//
//  Created by WangJZ on 14-1-21.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_list.h"

void helper(ListNode*parent, ListNode *l1,  ListNode *l2,int add) {
    if (l1 == NULL && l2 == NULL){//已经走到最后一个节点
        if (add == 1) {
            ListNode *end = new ListNode(1);
            parent->next = end;
        }
        return;
    }
    
    int value;
    ListNode *l_next,*r_next;
    if (l1 == NULL) {//左链没有了
        value = l2->val + add;
        l_next = NULL;
        r_next = l2->next;
    }else if(l2 == NULL){//右链没有了
        value = l1->val + add;
        l_next = l1->next;
        r_next = NULL;
    }else{//两个链表都有
        value = l1->val + l2->val + add;
        l_next = l1->next;
        r_next = l2->next;
    }
    
    add = value >= 10? 1:0;
    if (value >= 10) value -= 10;

    ListNode *current = new ListNode(value);
    parent->next = current;
    helper(current, l_next, r_next, add);
}
ListNode *addTwoNumbers( ListNode *l1,  ListNode *l2) {
    ListNode *head = new ListNode(0);
    helper(head, l1, l2, 0);
    return head->next;
}
