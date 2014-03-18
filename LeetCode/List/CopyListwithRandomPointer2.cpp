//
//  CopyListwithRandomPointer2.cpp
//  LeetCode
//
//  Created by WangJZ on 14-3-13.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/copy-list-with-random-pointer/

/*
 上一个思路用时是O(N2)
 这个代码使用了HashMap，在第一轮遍历的时候将原始节点与copy的节点一一对应
 在第二轮遍历的时候在HashMap中就可以以O(1)的时间复杂度读取任意一个节点，这样就能保证整体的时间复杂度
 
 */

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