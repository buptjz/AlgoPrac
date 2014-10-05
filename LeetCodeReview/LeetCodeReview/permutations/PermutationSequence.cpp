//
//  PermutationSequence.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-5.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_permute.h"


/*2014年10月5日更新，写的丑陋啊，再看别人的写法！*/

int getOrderOne(int order,vector<bool> &appear){
    int local_order = 1;
    for (int i = 0; i < appear.size(); i++) {
        if (appear[i] == false) {
            if (local_order == order) {
                return i+1;
            }else{
                local_order++;
            }
        }
    }
    return -1;
}


string getPermutation(int n, int k) {
    vector<bool> appear(n,false);
    vector<int> num(n+1,1);
    vector<int> res;
    
    for (int i = 1 ; i <= n; i++) {
        num[i] = num[i-1] * i;
    }
    
    for (int i = 0; i < n; i++) {
        int order =  (k-1) / num[n-i-1] + 1;
        k = k - (order - 1) * num[n-i-1];
        if (k == 0) k = 1;
        int tmp = getOrderOne(order,appear);
        res.push_back(tmp);
        appear[tmp - 1] = true;
    }
    
    string ret;
    for (int x : res)
        ret += to_string(x);
    return ret;
}


//采用next permutation的方式超时了！
void getNextPermute(vector<int> &a){
    int len = (int)a.size();
    //step 1 : find the first inorder pair from last
    //step 2 : swap the 2
    //step 3 : reverse the last from the 1st +1 idnex
    
    int bigIndex = -1;
    int smallIndex = -1;
    for (int i = len - 2; i >= 0 ; i--){
        if (a[i] < a[i+1]){
            smallIndex = i;
            break;
        }
    }
    
    if (smallIndex != -1) {
        for (int i = len - 1; i >=0; i--){
            if (a[i] > a[smallIndex]){
                bigIndex = i;
                break;
            }
        }
        swap(a[smallIndex], a[bigIndex]);
        reverse(a.begin()+smallIndex+1, a.end());
    }
}

string getPermutation_old(int n, int k) {
    vector<int> tmp;
    for (int i = 0; i < n; i++) {
        tmp.push_back(i+1);
    }
    
    for (int i = 1; i < k; i++)
        getNextPermute(tmp);
    
    string res;
    for (int x : tmp)
        res += to_string(x);

    return res;
}

void testGetPermutation(){
    string s = getPermutation(4, 5);
    cout << s<<endl;
    
}
