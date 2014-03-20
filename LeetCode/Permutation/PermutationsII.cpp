//
//  PermutationsII.cpp
//  Algorithms
//
//  Created by WangJZ on 14-3-20.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_permutation.h"

/*
 排列问题，用到了算法设计手册上讲的回溯法
 核心：
 1）算法框架要用熟
 2）排列问题实际上是找到1~n个不同出现的顺序，所以我们找寻所有情况，
 等于先把1~n这n个数排列，再通过n个数的排列计算出真正的我们需要排列的内容
 */

//bool isValidResult(vector<int> &result,int n){
//    if ((int)result.size() == n) {
//        return true;
//    }else{
//        return false;
//    }
//}
//
//void handleResult(vector<vector<int> >&res,vector<int> &currentItem,int length,vector<int>&num){
//    vector<int> item;
//    for (int i = 0; i < length; i++) {
//        item.push_back( num[currentItem[i]]);
//    }
//    res.push_back(item);
//}
//
//bool in_array(int *arr,int number,int length){
//    for (int i = 0; i < length; i++) {
//        if (arr[i] == number) {
//            return true;
//        }
//    }
//    return false;
//}
//
//void construct_candidates(vector<vector<int> >&res,
//                          vector<int> &currentItem,
//                          vector<int> &num,
//                          int level,
//                          int *ncandidates,
//                          int *candidate,
//                          int length)
//{
//    *ncandidates = length - level;
//    int candi_index = 0;
//    bool *bitmap = (bool *)malloc(sizeof(bool) * length);
//    for (int i = 0; i < length; i++) {
//        bitmap[i] = false;
//    }
//    for (int i = 0; i < level; i++) {
//        bitmap[currentItem[i]] = true;
//    }
//    //看0~length-1一共length个数中，哪个没在currentItem中出现过
//    //将没出现的放在candidate数组中
//    for (int i = 0; i < length; i++) {
//        if (bitmap[i] == false) {
//            candidate[candi_index++] = i;
//        }
//    }
//}
//void backtrack(vector<vector<int> >&res,vector<int> &currentItem,vector<int> &num,int level,int length){
//    if (isValidResult(currentItem,(int)num.size())){//如果result已经完成，退出
//        handleResult(res,currentItem,length,num);
//        return;
//    }
//    int ncandidates;
//    int *c = (int *)malloc(sizeof(int) * length);
//    construct_candidates(res,currentItem,num,level,&ncandidates,c,length);
//    for (int i=0; i < ncandidates; i++) {
//        currentItem.push_back(c[i]);
//        backtrack(res, currentItem, num, level+1,length);
//        currentItem.pop_back();
//    }
//}
//vector<vector<int> > permute(vector<int> &num) {
//    vector<vector<int> > returnValue;
//    vector<int> current;
//    backtrack(returnValue, current, num, 0,(int)num.size());
//    return returnValue;
//}
//
//vector<vector<int> > permute2(vector<int> &num) {
//    // Start typing your C/C++ solution below
//    // DO NOT write int main() function
//    int N = (int)num.size();
//    vector<vector<int> > ret;
//
//    if(N == 1){
//        ret.push_back(num);
//        return ret;
//    }
//    vector<vector<int> > post;
//
//    vector<int> cur;
//    vector<int> tmp;
//
//    for(int i = 0; i < N; i++){
//        cur = num;
//        cur.erase(cur.begin()+i);//这句话会分配一个新的地址，这也是本函数的关键！
//        post = permute2(cur);
//        for(int j = 0; j < post.size(); j++){
//            tmp = post[j];
//            tmp.insert(tmp.begin(), num[i]);
//            ret.push_back(tmp);
//        }
//    }
//    return ret;
//}
//
//int N;
//vector<vector<int>> ret;
//void perm3(vector<int> &num, int i){
//    if( i == N){
//        ret.push_back(num);
//    }
//
//    for(int j = i; j < N; j++){
//        swap(num[i], num[j]);
//        perm3(num, i + 1);
//        swap(num[j], num[i]);
//    }
//}
//
//
//vector<vector<int> > permute3(vector<int> &num) {
//    N = (int)num.size();
//    ret.clear();
//    perm3(num, 0);
//    return ret;
//
//}

static void permuteHelper(vector<vector<int>> &retVec,vector<int> &num,vector<int>&tmp,int length,vector<bool>isVisited){
    if ((int)tmp.size() == length) {
        retVec.push_back(tmp);
        return;
    }
    for (int i = 0; i < length; i++) {
        if (isVisited[i]) continue;
        tmp.push_back(num[i]);
        isVisited[i] = true;
        permuteHelper(retVec, num, tmp, length, isVisited);
        tmp.pop_back();
        isVisited[i] = false;
    }
    
}
static vector<vector<int> > permute(vector<int> &num) {
    vector<int> tmp;
    vector<vector<int>> retVec;
    int length = (int)num.size();
    vector<bool>isVisited = vector<bool>(length,false);
    permuteHelper(retVec, num, tmp, length,isVisited);
    return retVec;
}