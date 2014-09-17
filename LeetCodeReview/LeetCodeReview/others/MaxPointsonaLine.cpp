//
//  MaxPointsonaLine.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-17.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  Totally Wrong Direction

#include "leetcode_others.h"

class RecordItem{
public:
    map<Point, int> pnt_grp_map;
    map<int, vector<Point>> grp_pntLst_map;
    int accum;
    RecordItem(const Point &p1,const Point &p2){
        accum = 0;
        this->pnt_grp_map = map<Point, int>();
        this->pnt_grp_map[p1] = accum;
        this->pnt_grp_map[p2] = accum;
        this->grp_pntLst_map = map<int, vector<Point>>();
        this->grp_pntLst_map[accum] = {p1,p2};
        accum++;
    }
    
    void addPointPair(const Point &p1,const Point &p2){
        
        if (pnt_grp_map.find(p1) != pnt_grp_map.end() &&
            pnt_grp_map.find(p2) != pnt_grp_map.end()) {//1 : both in,merge
            int grpIndx1 = pnt_grp_map[p1];
            int grpIndx2 = pnt_grp_map[p2];
            vector<Point> vec1 = grp_pntLst_map[grpIndx1];
            vector<Point> vec2 = grp_pntLst_map[grpIndx2];
            
            //append to vec1 & modify value in pnt_grp_map
            for (int i = 0; i < (int)vec2.size(); i++) {
                vec1.push_back(vec2[i]);
                pnt_grp_map[vec2[i]] = grpIndx1;
            }
            //delete grpIndx2 in grp_pntLst_map
            grp_pntLst_map.erase(grp_pntLst_map.find(grpIndx2));
            
        }else if(pnt_grp_map.find(p1) != pnt_grp_map.end()){//2 : p1 in
            int grpIndx = pnt_grp_map[p1];
            pnt_grp_map[p2] = grpIndx;
            grp_pntLst_map[grpIndx].push_back(p2);
            
        }else if(pnt_grp_map.find(p2) != pnt_grp_map.end()){//3 : p2 in
            int grpIndx = pnt_grp_map[p2];
            pnt_grp_map[p1] = grpIndx;
            grp_pntLst_map[grpIndx].push_back(p1);
            
        }else{//4 : both not in
            this->pnt_grp_map[p1] = accum;
            this->pnt_grp_map[p2] = accum;
            this->grp_pntLst_map[accum] = {p1,p2};
            accum++;
        }
    }
    
    int countNumMaxGroup(){
        int max = 0,tmp;
        map<int, vector<Point>>::iterator it = grp_pntLst_map.begin();
        for (; it != grp_pntLst_map.end(); it++) {
            tmp = (int)(*it).second.size();
            max = max < tmp ? tmp : max;
        }
        return max;
    }
};



int maxPoints(vector<Point> &points) {
    map<float, RecordItem> slope_record_map;
    int slope;
    for(int i = 0; i < (int)points.size(); i++){
        for (int j = i; j < (int)points.size(); j++) {
            if (points[i].y == points[j].y) slope = INT_MAX;
            else slope =
                float(points[j].x - points[i].x) / float(points[j].y - points[i].y);
            if (slope_record_map.find(slope) == slope_record_map.end())
                slope_record_map[slope] = RecordItem(points[i],points[j]);
            else
                slope_record_map[slope].addPointPair(points[i],points[j]);
        }
    }
    map<float, RecordItem>::iterator it = slope_record_map.begin();
    int max = 0,tmp;
    for (; it != slope_record_map.end(); it++) {
        tmp = (*it).second.countNumMaxGroup();
        max = (max < tmp) ? tmp : max;
    }
    return max;
}




