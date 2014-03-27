//
//  question12.cpp
//  Algorithms
//
//  Created by WangJZ on 14-3-27.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

/*剑指offer第11题
 打印打印1~最大n位数
 */

#include "conquerOffer.h"

//n+1个位置，从0~n-1表示数，n表示最高+1位，如果该为是1，表示溢出了，位置n+1是'\0'
void printBigNumber(char *bignumber,int n){
    int last = n - 1;
    for (; last >= 0; last--) {
        if (bignumber[last]!= 0) {
            break;
        }
    }
    for (; last >= 0; last--) {
        printf("%d",bignumber[last]);
    }
    printf("\n");
}

bool inCrementNumber(char *bignumber,int n){
    bignumber[0] += 1;
    int cur = 0;
    while (bignumber[cur] > 9) {
        bignumber[cur] -= 10;
        bignumber[++cur] += 1;
    }
    if (bignumber[n] == 1) {
        return false;
    }else{
        return true;
    }
}

void Print1ToMaxofNDigits(int n){
    char *bigNumber = new char[n+2];
    memset(bigNumber,0,n);
    bigNumber[n+1] = '\0';
    while (true) {
        if (!inCrementNumber(bigNumber,n)) {
            break;
        }
        printBigNumber(bigNumber,n);
    }
}

void testPrint1ToMaxofNDigits(){
    Print1ToMaxofNDigits(4);
}