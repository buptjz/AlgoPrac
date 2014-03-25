//
//  LargestRectangularAreainaHistogramV3.cpp
//  LeetCode
//
//  Created by WangJZ on 3/8/14.
//  Copyright (c) 2014 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/largest-rectangle-in-histogram/

#include "leetcode_dp.h"
/*
 1) Create an empty stack.
 
 2) Start from first bar, and do following for every bar ‘hist[i]‘ where ‘i’ varies from 0 to n-1.
 ……a) If stack is empty or hist[i] is higher than the bar at top of stack, then push ‘i’ to stack.
 ……b) If this bar is smaller than the top of stack, then keep removing the top of stack while top of the stack is greater. Let the removed bar be hist[tp]. Calculate area of rectangle with hist[tp] as smallest bar. For hist[tp], the ‘left index’ is previous (previous to tp) item in stack and ‘right index’ is ‘i’ (current index).
 
 3) If the stack is not empty, then one by one remove all bars from stack and do step 2.b for every removed bar.
 
 */

/*
 参考http://www.geeksforgeeks.org/largest-rectangle-under-histogram/
 使用了Stack，方法太难想，怎么想的？
 
 96ms，提升了20ms
 */
using namespace std;
int largestRectangleArea(vector<int> &height) {

    int maxVal = 0;
    int curVal = 0;
    int length = (int)height.size();
    //1) Create an empty stack.
    stack<int> myStack;
    
    //2) Start from first bar, and do following for every bar ‘hist[i]‘ where ‘i’ varies from 0 to n-1.
    for (int i = 0 ; i < length; i++) {
        if (myStack.empty() || height[myStack.top()] <= height[i]) {
            myStack.push(i);//push the index into the stack
        }else{
            while (!myStack.empty() && height[myStack.top()] > height[i]) {
                int temp = height[myStack.top()];
                myStack.pop();
                curVal = temp * (myStack.empty()? (i): (i - myStack.top() -1 ));
                if (curVal > maxVal) {
                    maxVal = curVal;
                }
            }
            myStack.push(i);//push the index into the stack
        }
    }
    while (!myStack.empty()) {
        int temp = height[myStack.top()];
        myStack.pop();
        curVal = temp * (myStack.empty()? (length): (length - 1 - myStack.top()));
        if (curVal > maxVal) {
            maxVal = curVal;
        }
    }
    return maxVal;
}

void testLargestRectangleArea(){
    vector<int> height = {4,3,1};
    int x = largestRectangleArea(height);
    printf("%d\n",x);
}