//
//  CopyListwithRandomPointer.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-18.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  https://oj.leetcode.com/problems/copy-list-with-random-pointer/

#include "leetcode_list.h"


RandomListNode *copyRandomList(RandomListNode *head) {
    if (head == NULL) return NULL;
    
    RandomListNode *saved = head;
    map<RandomListNode *, RandomListNode *> n2n_map;
    
    
    RandomListNode *copyHead = new RandomListNode(head->label);
    n2n_map[head] = copyHead;
    
    head = head->next;
    while (head != NULL){
        n2n_map[head] = new RandomListNode(head->label);
        head = head->next;
    }
    
    head = saved;
    while (head != NULL) {
        n2n_map[head]->next = n2n_map[head->next];
        n2n_map[head]->random = n2n_map[head->random];
        head = head->next;
    }
    return copyHead;
}