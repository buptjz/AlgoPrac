//
//  MultiplyStrings.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-7.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_string.h"
#include <sstream>

//更新http://leetcodenotes.wordpress.com/2013/10/20/leetcode-multiply-strings-大整数的字符串乘法/comment-page-1/#comment-122

string multiply(string num1, string num2) {
    if (num1 =="0" || num2 == "0") return "0";
    
    int l1 = (int)num1.size();
    int l2 = (int)num2.size();
    
    reverse(num1.begin(),num1.end());
    reverse(num2.begin(), num2.end());
    
    //l1位数Xl2位数 的乘机结果 <= l1+l2位数
    vector<int> digits(l1+l2,0);
    for (int i = 0; i < l1; i++)
        for (int j = 0; j < l2; j++)
            digits[i+j] += (num1[i]-'0') * (num2[j]-'0');
    
    stringstream ss;

    for (int i = 0; i < l1+l2; i++) {
        int cur = digits[i] % 10;
        int carry = digits[i] / 10;
        if (carry != 0) digits[i+1] += carry;
        char s = cur+'0';
        ss << s;
    }
    string retString = ss.str();
    reverse(retString.begin(), retString.end());
    int find = 0;
    while (retString[find] == '0')
        find++;
    return retString.substr(find,retString.size()-find);
}




//这个算法超时了！
string add_string(string num1,string num2){
    string retVal;

    
    if (num1.size() > num2.size()) {
        retVal = num1;
        num1 = num2;
        num2 = retVal;
    }
    int small_len = (int )num1.size();
    int big_len  = (int) num2.size();
    
    retVal = "";
    

    int index = 0;
    char last = 0;
    while (index < big_len) {
        char cur = num2[big_len-index-1]-'0'+last;
        if (index < small_len) cur += num1[small_len-index-1]-'0';
        last = 0;
        if (cur > 9){
            cur  = cur - 10;
            last = 1;
        }
        retVal = string(1,cur + '0') + retVal;
        index++;
    }
    if (last == 1) retVal = "1" + retVal;
    return retVal;
}

string multiply2(string num1, string num2) {
    if (num1 =="0" || num2 == "0") return "0";
    
    int l1 = (int)num1.size();
    int l2 = (int)num2.size();
    
    string retString;
    for (int i = 0 ; i < l1; i++) {
        for (int j = 0; j < l2; j++) {
            int tmp = (num1[l1-1-i]-'0') * (num2[l2-1-j]-'0');
            retString =add_string(retString,to_string(tmp) + string(i+j,'0'));
        }
    }
    
    return retString;
}

void testMultiply(){
    string a ="123";
    string b = "456";
    string ans = multiply(a, b);
    cout<<ans<<endl;
}



