//
//  SpiralMatrixII.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-6.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_others.h"

vector<vector<int> > generateMatrix(int n) {
    vector<vector<int> >ret(n,vector<int>(n,0));
    int index = 1;
    
    //cycle by cycle
    for (int cycle = 0; cycle < n/2; cycle++) {
        //row from left to right
        for (int j = 0; j <= n - 2 * cycle - 2; j++) {
            ret[cycle][cycle+j] = index;
            index++;
        }
        //column top to bottom
        for (int j = 0; j <= n - 2 * cycle - 2; j++) {
            ret[cycle+j][n - cycle - 1] = index;
            index++;
        }
        //row right to left
        for (int j = 0; j <= n - 2 * cycle - 2; j++) {
            ret[n - cycle - 1][n - cycle - 1 - j] = index;
            index++;
        }
        //column bottom to top
        for (int j = 0; j <= n - 2 * cycle - 2; j++) {
            ret[n - cycle - 1 - j][cycle] = index;
            index++;
        }
    }
    if (n % 2 != 0) ret[n/2][n/2] = index;
    return ret;
}

void testGenerateMatrix(){
    vector<vector<int> >res = generateMatrix(4);
    cout<<"Finished"<<endl;
}