//
//  RotateList.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-6.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/rotate-list/

/*
 比较简单的旋转链表，注意画图小伙！链表问题一般画图都能解决，最难的无非使用到递归！
 */

#include "leetcode_list.h"

ListNode *rotateRight(ListNode *head, int k) {
    if (!head || !head->next || k == 0) return head;
    int length = 1;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    
    //Calculate the length of the list
    while (head->next) {
        length++;
        head = head->next;
    }
    
    //the actual rotate times.
    k = k % length;
    if (k == 0) return dummy->next;
    
    //The kth to last will be 1th in the new list,let the back to be the (k-1)th to last
    ListNode *back,*front;
    back = front = dummy->next;
    while (k-- > 0) front = front->next;
    while (front->next) {
        front = front->next;
        back = back->next;
    }
    
    //Regroup the generate the new list
    head = dummy->next;
    dummy->next = back->next;
    back->next = nullptr;
    front->next = head;
    return dummy->next;
}

void testRotateRight(){
    ListNode *root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(4);
    ListNode *res = rotateRight(root, 1);
    cout<<"Finished"<<endl;
}

