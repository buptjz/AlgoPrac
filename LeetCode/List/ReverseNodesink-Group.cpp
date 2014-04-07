//
//  ReverseNodesink-Group.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-7.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/reverse-nodes-in-k-group/

/*
 总体比较简单，画图就好，需要注意的是第一个group反转的时候，注意把dummy指向头结点
 */
#include "leetcode_list.h"

ListNode *reverseKGroup(ListNode *head, int k) {
    if (!head || !head->next || k <= 1) return head;
    
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    int first_group = true;
    
    ListNode *end,*prev = dummy;
    while (true) {
        if(!(head = end = prev->next)) return dummy->next;
        int kk = k;
        while (--kk > 0){
            end = end->next;
            //number of nodes is not a multiple of k,left-out nodes in the end remain.
            if (end == NULL) return dummy->next;
        }
        while (head->next != end) {
            ListNode *temp = head->next;
            head->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }
        //the last one of k nodes
        head->next = end->next;
        end->next = prev->next;
        prev->next = end;
        if (first_group) {
            first_group = false;
            dummy->next = end;
        }
        prev = head;
    }
    
    return dummy->next;
}

void testReverseKGroup(){
    ListNode *root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(4);
    ListNode *res = reverseKGroup(root, 1);
    cout<<"Finished"<<endl;
}
