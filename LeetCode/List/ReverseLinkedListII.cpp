//
//  ReverseLinkedListII.cpp
//  Algorithms
//
//  Created by WangJZ on 14-3-21.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_list.h"

//2014-3-21 update
ListNode *reverseBetween(ListNode *head, int m, int n)
{
    ListNode dummy(0);
    ListNode *p = &dummy;
    dummy.next = head;
    
    for (int i = 1; i < m; i++) p = p->next;
    head = p->next;
    
    for ( ; m < n; m++)
    {
        ListNode *tmp = head->next;
        head->next = tmp->next;
        tmp->next = p->next;
        p->next = tmp;
    }
    return dummy.next;
}

ListNode *reverseBetween2(ListNode *head, int m, int n)
{
    if(head == NULL)
        return NULL;
    ListNode **pNode = &head;
    for(int i = 1; i < m; ++i)
        pNode = &((*pNode)->next);
    ListNode *subTail = *pNode;
    for(int i = m + 1; i <= n; ++i)
    {
        ListNode *pCur = subTail->next;
        subTail->next = pCur->next;
        pCur->next = *pNode;
        *pNode = pCur;
    }
    return head;
}