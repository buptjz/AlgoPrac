//
//  MaximalRectangle.cpp
//  LeetCode
//
//  Created by WangJZ on 3/8/14.
//  Copyright (c) 2014 WangJZ. All rights reserved.
//

#include "MaximalRectangle.h"
#include <vector>
#include <stack>

using namespace std;
int largestRectangleAreaJZ(vector<int> &height) {
    
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

void computeHistogram(vector<vector<char> > &matrix,vector<vector<int>> &histogram){
    int row = (int)matrix.size();
    int col = (int)matrix[0].size();
    char currentMatrixValue;
    for (int i = 0; i < row; i++) {
        vector<int> height = vector<int>(col,0);
        for (int j = 0; j < col; j++) {
            //1）如果上方的单元是0或者是首行，本cell与matrix相同
            //2) 如果不是首行，上方的单元不是0：（1）matrix是0，本单元是0；（2）matrix不是0，本单元 = 上方单元 + 1；
            currentMatrixValue = matrix[i][j];
            if (i == 0 ||  currentMatrixValue== '0') {
                height[j] = (currentMatrixValue == '0'? 0:1);
            }else{
                if (currentMatrixValue == 0) {
                    height[j] = 0;
                }else{
                    height[j] = histogram[i-1][j] + 1;
                }
            }
        }
        histogram.push_back(height);
    }
}


int maximalRectangle(vector<vector<char> > &matrix) {
    int maxVal = 0;
    int currentVal = 0;
    int row = (int)matrix.size();
    //base case
    if (row == 0) {
        return 0;
    }
    vector<vector<int>> histogram;
    computeHistogram(matrix,histogram);

    for (int i = 0; i < row; i++) {
        currentVal = largestRectangleAreaJZ(histogram[i]);
        if (currentVal > maxVal) {
            maxVal = currentVal;
        }
    }
    return maxVal;
}

void testMaximalRectangle(){
    vector<vector<char>> myMat= {{'1','1','1'},{'1','1','0'}};
    int res = maximalRectangle(myMat);
    printf("Finished %d\n",res);
    
}






