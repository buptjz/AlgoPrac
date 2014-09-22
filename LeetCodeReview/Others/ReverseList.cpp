//
//  ReverseList.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-17.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "others.h"

//链表翻转，看到的最精简的解法了
static void reverseList(ListNode * &head){
    if (head == NULL || head->next == NULL) return;
    ListNode *pre = head,*cur = head->next;
    head->next = NULL;
    while (cur != NULL) {
        ListNode *tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    head = pre;
}

void testReverseList(){
    ListNode *ln1 = new ListNode(0);
    ln1->next = new ListNode(1);
    ln1->next->next = new ListNode(2);
    ln1->next->next->next = new ListNode(3);
    ln1->next->next->next->next = new ListNode(4);
    
    reverseList(ln1);
    printf("Finished\n");
}