//
//  InsertionSortList.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-6.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/insertion-sort-list/

/*
 插入排序
 使用多个指针，注意直来直去别弄乱了，画图非常easy！
 */
#include "leetcode_list.h"

ListNode *insertionSortList(ListNode *head) {
    if (head == NULL) return NULL;
    
    ListNode *dummy = new ListNode(-2147483648);
    dummy->next = head;
    
    ListNode *p_prev = head,*p_next,*p_cur = head->next,*p_compare;

    //starts from the second node
    while (p_cur != NULL) {
        p_next = p_cur->next;
        p_compare = dummy;
        
        //no need to insert
        if (p_cur->val >= p_prev->val) {
            p_cur = p_cur->next;
            p_prev = p_prev->next;
        }else{
            //search the place to insert
            while (p_compare != p_prev) {
                if(p_compare->val <= p_cur->val && p_compare->next->val > p_cur->val){
                    //find the place to insert
                    p_prev->next = p_next;
                    p_cur->next = p_compare->next;
                    p_compare->next = p_cur;
                    
                    //set next iteration,pay attention no need to reset prev!
                    p_cur = p_next;
                    break;
                }
                p_compare = p_compare->next;
            }
            
        }
        
    }
    return dummy->next;
}

