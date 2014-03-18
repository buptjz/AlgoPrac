//
//  CopyListwithRandomPointer.cpp
//  LeetCode
//
//  Created by WangJZ on 14-3-13.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "CopyListwithRandomPointer.h"

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode *copyRandomList(RandomListNode *head) {
    if(head == NULL) return NULL;
    RandomListNode *source_cur,*copy_cur,*source_temp,*copy_temp;
    RandomListNode *rhead = new RandomListNode(head->label);
    source_cur = head;
    copy_cur = rhead;
    while(source_cur->next){
        copy_cur->next = new RandomListNode(source_cur->label);
        copy_cur = copy_cur->next;
        source_cur = source_cur->next;
    }
    source_cur = head;
    copy_cur = rhead;
    while(source_cur){
        source_temp = head;
        copy_temp = rhead;
        while(source_temp){
            if(source_temp->random == source_cur){
                copy_temp->random = copy_cur;
            }
            source_temp = source_temp->next;
            copy_temp = copy_temp->next;
        }
        source_cur = source_cur->next;
        copy_cur = copy_cur->next;
    }
    return rhead;
}
