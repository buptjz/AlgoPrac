//
//  MultiplyStrings.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-1.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/multiply-strings/

#include "leetcode_others.h"

//好一点的答案在这里，自己写的太ugly了http://blog.csdn.net/havenoidea/article/details/12086339

int data[100000];
string multiply(string num1, string num2)
{
    //预处理
    reverse(num1.begin(),num1.end());
    reverse(num2.begin(),num2.end());
    memset(data,0,sizeof(data));
    
    //计算
    size_t len1 = num1.length();
    size_t len2 = num2.length();
    int i,j;
    for(i = 0 ; i < len1; ++i)
        for(j = 0 ; j < len2; ++j)
            data[j + i] += (num1[i]-'0') * (num2[j] - '0');
    
    //调整进位
    int add = 0,temp = 0;
    while( i < len1 + len2 - 1 || add != 0){
        temp = data[i] + add;
        data[i] = temp % 10;
        add = temp / 10;
        ++i;
    }
    
    //写入最终结果
    string result;
    bool flag = 0;
    for( ; i >= 0; --i){
        if( flag == 0 && data[i] == 0){
            continue;
        }else{
            flag = 1;
            result += (char)(data[i]+'0');
        }
    }
    if(flag == 0) return "0";
    else return result;
}


void add_string(string &a,string &b)
{
    int length = (int)a.length();
    int add = 0;
    for (int i = 0; i < length; i++) {
        char temp = a[i] + b[i] + add;
        add = temp / 10;
        b[i] = temp % 10;
    }
}

string multiply2(string num1, string num2) {
    if (num1 == "0" || num2 == "0") {
        return string("0");
    }
    
    for (size_t i  = 0; i < num1.length(); i++) {
        num1[i] -= '0';
    }
    for (size_t i  = 0; i < num2.length(); i++) {
        num2[i] -= '0';
    }
    
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    int max_length = (int)num1.length() + (int)num2.length();
    num1.resize(max_length, 0);
    num2.resize(max_length, 0);
    string newNum1(max_length,0);
    string newNum2(max_length,0);
    for (int i = 0; i< num1.size(); i++) {
        newNum1[i] = num1[i];
    }
    for (int i = 0; i< num2.size(); i++) {
        newNum2[i] = num2[i];
    }
    string final(max_length,0);
    
    for (int i = 0 ; i < newNum2.length(); i++) {
        string temp(max_length,0);
        for (int j = 0; j < num1.length(); j++) {
            temp[j+i] = newNum1[j] * newNum2[i];
        }
        add_string(temp,final);
    }
    int length = max_length;
    while (length > 0) {
        if (final[length - 1] != 0) break;
        length--;
    }
    final = final.substr(0,length);
    for (int i =0; i< length; i++) {
        final[i] += '0';
    }
    reverse(final.begin(), final.end());
    return final;
}
void testMultipley(){
    string res = multiply("123", "456");
    cout<<res<<endl;
}

