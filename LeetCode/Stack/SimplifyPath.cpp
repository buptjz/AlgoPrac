//
//  SimplifyPath.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-4.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/simplify-path/

//别忘了将最后一段放入到stack中

//ref http://www.cnblogs.com/RazerLu/p/3552545.html
#include "leetcode_others.h"
#include <stack>

vector<string> total;

void addToStack(string cur){
    if (cur == "" || cur == ".") return;
    if (cur == ".."){
        if (total.size() > 0)total.pop_back();
    }else {
       total.push_back(cur);
    }
}

string simplifyPath(string path) {
    int length = (int)path.size();
    string cur = "";
    for (int i = 0; i < length; i++) {
        if (path[i] == '/') {
            addToStack(cur);
            cur = "";
        }else{
            cur+= path[i];
        }
    }
    addToStack(cur);//Do not forget the last one
    if (total.size() == 0) return "/";
    string ret;
    for (int i = 0; i < total.size(); i++)
        ret +="/"+total[i];
    return ret;
}

void testSmplifyPath(){
    string res = simplifyPath("/a/./b/../../c/");
    cout<<res<<endl;
}
