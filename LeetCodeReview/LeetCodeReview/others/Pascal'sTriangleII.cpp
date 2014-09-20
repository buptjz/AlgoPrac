//
//  Pascal'sTriangleII.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-20.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_others.h"

vector<int> getRow(int rowIndex) {
    //retVec has (rowIndex + 1) element
    vector<int> retVec(rowIndex + 1,1);
    if (rowIndex <= 0) return retVec;
    
    for (int row = 1; row <= rowIndex; row++) {
        for (int j = row - 1; j >= 1; j--)
            retVec[j] = retVec[j] + retVec[j - 1];
    }
    
    return retVec;
}
