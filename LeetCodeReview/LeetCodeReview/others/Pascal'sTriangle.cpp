//
//  Pascal'sTriangle.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-20.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_others.h"


vector<vector<int> > generate(int numRows) {
    vector<vector<int>> retVec;
    if (numRows <= 0) return retVec;
    
    retVec.push_back(vector<int>(1,1));
    
    for (int i = 1; i < numRows; i++) {
        vector<int> cur_layer;
        vector<int> lasy_layer = retVec[i - 1];
        
        cur_layer.push_back(1);
        for (int j = 1; j < lasy_layer.size(); j++)
            cur_layer.push_back(lasy_layer[j - 1] + lasy_layer[j]);
        cur_layer.push_back(1);
        retVec.push_back(cur_layer);
    }
    
    return retVec;
}