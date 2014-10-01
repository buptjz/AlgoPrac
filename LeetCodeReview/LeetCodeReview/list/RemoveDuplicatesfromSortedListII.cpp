//
//  RemoveDuplicatesfromSortedListII.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-1.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

//做链表题不画图就是作死

#include "leetcode_list.h"

static ListNode *deleteDuplicates(ListNode *head) {
    if (head == NULL || head->next == NULL) return head;
    ListNode *dummy = new ListNode(0);
    
    ListNode *tail = dummy;
    
    ListNode *pre = NULL;
    ListNode *cur = head;
    while (true) {
        if (cur->next == NULL) {
            if (pre && pre->val != cur->val) {
                tail->next = cur;
                tail = tail->next;
            }
            break;
        }else{
            if (cur->val == cur->next->val || (pre && pre->val == cur->val)) {//当前node跟前面或者后面的一样
                
            }else{//跟前后都不一样，可以加入到list中
                tail->next = cur;
                tail = tail->next;
            }
            pre = cur;
            cur = cur->next;
        }
    }
    tail->next = NULL;
    
    return dummy->next;
}

void testDeleteDuplicates(){
    ListNode *root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(2);
    ListNode *ret = deleteDuplicates(root);
}
