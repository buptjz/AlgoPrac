//
//  LinkedListCycleII.cpp
//  Algorithms
//
//  Created by WangJZ on 14-3-21.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_list.h"

ListNode *detectCycle(ListNode *head) {
    if(head == NULL) return NULL;
    ListNode *fast,*low,*start;
    start = head;
    fast = head;
    low = head;
    while(true){
        fast = fast->next;
        if(fast == NULL) return NULL;
        fast = fast->next;
        if(fast == NULL) return NULL;
        low = low->next;
        if(low == fast) break;
    }
    while(true){
        if(start == low) return start;
        start = start->next;
        low = low->next;
    }
}