//
//  leetcode_sort.h
//  Algorithms
//
//  Created by WangJZ on 14-3-27.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#ifndef Algorithms_leetcode_sort_h
#define Algorithms_leetcode_sort_h

#include <vector>
using namespace std;
void testMerge();
void testsSearchInsert();
void testIntervalInsert();
void testSortCorlors();
void testFirstMissingPositive();
void testSortList();
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

#endif
