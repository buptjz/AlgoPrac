//
//  MaxPointsonaLine2.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-17.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  https://oj.leetcode.com/problems/max-points-on-a-line/

#include "leetcode_others.h"

int maxPoints(vector<Point> &points) {
    int max = 0;
    float slope;
    map<float, int> hashMap;
    for(int i = 0; i < (int)points.size(); i++){
        hashMap.clear();
        int vertical = 0;
        int base = 1;
        for (int j = i + 1; j < (int)points.size(); j++) {
            if (points[i].y == points[j].y && points[i].x == points[j].x) {
                base ++;
                continue;
            }
            
            if (points[i].y == points[j].y) {
                vertical ++;
                continue;
            }
            
            slope = float(points[i].x - points[j].x) / float(points[i].y - points[j].y);
            if (hashMap.find(slope) == hashMap.end()) {
                hashMap[slope] = 1;
            }else{
                hashMap[slope] += 1;
            }
        }
        max = (max < vertical + base) ? (vertical + base) : max;
        int tmp;
        map<float, int>::iterator it = hashMap.begin();
        for (; it != hashMap.end(); it++) {
            tmp = (*it).second + base; // plus the point itself
            max = max < tmp ? tmp : max;
        }
    }

    return max;
}
