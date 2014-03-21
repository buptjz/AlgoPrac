//
//  MergekSortedLists .cpp
//  CiCT
//
//  http://oj.leetcode.com/problems/merge-k-sorted-lists/
//  目前状态,通过

#include "leetcode_list.h"

//新版本，时间复杂度是O(N*logK)
/*
    使用小顶堆保存k个数，每次拿出并塞进一个
 STL中优先级队列简介http://www.cppblog.com/darren/archive/2009/06/09/87224.html
 可以看到实际使用的时候与stack很想，只是初始化的时候要制定container和cmp函数
 */

struct cmp{
    bool operator()(ListNode* t1,ListNode* t2)
    {
        if ( !t1 || !t2 )
            return !t2;
        return t1->val > t2->val;
    }
};

ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.empty()) return NULL;
    int k = (int)lists.size();//求k路归并的k是多少
    
    priority_queue<ListNode* ,vector<ListNode* >,cmp> Q;
    for(int i = 0;i < k;i++){
        if ( lists[i] != NULL){
            Q.push(lists[i]);
        }
    }
    ListNode guard(-1);
    ListNode *tail = &guard;
    while(!Q.empty())
    {
        ListNode* toAdd = Q.top();
        Q.pop();
        tail->next = toAdd;
        tail = tail->next;
        if (toAdd->next) Q.push(toAdd->next);//如果新加入的Node还指向另一个指针，那么把新的指针加入到堆中来
    }
    return guard.next;
}


//老版本，时间复杂度是O(kn)
ListNode *mergeKLists2(vector<ListNode *> &lists) {
    ListNode *res = (ListNode *)malloc(sizeof(ListNode));//返回的链表
    int k = (int)lists.size();//求k路归并的k是多少
    
    //创建k个指针分别指向k路的第一个node
    ListNode **pp = (ListNode **)malloc(sizeof(ListNode*)*k);
    for (int i = 0 ; i < k; i++) {
        pp[i] = lists[i];
    }
    while (true) {
        ListNode *small;
        for (int i = 0; i < k; i++) {
            if (pp[i] != NULL) {
                if (small == NULL && small->val < pp[i]->val) {
                    small = pp[i];
                }
                pp[i] = pp[i]->next;
            }
        }
        if(small == NULL){
            break;
        }else{
            res->next = small;
        }
    }
    return res->next;
}


