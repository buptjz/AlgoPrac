//
//  RemoveDuplicatesfromSortedListII.cpp
//  Algorithms
//
//  Created by WangJZ on 14-3-21.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
// https://github.com/missjing/leetcode/blob/master/Remove%20Duplicates%20from%20Sorted%20ListII.txt

#include "leetcode_list.h"

static ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *root = NULL;
    ListNode **ppNext = &root;
    while(head)
    {
        if(head->next == NULL || head->next->val != head->val)
        {
            *ppNext = head;
            ppNext = &(head->next);
            head = head->next;
        }
        else
        {
            int val = head->val;
            while(head != NULL && head->val == val)
                head = head->next;
        }
    }
    *ppNext = NULL;
    return root;
}