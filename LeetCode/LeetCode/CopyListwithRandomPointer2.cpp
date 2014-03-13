//
//  CopyListwithRandomPointer2.cpp
//  LeetCode
//
//  Created by WangJZ on 14-3-13.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "CopyListwithRandomPointer2.h"
#include <map>
using namespace std;
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode *copyRandomList2(RandomListNode *head) {
    //使用hashmap来保存节点，key是节点的地址，value是节点的next的值
    map<RandomListNode*, RandomListNode*> nodesMap;
    RandomListNode *saved_head = head;
    while (head) {
        nodesMap[head] = new RandomListNode(head->label);
        head = head->next;
    }
    head = saved_head;
    while (head) {
        if (nodesMap[head]) {
            RandomListNode *curCopyNode = nodesMap[head];
            if (head->next) {
                curCopyNode->next = nodesMap[head->next];
            }else{
                curCopyNode->next = NULL;
            }
            curCopyNode->random = nodesMap[head->random];
        }
        head = head->next;
    }
    return nodesMap[saved_head];
}