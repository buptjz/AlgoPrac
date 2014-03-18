
//
//  LargestRectangularAreainaHistogramV2.cpp
//  LeetCode
//
//  Created by WangJZ on 3/8/14.
//  Copyright (c) 2014 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/largest-rectangle-in-histogram/

#include "LargestRectangularAreainaHistogramV2.h"
#include <vector>

#include <stdio.h>
#include <math.h>
#include <limits.h>

/*
 
 参考了 http://www.geeksforgeeks.org/largest-rectangular-area-in-a-histogram-set-1/
 与版本1相比，用了segment tree，时间复杂度稳定在O(nLogn)
 状态是通过，耗时是116ms
 
 */
using namespace std;

int *seg_tree;
// A utility function to get minimum of two numbers
int minVal(vector<int>&vec,int x, int y){
    if (x == -1) return y;
    if (y == -1) return x;
    return (vec[x] < vec[y])? x : y;
}

// A utility function to get the middle index from corner indexes.
int getMid(int s, int e) {  return s + (e -s)/2;  }

/*  A recursive function to get the minimum value in a given range of array
 indexes. The following are parameters for this function.
 
 st    --> Pointer to segment tree
 index --> Index of current node in the segment tree. Initially 0 is
 passed as root is always at index 0
 ss & se  --> Starting and ending indexes of the segment represented by
 current node, i.e., st[index]
 qs & qe  --> Starting and ending indexes of query range */
int RMQUtil(vector<int>&vec,int *st, int ss, int se, int qs, int qe, int index)
{
    // If segment of this node is a part of given range, then return the
    // min of the segment
    if (qs <= ss && qe >= se)
        return st[index];
    
    // If segment of this node is outside the given range
    if (se < qs || ss > qe)
        return -1;
    
    // If a part of this segment overlaps with the given range
    int mid = getMid(ss, se);
    return minVal(vec,RMQUtil(vec,st, ss, mid, qs, qe, 2*index+1),
                  RMQUtil(vec,st, mid+1, se, qs, qe, 2*index+2));
}

// Return minimum of elements in range from index qs (quey start) to
// qe (query end).  It mainly uses RMQUtil()
int RMQ(vector<int>&vec,int *st, int n, int qs, int qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }
    
    return RMQUtil(vec,st, 0, n-1, qs, qe, 0);
}

// A recursive function that constructs Segment Tree for array[ss..se].
// si is index of current node in segment tree st
int constructSTUtil(vector<int> &vec, int ss, int se, int *st, int si)
{
    // If there is one element in array, store it in current node of
    // segment tree and return
    if (ss == se)
    {
        st[si] = ss;
        return ss;
    }
    
    // If there are more than one elements, then recur for left and
    // right subtrees and store the minimum of two values in this node
    int mid = getMid(ss, se);
    st[si] =  minVal(vec,constructSTUtil(vec, ss, mid, st, si*2+1),
                     constructSTUtil(vec, mid+1, se, st, si*2+2));
    return st[si];
}

/* Function to construct segment tree from given array. This function
 allocates memory for segment tree and calls constructSTUtil() to
 fill the allocated memory */
int *constructST(vector<int> &vec)
{
    // Allocate memory for segment tree
    int x = (int)(ceil(log2((int)vec.size()))); //Height of segment tree
    int max_size = 2*(int)pow(2, x) - 1; //Maximum size of segment tree
    int *st = new int[max_size];
    
    // Fill the allocated memory st
    constructSTUtil(vec, 0, (int)vec.size()-1, st, 0);
    
    // Return the constructed segment tree
    return st;
}

int findMinimunIndex(vector<int> &height,int start,int end){
    return RMQ(height, seg_tree, (int)height.size(), start, end);
}

int largestRectangleAreaHelper(vector<int> &height,int start,int end){
    //base case ：start >= end;
    if (start == end) return height[start];
    if (start > end) return 0;
    
    int index = findMinimunIndex(height, start, end);
    int leftValue = largestRectangleAreaHelper(height, start, index - 1);
    int rightValue = largestRectangleAreaHelper(height, index+1, end);
    int wholeValue = height[index] * (end - start + 1);
    return max(max(leftValue,rightValue),wholeValue);
}
//int largestRectangleArea(vector<int> &height) {
//    
//    //edge case: zero elements
//    if(height.size() == 0) return 0;
//    int start = 0;
//    int end = (int)height.size() - 1;
//    seg_tree = constructST(height);//build segment tree with a vector
//    return largestRectangleAreaHelper(height, start, end);
//}

//void testLargestRectangleArea(){
//    vector<int> height = {1,2,3,4,5,6,7,8,9,10};
//    int x = largestRectangleArea(height);
//    printf("%d\n",x);
//}
