//
//  ReorderList.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-17.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_list.h"

/*
 更新，有点二了， 更简单的方法是拆分成两个链表，将后一半链表翻转，再合并

 */

//递归求解法 有点复杂
static ListNode *middle;
static bool isEven = true;
void helper(ListNode *cur,ListNode **ret){
    //base case:
    if(cur == middle){
        if (isEven == true) {
            *ret = cur->next->next;
            cur->next->next = NULL;
        }else{
            *ret = cur->next;
            cur->next = NULL;
        }
        return;
    }
    ListNode **insert = (ListNode **)malloc(sizeof(ListNode **) * 1);
    helper(cur->next,insert);
    *ret= (*insert)->next;
    (*insert)->next = cur->next;
    cur->next = *insert;
    free(insert);
}

ListNode *findMiddle(ListNode *head){
    ListNode *fast,*slow;
    fast = head;
    slow = head;
    while (true) {
        fast = fast->next;
        if (fast == NULL) {
            isEven = false;
            break;
        }
        fast = fast->next;
        if (fast == NULL){
            isEven = true;
            break;
        }
        slow = slow->next;
    }
    return slow;
}

void reorderList(ListNode *head) {
    if (head == NULL || head->next == NULL) return;
    middle = findMiddle(head);
    ListNode **ret =(ListNode **) malloc(sizeof(ListNode**) * 1);
    helper(head, ret);
    free(ret);
}

void testReorderList(){
    ListNode *ln1 = new ListNode(0);
    ln1->next = new ListNode(1);
    ln1->next->next = new ListNode(2);
    ln1->next->next->next = new ListNode(3);
    ln1->next->next->next->next = new ListNode(4);
    
    reorderList(ln1);
    printf("Finished\n");
}







