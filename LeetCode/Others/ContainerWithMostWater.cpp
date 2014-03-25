//
//  ContainerWithMostWater.cpp
//  LeetCode
//
//  Created by WangJZ on 3/6/14.
//  Copyright (c) 2014 WangJZ. All rights reserved.
//


/*
http://oj.leetcode.com/problems/container-with-most-water/
暴力求解发需要O(n2),有高手提出了从两边向中间找的想法，非常赞，怎么想到的呢？
http://rafal.io/posts/leetcode-11-container-with-most-water.html
http://blog.unieagle.net/2012/09/16/leetcode%E9%A2%98%E7%9B%AE%EF%BC%9Acontainer-with-most-water/)
*/

#include "leetcode_others.h"

int maxArea(vector<int> &height) {
    int start = 0;
    int end = (int)height.size() - 1;
    int maxC = 0;
    int current = 0;
    while(start < end){
        current = min(height[start],height[end]) * (end - start);
        maxC = max(maxC,current);
        if(height[start] > height[end]) end--;
        else start++;
    }
    return maxC;
}

void testMaxArea(){
    vector<int> c = {1,1};
    int x = maxArea(c);
    printf("Finished\n");
}