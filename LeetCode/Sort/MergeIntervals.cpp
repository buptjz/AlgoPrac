//
//  MergeIntervals.cpp
//  Algorithms
//
//  Created by WangJZ on 14-3-27.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/merge-intervals/

/*在本地执行没有问题，在leetcode上遇到http://www.cnblogs.com/qianye/archive/2013/09/12/3316028.html所述的问题
原因：不能把compare函数作为一个类的成员变量，因为成员变量默认还有this指针，与vector需要的cmp函数不匹配
 解决方法是让compare放在类外或者作为静态方法
 
*/

#include "leetcode_sort.h"

bool intCompare(const Interval &lhs,const Interval &rhs){
    if (lhs.start == rhs.start) return lhs.end < rhs.end ? true:false;
    else return lhs.start < rhs.start ? true : false;
}

vector<Interval> merge(vector<Interval> &intervals) {
    vector<Interval> retVec;
    size_t length = intervals.size();
    if (length == 0) return retVec;
    sort(intervals.begin(),intervals.end(),intCompare);
    Interval last,cur;//分别指向上一个interval和当前interval
    last = intervals[0];
    
    //遍历，进行合并
    for (int i = 1; i < length; i++) {
        cur = intervals[i];
        if (cur.start <= last.end) {//有overlap的部分，合并
            last.end = max(last.end,cur.end);
        }else{//没有overlap的部分
            retVec.push_back(last);
            last = cur;
        }
    }
    retVec.push_back(last);
    return retVec;
}

void testMerge(){
    vector<Interval> x;
    x.push_back(Interval(3,4));
    x.push_back(Interval(3,5));
    x.push_back(Interval(2,7));
    x.push_back(Interval(0,0));
    vector<Interval> res = merge(x);
    printf("Finished\n");
}