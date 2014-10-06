//
//  InsertInterval.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-6.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_interval.h"

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> ret;
    bool noNeedCompare = false;
    for (Interval cur : intervals) {
        if (noNeedCompare) {
            ret.push_back(cur);
            continue;
        }
        
        if (cur.start <= newInterval.start && cur.end >= newInterval.end) {//(4,6) - (3,8)
            ret.push_back(cur);
            noNeedCompare = true;
            continue;
        }
        
        if (cur.start > newInterval.end){ //(4,6) - (7,8)
            ret.push_back(newInterval);
            ret.push_back(cur);
            noNeedCompare = true;
            continue;
        }
        if (cur.end < newInterval.start) { //(4,6) - (1,3)
            ret.push_back(cur);
            continue;
        }
            

        if (cur.end <= newInterval.end && cur.start >= newInterval.start) {//(4,6) - (5,6)
            ;
        }else{
            if (cur.start < newInterval.start) {
                newInterval.start = cur.start;
            }else{
                newInterval.end = cur.end;
            }
        
        }

    }
    if (!noNeedCompare) ret.push_back(newInterval);
    return ret;
}
