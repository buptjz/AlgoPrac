//
//  MergeTwoSortedLists.cpp
//  LeetCode
//
//  Created by WangJZ on 14-3-14.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/merge-two-sorted-lists/


/*
 合并两个链表，代码需要精简！
 思路：
 归并排序的并，
 用三个指针，分别指向current，L1的某个节点，L2的某个节点
 current不断被前行，L1和L2中的小者前行
 
 注意问题
 1）指针来回赋值的时候，注意使用temp保存中间结果
 2）要画图比较清晰
 */
#include "leetcode_list.h"

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *current,*savedHead,*temp;
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    if (l1->val > l2->val) {
        savedHead = l2;
        l2 = l2->next;
    }else{
        savedHead = l1;
        l1 = l1->next;
    }
    current = savedHead;
    while (l1 && l2) {
        if (l2->val < l1->val) {
            temp = l2->next;
            current->next = l2;
            l2 = temp;
            
        }else{
            temp = l1->next;
            current->next = l1;
            l1 = temp;
        }
        current = current->next;
    }
    if (l1) {
        current->next = l1;
    }
    if (l2) {
        current->next = l2;
    }
    return savedHead;
}