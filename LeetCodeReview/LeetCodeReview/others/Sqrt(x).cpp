//
//  Sqrt(x).cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-2.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_others.h"

int sqrtHelper(long long x,int start,int end){
    if (start == end) return start;
    if (start == end - 1){
        if(end * end > x) return start;
        if (end * end <= x) return end;
    }
    long mid = start + ((end - start) >> 1);
    if (mid * mid > x ) {
        return sqrtHelper(x,start,(int)mid-1);
    }else{
        return sqrtHelper(x, (int)mid,(int)end);
    }
}


int sqrt(int x) {
    if (x >= 46340) {
        return sqrtHelper(x, 0, 46340);
    }else{
        return sqrtHelper(x, 0, x);
    }
}

void testSqrt(){
    cout << sqrt(2147395600) <<endl;
        cout << sqrt(9) <<endl;
    cout << sqrt(7) <<endl;
    cout << sqrt(6) <<endl;
    cout << sqrt(1) <<endl;
    cout << sqrt(0) <<endl;
}