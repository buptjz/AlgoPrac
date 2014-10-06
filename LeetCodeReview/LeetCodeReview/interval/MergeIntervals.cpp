//
//  MergeIntervals.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-6.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_interval.h"

/*
 Merge Intervals
 
 Given a collection of intervals, merge all overlapping intervals.
 
 For example,
 Given [1,3],[2,6],[8,10],[15,18],
 return [1,6],[8,10],[15,18].
 */

//【注意】这里必须是static 的才能用在类中，特别注意！

static bool int_compare(Interval in1,Interval in2){
    return in1.start < in2.start;
}

vector<Interval> merge(vector<Interval> &intervals) {
    vector<Interval> ret;
    if (intervals.empty()) return ret;
    sort(intervals.begin(), intervals.end(), int_compare);
    
    Interval last = intervals[0];
    
    for (int i = 1 ; i < intervals.size(); i++) {
        Interval cur = intervals[i];
        if (last.start == cur.start) {//(1,3) - (1,4)
            last.end = max(last.end,cur.end);
        }else{
            if (cur.start > last.end) {//(1,3) - (4,5)
                ret.push_back(last);
                last = cur;
            }else{
                if (cur.end > last.end) {//(1,3) - (2,5)
                    last.end = cur.end;
                }else{//(1,4) - (2,3)
                    ;
                }
            }
        }
    }
    ret.push_back(last);
    
    return ret;
}
