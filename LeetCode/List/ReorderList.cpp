//
//  ReorderList.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-5.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/reorder-list/

/*
excited
 算是第一个自己想出来的比较难的递归方法，思路和用排序链表构建二叉查找树很类似
 
 */

#include "leetcode_list.h"

ListNode *p2;// point to the second half head.
ListNode *last;//point to the first half last.
void locate(ListNode *head){
    //locate the position of p2 and last,pay attetion there r 2 situtions, even/odd numbers nodes 
    ListNode *fast,*slow;
    fast = slow = head;
    while (true) {
        if (!fast->next) {
            //odd
            p2 = slow->next;
            last = slow;
            slow->next = nullptr;
            break;
        }
        fast = fast->next;
        if (!fast->next) {
            //even
            last = slow;
            p2 = slow->next->next;
            slow->next->next = nullptr;
            break;
        }
        fast = fast->next;
        slow = slow->next;
    }
}
void scan(ListNode *head){
    //递归的去扫描，递归步进的条件是p2 = p2->next;和scan(head->next);
    //有一种后序遍历的赶脚！从递归的最后到最开始反过来看，每次p2前进一格，head后退一格
    //每轮递归都做改变，将head指向p2，p2指向head->next
    if (head->next != last)
        scan(head->next);
    ListNode *h_next = head->next;
    head->next = p2;
    p2 = p2->next;
    head->next->next = h_next;
}
void reorderList(ListNode *head) {
    if (!head || !head->next || !head->next->next) return;
    locate(head);
    scan(head);
}

void testReorderList(){
    ListNode *root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(4);
    reorderList(root);
    cout<<"Finished"<<endl;
}
