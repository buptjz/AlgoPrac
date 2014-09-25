//
//  MaximumProductSubarray.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-24.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_others.h"

int maxProduct(int A[], int n) {
    if (n == 0) return 0;
    if (n == 1) return A[0];
    
    vector<int> result;
    vector<pair<int, int>> ranges;
    
    //find ranges
    int start = 0;
    int end = n - 1;
    for (int i = 0; i < n; i++) {
        if (A[i] == 0) {
            end = i - 1;
            if (start <= end) ranges.push_back(make_pair(start, end));
            start = i + 1;
            end = n - 1;
        }
    }
    if (start <= end) ranges.push_back(make_pair(start, end));

    int maxProduct = 0;
    for (pair<int, int> p : ranges) {
        start = p.first;
        end = p.second;
        int numOfMinus = 0;
        for (int i = start; i <= end; i++)
            if(A[i] < 0) numOfMinus++;
        
        int curMax = 1;
        if (numOfMinus % 2 == 0){//偶数个负数，直接相乘
            for (int i = start; i <= end; i++)
                curMax *= A[i];
            maxProduct = max(maxProduct,curMax);
        }else{//奇数个负数，第一个负数右边的数相乘，和最后一个数的左边的数连乘相比较
            int copyNumOfMinus = numOfMinus;
            int leftMax = 1,rightMax = 1;
            if(start == end){
                maxProduct = max(maxProduct,A[start]);
                continue;
            }
            for (int i = start; i <= end; i++) {
                if (A[i] < 0) {
                    copyNumOfMinus--;
                    if (copyNumOfMinus == 0) break;
                }
                leftMax *= A[i];
            }
            copyNumOfMinus = numOfMinus;
            for (int i = end; i >= start; i--) {
                if (A[i] < 0) {
                    copyNumOfMinus--;
                    if (copyNumOfMinus == 0) break;
                }
                rightMax *= A[i];
            }
            maxProduct = max(max(rightMax,leftMax),maxProduct);
        }
    }
    return maxProduct;
}

void testMaxProduct(){
    int a[2] = {-4,-3};
    cout << maxProduct(a, 2) << endl;
}



