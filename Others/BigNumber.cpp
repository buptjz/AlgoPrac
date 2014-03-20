//
//  BigNumber.cpp
//  Algorithms
//
//  Created by WangJZ on 14-3-20.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  写一个大数类，能够完成超出longlong 表示的加减乘除

//  【教程】http://dhcp.tcgs.tc.edu.tw/c/p019.htm

#include "BigNumber.h"
#include <strings.h>
#define LENGTH 300
int big_input(char big[]);
void big_print(char big[]);

/*
 输入，正确返回0，不正确返回-1
 
 把該陣列的每一格數字歸零。
 將使用者輸入的數字以字串方式存到另一個字串。
 計算該字串的長度。
 從該字串的尾端(即個位數)開始一個一個位數往左，將它轉換成數字後，存到陣列對應的格子中。

 */
int big_input(char big[]){
    char temp[LENGTH];
    
    for (int i = 0; i < LENGTH; i++) {//初始化
        big[i] = 0;
    }
    if(scanf("%s",temp) < 1) return -1;//非法输入，出错
    int l = (int)strlen(temp);
    for (int i = 0; i < l; i ++) {
        big[i] = temp[l-1-i] - '0';
    }
    return 0;
}

/*打印输出
 
 從該陣列最後面往回找到第一個不是 0 的數字。
 從該位數字往左邊依序把它們一個一個印出來。
 印出換行符號。

 */
void big_print(char big[]){
    int i;
    for (i = LENGTH - 1; i >= 0; i--) {
        if (big[i] != 0) {
            break;
        }
    }
    for (; i >= 0; i--) {
        printf("%d",big[i]);
    }
    printf("\n");
}

/*
 大數相加
 */
void big_add(char big_a[],char big_b[],char big_c[]){
    for (int i = 0; i < LENGTH; i++) {
        big_c[i] = big_a[i] + big_b[i];
    }
    for (int i = 0; i < LENGTH; i++) {
        if (big_c[i] > 9) {
            big_c[i+1] += big_c[i] / 10;
            big_c[i] =  big_c[i] % 10;
        }
    }
}

/*
 大數相乘
 */
void big_mul(char big_a[],char big_b[],char big_c[]){
    for (int i = 0; i < LENGTH; i++) {
        big_c[i] = 0;
    }
    //将a中的每一位和b中的每一位相乘，将结果存在c中
    for (int i = 0; i < LENGTH; i++) {
        for(int j = 0; j < LENGTH; j++){
            big_c[i+j] += (big_a[i] * big_b[j]);
            if (big_c[i+j] > 10) {
                big_c[i+j+1] += big_c[i+j] / 10;
                big_c[i+j] =  big_c[i+j] % 10;
            }
        }
    }
}


void testBigNumber(){
    char big_a[LENGTH],big_b[LENGTH],big_c[LENGTH];
    big_input(big_a);
    big_print(big_a);
    big_input(big_b);
    
    big_mul(big_a, big_b, big_c);
    big_print(big_c);
}