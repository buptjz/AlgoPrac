//
//  MergeTwoSortedLists.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-4.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_list.h"

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (!l2) return l1;
    if (!l1) return l2;
    
    ListNode *dummy = new ListNode(0);
    ListNode *cur = dummy;
    
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            cur->next = l1;
            l1 = l1->next;
        }else{
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    
    if (!l1) {
        cur->next = l2;
    }else{
        cur->next = l1;
    }
    
    
    return dummy->next;
}
