//
//  RotateList.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-4.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_list.h"

ListNode *rotateRight(ListNode *head, int k) {
    if (head == NULL || head->next == NULL) return head;
    
    ListNode *save_head = head;
    int len = 0;
    while (head != NULL) {
        len ++;
        head = head->next;
    }
    
    int move = k % len;
    head = save_head;
    
    ListNode *tail = head;
    while (move > 0) {
        tail = tail->next;
        move--;
    }
    
    while (tail->next != NULL) {
        head = head->next;
        tail = tail->next;
    }
    
    tail->next = save_head;
    save_head = head->next;
    head->next = NULL;
    return save_head;
}
