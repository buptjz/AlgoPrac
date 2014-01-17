//
//  searchInMatrix.c
//  CiCT
//
//  11.6
//
//  Given an MX N matrix in which each row and each column is sorted in ascending order, write a method to
//  find an element.
//  【思路】从右上角开始找起，如果小于右上角的元素，向左走一格，如果大于右上角，向下走，O(长+高)
//  【问题】：下面这段代码会在最后一行出问题
//int a[4][5] ={1,2,3,4,5,2,3,4,6,7,3,4,5,8,9,4,7,8,9,10};
//int **b = a;
//int test = b[0][0];

#include <stdio.h>
#include "arrayAndString.h"

void searchInMatrix(int matrix[][5],int width,int height,int target,int *pos_x,int *pos_y){
    //查找到的位置会返回给*pos_x和*pos_y,如果没有找到，返回(-1,-1)
    if (matrix == NULL) return ;
    int x1 = 0;
    int x2 = width - 1;
    while (x2 >= 0 && x1 <= height - 1) {//确保x和y在矩形内
        if (target == *(*(matrix+x1)+x2)){
            //case1: 找到了
            *pos_x = x2;
            *pos_y = x1;
            return;
        }else if(target < matrix[x1][x2]){
            //case2:target要小，在左侧的一个位置去找
            x2--;
        }else{
            //case2:target要大，在下方的一个位置去找
            x1++;
        }
    }
    *pos_x = -1;
    *pos_y = -1;
}

void testSearchInMatric(){
    int a[4][5] ={1,2,3,4,5,2,3,4,6,7,3,4,5,8,9,4,7,8,9,10};
    //显示数组
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
//    //int a[4][5] ={1,2,3,4,5,2,3,4,6,7,3,4,5,8,9,4,7,8,9,10,};
//    //int **b = a;
//    //int test = b[0][0];
    
    int x,y;//用来保存搜索到的位置
    searchInMatrix(a,5,4,8,&x,&y);
    printf("find in (%d,%d)\n",x+1,y+1);
}

