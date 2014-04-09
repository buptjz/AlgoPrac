//
//  SortList.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-5.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/sort-list/

#include "leetcode_sort.h"
#include "leetcode_list.h"
#include <math.h>

//编码太复杂了，ugly!!!
/*
 不管怎样，还是做出来了
 第一趟对2个数进行排序
 第二趟对4个
 第三趟对8个
 直到最后
 
 相当于做了原地的归并排序
 如果像网上很多人说的递归的归并排序，其实它所使用的空间不是常数的，而是logN的，不管怎样，还是参考一下
 http://www.cnblogs.com/TenosDoIt/p/3434550.html
*/
void sortListHelper(ListNode **head,int step){
    int save_step = step;
    ListNode *p1,*p2;
    p1 = p2 = *head;
    int p1_count = 1,p2_count = 1;
    while (save_step) {
        save_step--;
        if (save_step == 0) {
            ListNode *temp = p2;
            p2 = p2->next;
            temp->next = NULL;
        }else{
            p2 = p2->next;
        }
        if(p2 == NULL) return;
    }
    while (true) {
        if (p2 == NULL){
            while (p1_count <= step) {
                *head = p1;
                p1 = p1->next;
                head = &((*head)->next);
                p1_count++;
            }
            return;
        }
        if (p1_count <= step && p2_count <= step) {
            //p1 and p2 both has members
            if (p1->val <= p2->val) {
                *head = p1;
                p1 = p1->next;
                p1_count += 1;
            }else{
                *head = p2;
                p2 = p2->next;
                p2_count += 1;
            }
            head = &((*head)->next);
        }else if(p1_count <= step){
            //p2 has no members
            *head = p1;
            p1 = p1->next;
            p1_count++;
            head = &((*head)->next);
        }else if(p2_count <= step){
            //p1 has no members
            *head = p2;
            p2 = p2->next;
            p2_count++;
            head = &((*head)->next);
        }else{
            p1 = p2;
            save_step = step;
            p1_count = p2_count = 1;
            while (save_step) {
                save_step--;
                if (save_step == 0) {
                    ListNode *temp = p2;
                    p2 = p2->next;
                    temp->next = NULL;
                }else{
                    p2 = p2->next;
                }
                if(p2 == NULL){
                    *head = p1;
                    return;
                };
            }
        }
    }
    (*head)->next = NULL;
}

ListNode *sortList2(ListNode *head) {
    ListNode *saved_head = head;
    int count = 0,step;
    int length = 1;
    while ((head = head->next)) length++;
    while (true) {
        step = pow(2, count);
        if (step >= length) break;
        sortListHelper(&saved_head,step);
        count++;
    }
    return saved_head;
}

void testSortList(){
    ListNode *root = new ListNode(3);
    root->next = new ListNode(2);
    root->next->next = new ListNode(4);
//    root->next->next->next = new ListNode(8);
//    root->next->next->next->next = new ListNode(7);
//    root->next->next->next->next->next = new ListNode(1);
    ListNode *res = sortList2(root);
    cout<<"Finishe"<<endl;
}