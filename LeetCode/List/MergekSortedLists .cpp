//
//  MergekSortedLists .cpp
//  CiCT
//
//  http://oj.leetcode.com/problems/merge-k-sorted-lists/
//  目前状态


#include "leetcode_list.h"

using namespace std;


struct cmp{
    bool operator()(ListNode* t1,ListNode* t2)
    {
        if ( !t1 || !t2 )
            return !t2;
        return t1->val>t2->val;
    }
};


ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.empty()) return NULL;
    int k = (int)lists.size();//求k路归并的k是多少
    
    priority_queue<ListNode*,vector<ListNode*>,cmp> Q;
    for(int i = 0;i < k;i++){
        if ( lists[i] != NULL){
            Q.push(lists[i]);
        }
    }
    ListNode guard(-1);
    ListNode* tail=&guard;
    while(!Q.empty())
    {
        ListNode* toAdd = Q.top();
        Q.pop();
        tail->next = toAdd;
        tail = tail->next;
        if (toAdd->next) Q.push(toAdd->next);//如果新加入的Node还指向另一个指针，那么把新的指针加入到其中来
    }
    return guard.next;
}



class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
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
};

