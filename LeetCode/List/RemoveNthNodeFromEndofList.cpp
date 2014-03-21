//
//  RemoveNthNodeFromEndofList.cpp
//  Algorithms
//
//  Created by WangJZ on 14-3-21.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_list.h"

ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *first,*second;
    first = head;
    second = head;
    while(n>0){
        second = second->next;
        n--;
    }
    if(second == NULL) return head->next;
    while(second->next){
        first = first->next;
        second = second->next;
    }
    second = first->next->next;
    free(first->next);
    first->next = second;
    return head;
}