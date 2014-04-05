//
//  Candy.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-5.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/candy/

/*
 ugly code 考虑到非常多的细节
 总体思路是判断上升下降转折点，
 上升点从1开始，只要一直上升，就一直加上连续上升的数量
 一旦从上升状态变为下降，则令第一个下降的点为第一点，设为1，之后一直下降的话，每次都加上连续下降的数量
 由下降变为上升是最关键的地方，因为，我们令第一个下降点为1，而第一个下降点之前的点本身是有一个值的，如果这个值很大，那么是可以的，如果这个值比它后面连续下降的串的数量要小，那么要改变它的值
 比如说
  6 7 4 3 2 1 3
 对应为
 [1 2 4 3 2 1 2 ]
可以看到数字7是第一个下降点之前的点，它本身发到两块糖，但由于后面连续的下降子串数量大于4，所以accum上面要加上3个糖
 
 */

#include "leetcode_dp.h"

int candy(vector<int> &ratings) {
    if (ratings.size() == 0) return 0;
    if (ratings.size() == 1) return 1;
    int first_value = 1;
    int accum = 1;
    int lasting = 1;
    bool is_up = true;
    bool succesive_equal = true;
    for (int i = 1; i < ratings.size(); i++) {
        if (ratings[i] == ratings[i-1]) {//same to last
            if (is_up == false && first_value <= lasting && !succesive_equal)
                accum += lasting - first_value + 1;
            succesive_equal = true;
            lasting = 1;
            accum += lasting;
            is_up = true;
            first_value = 1;//no need to calculate first value
        }else if(ratings[i] > ratings[i-1]){//上升
            succesive_equal = false;
            if(is_up == true){//持续上升
                lasting += 1;
                first_value = lasting;//记住这个第0个下降的点
                accum += lasting;
            }else{//由下降转上升
                if (first_value <= lasting) accum += lasting - first_value + 1;
                lasting = 2;
                accum += lasting;
                first_value = lasting;//记住这个第0个下降的点
                is_up = true;
            }
        }else{//下降
            succesive_equal = false;
            if (is_up == false) {//一直是下降的
                lasting += 1;
                accum += lasting;
            }else{//右上升转下降
                is_up = false;
                lasting = 1;
                accum += lasting;
            }
        }
    }
    if (is_up == false && first_value <= lasting) accum += lasting - first_value + 1;
    return accum;
}

void testCandy(){
    vector<int > A ={1,2,2};
    int res = candy(A);
    cout<<res<<endl;
}