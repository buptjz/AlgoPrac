////
////  LargestRectangularAreainaHistogram.cpp
////  LeetCode
////
////  Created by WangJZ on 3/7/14.
////  Copyright (c) 2014 WangJZ. All rights reserved.
////
//
//
//#include "LargestRectangularAreainaHistogram.h"
//#include <vector>
//
///*
// Largest Rectangular Area in a Histogram
// We can use Divide and Conquer to solve this in O(nLogn) time. The idea is to find the minimum value in the given array. Once we have index of the minimum value, the max area is maximum of following three values.
// a) Maximum area in left side of minimum value (Not including the min value)
// b) Maximum area in right side of minimum value (Not including the min value)
// c) Number of bars multiplied by minimum value.
// */
//
///*
// 结果：
// Status:Time Limit Exceeded
// Last executed input: 	[0,1,2,3,4,5,6,7,8,9,10,11,12,13,...,19999]
// 表面上看分治法和快排很像，时间复杂度确实是O(nlogn)，这是建立在minimum是在数组中间的情况，
//( n+2*n/2+4*n/4+... = nlongn)
// 
// */
//using namespace std;
//int findMinimunIndex(vector<int> &height,int start,int end){
//    int minimun = height[start];
//    int index = start;
//    for (int i = start+1; i <= end; i++) {
//        if(height[i] < minimun) {
//            minimun = height[i];
//            index = i;
//        }
//    }
//    return index;
//}
//
//int largestRectangleAreaHelper(vector<int> &height,int start,int end){
//    //base case ：start >= end;
//    if (start == end) return height[start];
//    if (start > end) return 0;
//    
//    int index = findMinimunIndex(height, start, end);
//    int leftValue = largestRectangleAreaHelper(height, start, index - 1);
//    int rightValue = largestRectangleAreaHelper(height, index+1, end);
//    int wholeValue = height[index] * (end - start + 1);
//    return max(max(leftValue,rightValue),wholeValue);
//}
//int largestRectangleArea(vector<int> &height) {
//    //edge case: zero elements
//    if(height.size() == 0) return 0;
//    int start = 0;
//    int end = (int)height.size();
//    return largestRectangleAreaHelper(height, start, end);
//}
//
//void testLargestRectangleArea(){
//    vector<int> height = {4,3,4,8,8};
//    int x = largestRectangleArea(height);
//    printf("%d\n",x);
//}
//
