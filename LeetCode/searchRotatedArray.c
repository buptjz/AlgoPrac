/*
 在一个旋转数组中找到中间那个值，要特别注意数组中可以允许重复的数字出现
 Follow up for "Search in Rotated Sorted Array":
 What if duplicates are allowed?
 
 Would this affect the run-time complexity? How and why?
 
 Write a function to determine if a given target is in the array.
 
 http://oj.leetcode.com/problems/search-in-rotated-sorted-array-ii/
 
 写了两个辅助函数，searchhelperatmost和searchhelperatleast
 比如当第一次A[mid]大于target 的时候，target可能会出现在
    1）左侧，这时target在左侧序列中后半段的递增序列上，所以在该分支上如果遇到中值大于atmost的值的时候，可以直接左侧删掉
    2）右侧，就是在后半段的递增序列上，所以在该分支上继续递归的时候，如果遇到大于atmost的时候，可以直接删掉左侧的分支
 
 但是这个想法complicated，可参见11.3的实现，更为简洁。
 */
#include <stdio.h>

int searchhelperatleat(int *A,int n,int target,int atleast){
    if (n<1) return 0;
    int mid = n >> 1;
    if (A[mid] == target) return 1;
    if (A[mid] > target) {//中间的值比要寻找的大
        //return searchhelpernormal(A,mid,target);
        return searchhelperatleat(A,mid,target,atleast);
    }else{
        if (A[mid] == atleast) {
            return searchhelperatleat(A+mid+1,n-mid-1,target,atleast) || searchhelperatleat(A,mid,target,atleast);
        }
        else if (A[mid] > atleast) {
            return searchhelperatleat(A+mid+1,n-mid-1,target,atleast);
        }else{
            return searchhelperatleat(A,mid,target,atleast);
        }
        
    }
}

int searchhelperatmost(int *A,int n,int target,int atmost){
    if (n<1) return 0;
    int mid = n >> 1;
    if (A[mid] == target) return 1;
    if (A[mid] > target) {//中间的值比要寻找的大
        if (A[mid] == atmost) {//数组中有重复的情况，不能删掉任何一个分支
            return searchhelperatmost(A,mid,target,atmost)|| searchhelperatmost(A+mid+1,n-mid-1,target,atmost);
        }
        if (A[mid] < atmost) {
            return searchhelperatmost(A,mid,target,atmost);
        }else{
            return searchhelperatmost(A+mid+1,n-mid-1,target,atmost);
        }
    }else{
        //        return searchhelpernormal(A+mid+1,n-mid-1,target);
        return searchhelperatleat(A+mid+1,n-mid-1,target,atmost);
    }
}
int search(int A[], int n, int target) {
    if(A == NULL || n <1) return 0;
    int mid = n >> 1;
    if(A[mid] == target) return 1;
    if (A[mid] > target) {
        return searchhelperatmost(A+mid+1,n-mid-1,target,A[mid]) || search(A,mid,target);
    }else{
        return searchhelperatleat(A,mid,target,A[mid]) || search(A+mid+1,n-mid-1,target);
    }
}


