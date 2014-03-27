//
//  PowXN.cpp
//  Algorithms
//
//  Created by WangJZ on 14-3-26.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_others.h"

/*2014.3.27日更新
 1）考虑到非法输入：0的0幂 或0的负次幂
2）使用unsigned int 来避免溢出
 */
bool invalid = false;
bool isEqual(double x,double y){
    return ((x - y) * (x - y) < 0.00001) ? true:false;
}
double powHelper(double x, unsigned int n){
    if (n == 1) return x;//base case
    double result;
    result = powHelper(x, n / 2);
    result = result * result;
    if (n & 1) result *= x;
    return result;
}

double pow2(double x, int n) {
    if (n <= 0 && isEqual(x,0.0)) {//0的0次方没有意义
        invalid = true;
        return 0;
    }else if(n == 0) return 1;
    if (n > 0) {
        return powHelper(x,n);
    }else{
        return 1.0/powHelper(x, (unsigned int)-n);
    }
}

/**原始信息**/

double pow(double x, int n) {
    if(n == 0) return 1;
    if(n == 1) return x;
    if(n == -1) return 1.0 / x;
    double result;
    result = pow(x, abs(n)/2);
    if (n % 2 == 0) {//偶数
        result *= result;
    }else{//奇数
        result = result * result * x;
    }
    return n > 0? result: (1.0/result);
}

void testPow(){
    double res = pow2(-1, -2147483648);
    printf("%20.10f\n",res);
    printf("%d\n",1<<31);
}