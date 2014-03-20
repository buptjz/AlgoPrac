//  Created by WangJZ on 14-3-20.


/*
 Cracking the Coding Interview 题目13.1
 用C++写个方法，打印文件最后K行
 用一个循环数组，每次读取新的一行，替换掉最早读取的一行，这样在内存中只保留k行数据
 */

#include "cict_c++.h"
#define LENGTH 1024

void printLastKLines(int k){
    FILE *file;
    char *file_path = "/Users/wangjz/Desktop/Crawler.py";
    if((file = fopen(file_path, "r"))!= NULL){
        
        char **loop_array = (char **)malloc(sizeof(char *) * k);//申请一个包含k个指针的数组
        int size = k;//数组的大小
        k = 0;//k作为当前行数
        for (int i = 0; i < size; i++) {
            loop_array[i] = (char *)malloc(sizeof(char) * 1024);
        }
        
        while (!feof(file)) {
            fgets(loop_array[k % size], LENGTH, file);
            k++;
        }
        fclose(file);
        for (int i = 0; i < size; i++) {
            printf("%s",loop_array[(k+i) % size ]);
        }
    }

}

void testPrintLastKLines(){
    printLastKLines(10);
}