//
//  leetcode_list.h
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-15.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#ifndef LeetCodeReview_leetcode_list_h
#define LeetCodeReview_leetcode_list_h

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <stack>


struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x),next(NULL){}
};

void testSortList();
void testInsertSortList();

void testReorderList();

#endif
