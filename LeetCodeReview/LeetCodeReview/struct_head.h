//
//  struct_head.h
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-17.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#ifndef LeetCodeReview_struct_head_h
#define LeetCodeReview_struct_head_h


struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x),next(NULL){}
};
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

#endif
