//
//  InsertInterval.cpp
//  Algorithms
//
//  Created by WangJZ on 14-3-27.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://www.programcreek.com/2012/12/leetcode-insert-interval/

/*
 借鉴了http://www.programcreek.com/2012/12/leetcode-insert-interval/，核心思想是不断的更改newInterval
 其思想是：保证下一次能处理一样的数据
*/
#include "leetcode_sort.h"

/*----2014.3.27日更新----*/
vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> retVec;
    int length = (int)intervals.size();
    for (int i = 0; i < length ; i++) {
        //分三种情况
        if (intervals[i].end < newInterval.start) {
            retVec.push_back(intervals[i]);
        }else if(intervals[i].start > newInterval.end){
            retVec.push_back(newInterval);
            newInterval = intervals[i];
        }else if(intervals[i].end >= newInterval.start){
            newInterval = Interval(min(intervals[i].start,newInterval.start),max(intervals[i].end,newInterval.end));
        }
    }
    retVec.push_back(newInterval);
    return retVec;
}


int binarySearch(vector<Interval>&intervals,int target){
    if (intervals.size() == 0) {
        return 0;
    }
    int start = 0;
    int end = (int)intervals.size() - 1;
    int mid;
    while (start <= end) {
        mid = start + ((end - start) >> 1);
        if (intervals[mid].start == target) return mid;
        else if(intervals[mid].start < target) start = mid + 1;
        else end = mid - 1;
    }
    return start;
}

vector<Interval> insert2(vector<Interval> &intervals, Interval newInterval) {
    Interval last;
    int ist = binarySearch(intervals, newInterval.start);
    vector<Interval> retInt;
    if (ist == 0 ) {
        last = newInterval;
    }else{
        retInt = vector<Interval>(intervals.begin(),intervals.begin()+ist);
        if(newInterval.start > intervals[ist - 1].end){//如果新插入的interval和前一个没有交叠，那么把它作为新的last
            retInt = vector<Interval>(intervals.begin(),intervals.begin()+ist);
            last = newInterval;
        }else{//如果新插入的interval和前一个有交叠，那么和前一个合并作为lastone
            retInt = vector<Interval>(intervals.begin(),intervals.begin()+ist - 1);
            intervals[ist - 1].end = max(intervals[ist - 1].end,newInterval.end);
            last = intervals[ist - 1];
        }
    }

    //将后续的内容一次放入数组中
    for (size_t i = ist; i < intervals.size(); i++) {
        if (intervals[i].start <= last.end) {//合并
            last.end = max(last.end,intervals[i].end);
        }else{
            retInt.push_back(last);
            last = intervals[i];
        }
    }
    retInt.push_back(last);
    return retInt;
}

void testIntervalInsert(){
    vector<Interval> val;
    val.push_back(Interval(1, 5));
    val.push_back(Interval(6, 8));
    vector<Interval> res = insert(val, Interval(0, 3));
    printf("finished\n");
}

