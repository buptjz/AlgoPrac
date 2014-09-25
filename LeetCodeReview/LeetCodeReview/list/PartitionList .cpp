//
//  PartitionList .cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-25.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_list.h"

ListNode *partition(ListNode *head, int x) {
    if (head == NULL) return NULL;
    
    ListNode *leftDummy = new ListNode(0);
    ListNode *rightDummy = new ListNode(0);
    
    ListNode *leftTail = leftDummy;
    ListNode *rightTail = rightDummy;
    while (head != NULL) {
        if (head->val < x) {
            leftTail->next = head;
            leftTail = leftTail->next;
        }else{
            rightTail->next = head;
            rightTail = rightTail->next;
        }
        head = head->next;
    }
    rightTail->next = NULL;
    leftTail->next = rightDummy->next;
    free(rightDummy);
    head = leftDummy->next;
    free(leftDummy);
    return head;
}

void testPartition(){
    ListNode *root = new ListNode(2);
    root->next = new ListNode(1);
    
}