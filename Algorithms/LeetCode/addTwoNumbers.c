//
//  addTwoNumbers.c
//  LeetCode
//
//  Created by WangJZ on 14-1-21.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode *helper(struct ListNode *l1, struct ListNode *l2) {
    if (l1 == NULL || l2 == NULL) return NULL;
    struct ListNode *ret = malloc(sizeof(struct ListNode *));
    ret->next = helper(l1->next, l2->next);
    ret->val = l1->val + l2->val;
    if (ret->next && ret->next->val >= 10) {//如果下一个节点有值并且值大于10，加到本节点上
        ret->next->val -= 10;
        ret->val ++;
    }
    return ret;
}
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode* ret = helper(l1, l2);
    if (ret->val>=10) {
        struct ListNode *head = malloc(sizeof(struct ListNode*));
        head->val = 1;
        head->next = ret;
        ret->val -= 10;
        return head;
    }else{
        return ret;
    }
}



