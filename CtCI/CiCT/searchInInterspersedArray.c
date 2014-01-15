//
//  searchInInterspersedArray.c
//  CiCT
//
//  11.5
//  Given a sorted array of strings which is interspersed with empty strings,
//  write a method to find the location of a given string.
//
//  【思路】如果这里没有空白string的话，那么就是一个二分查找了。
//  依然按照二分查找的方式进行查询，如果有空字符串的话，分别向两边查找，直到找到非空的字符串，再继续二分查找

#include "arrayAndString.h"
#include <stdio.h>
#include <string.h>

int searchInArray(char **A,int start,int end,char *target){
    if (strcmp(target, "") == 0) return -1; //边界情况，要查找的字符串是空串
    if (A == NULL || start > end) return -1;
    int mid = start + ((end - start) >> 1);
    if (strcmp(A[mid], "") == 0) {//A[mid]是空字符串
        int left = mid - 1;
        int right = mid + 1;
        while (1) {
            if (left < start && right > end) return -1;//两边都越界了，返回没找到
            else if(left >= start && (strcmp(A[left], "") != 0)){//左边没有越界，而且A[left]非空字符串
                mid = left;
                break;
            }else if(right <= end && (strcmp(A[right], "") != 0)){//右边没有越界，而且A[right]非空字符串
                mid = right;
                break;
            }
            left --;
            right ++;
        }
    }
    int res = strcmp(A[mid], target);
    if (res == 0) return mid;
    else if (res > 0) return searchInArray(A, start, mid - 1, target);
    else return searchInArray(A, mid + 1, end, target);
}

void testSearchInArray(){
    char *A[12] = {"abc","","","bar","bbb","","","","car","cube","zzz",""};
    int res = searchInArray(A, 0, 11, "car");
    printf("Expected %d, Got %d\n",8,res);
    
    char *B[12] = {"abc","","","","","","","","car","cube","zzz",""};
    int res2 = searchInArray(B, 0, 11, "zzz");
    printf("Expected %d, Got %d\n",10,res2);
}
