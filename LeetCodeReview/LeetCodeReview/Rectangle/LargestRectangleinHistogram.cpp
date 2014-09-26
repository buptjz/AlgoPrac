//
//  LargestRectangleinHistogram.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-26.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_rectangle.h"

//使用堆栈的解法

int largestRectangleArea(vector<int> &height) {
    int len = (int)height.size();
    if (len == 0) return 0;
    
    int retMax = 0;
    stack<int> indexST;
    for (int i = 0; i < height.size(); i++) {
        if (indexST.empty() || height[indexST.top()] < height[i])
            ;
        else{
            while (!indexST.empty() && height[i] <= height[indexST.top()]) {
                int curIndex = indexST.top();
                indexST.pop();
                int preIndex = -1;
                if (!indexST.empty()) preIndex = indexST.top();
                retMax = max(retMax,height[curIndex] * (i - 1 - preIndex));
            }
            
        }
        indexST.push(i);
    }
    int lastIndex = (int)height.size() - 1;

    while (!indexST.empty()) {
        int curIndex = indexST.top();
        indexST.pop();
        int preIndex = -1;
        if (!indexST.empty()) preIndex = indexST.top();
        retMax = max(retMax,height[curIndex] * (lastIndex - preIndex));
    }
    
    return retMax;
}


//很少的使用到分治法的题型，但是下面这个解法超时了！
static int helper(const vector<int> &height,int start,int end){
    if (start > end) return 0;
    if (start == end) return height[start];
    
    int index = start;
    int minimumVal = height[start];
    for (int i = start + 1; i <= end; i++) {
        if (minimumVal > height[i]) {
            index = i;
            minimumVal = height[i];
        }
    }
    
    int withMiniVal = minimumVal * (end - start + 1);
    int leftMax = helper(height, start, index - 1);
    int rightMax = helper(height, index + 1, end);
    
    return max(max(leftMax, rightMax),withMiniVal);
}

//int largestRectangleArea(vector<int> &height) {
//    int len = (int)height.size();
//    if (len == 0) return 0;
//    return helper(height, 0, len - 1);
//}
//
void testLargestRectangleArea(){
    vector<int > a = {5,4,4,6,3,2,9,5,4,8,1,0,0,4,7,2};
    cout << largestRectangleArea(a) << endl;
}




