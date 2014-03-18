/*
 在两个排序好的数组中找到中间的那个值
 目前没有完成
 */

#include <stdio.h>
#include "functions.h"

double findMedianSortedArrays(int A[], int m, int B[], int n) {
    if(m == 0) return (n % 2) ? B[n>>1] : ((B[n>>1] + B[(n>>1)-1]) / 2.0);
    else if (n == 0) return (m % 2) ? A[m>>1] : ((A[m>>1] + A[(m>>1)-1]) / 2.0);
    
    int *a1,*a2;
    int x,y,s2,e2,t1,t2;
    if(m>n){
        a1 = A;
        a2 = B;
        x = m;
        y = n;
    }else{
        a1 = B;
        a2 = A;
        x = n;
        y = m;
    }
    s2 = 0;
    e2 = y-1;
    while(s2<=e2){
        t2 = s2 + ((e2 - s2) >> 1);//求s2和e2的均值，找到中间位置的索引
        t1 = ((x+y-2)>>1) - t2;//t1+t2=(x+y-2)/2
        if(a2[t2] == a1[t1]) return a2[t2];
        if(a2[t2] < a1[t1]){
            s2 = t2 + 1;
        }else{
            e2 = t2 - 1;
        }
    }
    if ((m+n) % 2){//奇数个
        if (a2[t2] > a1[t1+1]) {
            return a1[t1+1];
        }
        return a2[t2] > a1[t1] ? a2[t2] : a1[t1];
    }else{//偶数个
        return (a2[t2]+a1[t1]) / 2.0;
    }
}