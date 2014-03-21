//
//  LinkedListCycle.cpp
//  Algorithms
//
//  Created by WangJZ on 14-3-21.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_list.h"

bool hasCycle(ListNode *head) {
    if(head == NULL) return false;
    ListNode *slow,*fast;
    slow = head;
    fast = head;
    while(true){
        fast = fast->next;
        if(fast == NULL) return false;//截止了，没有cycle
        fast = fast->next;
        if(fast == NULL) return false;//截止了，没有cycle
        slow = slow->next;
        if(slow == fast) return true;//是回环的唯一条件是快慢指针重合
    }
    return false;
}