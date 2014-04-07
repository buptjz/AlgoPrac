//
//  leetcode_list.h
//  Algorithms
//
//  Created by WangJZ on 14-3-19.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#ifndef Algorithms_leetcode_list_h
#define Algorithms_leetcode_list_h

#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <queue>
using namespace std;
void testMinimumTotal();
void testReorderList();
void testRotateRight();
void testReverseKGroup();
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

#endif
