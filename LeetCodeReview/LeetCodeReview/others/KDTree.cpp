//
//  KDTree.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-4.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "KDTree.h"
#include <vector>

//自己写 kd 树      2014-9-4

using namespace std;
class kdTree{
private:
    int calculateVariance(vector<vector<int>> &dataSet,int index);
    int findSplitIndex(vector<vector<int>> &dataSet);
    void sortDataSet(vector<vector<int>> &dataSet,int index);
    
public:
    vector<int> data;
    int split;
    kdTree *left,*right,*parent;
    
    //根据数据集 创建kd树
    void buildKDTree(vector<vector<int>> &dataSet){
        if (dataSet.size() == 0) return;
        this->split = findSplitIndex(dataSet);
        sortDataSet(dataSet, this->split);
        int middle = (int)dataSet.size() / 2;
        this->data = dataSet[middle];
        if (middle > 0) {
            this->left = new kdTree();
            this->left->parent = this;
            vector<vector<int>> leftDataSet(dataSet.begin(),dataSet.begin() + middle - 1);
            this->left->buildKDTree(leftDataSet);
        }
        if (middle < (int)dataSet.size()) {
            this->right = new kdTree();
            this->right->parent = this;
            vector<vector<int>> leftDataSet(dataSet.begin() + middle + 1,dataSet.end());
            this->right->buildKDTree(leftDataSet);
        }
    }
};

