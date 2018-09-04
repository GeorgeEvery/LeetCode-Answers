//
//  main.cpp
//  2. Add Two Numbers
//
//  Created by 于博尧 on 2018/9/4.
//  Copyright © 2018年 于博尧. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

// 加速cin读取速度，即将cin与stdio兼容的开关关闭
static const auto __ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){};
};

class Solution{
public:
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        
        ListNode *phead = NULL;
        ListNode *ptail = NULL;
        int sum = 0;
        int rest = 0;
        while(l1 != NULL || l2 != NULL){
            int val1 = (l1 == NULL ? 0 : l1->val);
            int val2 = (l2 == NULL ? 0 : l2->val);
            sum = val1 + val2 + rest;
            rest = (sum >= 10);
            ListNode *puse = new ListNode(rest ? sum - 10 : sum);
            
            if(phead == NULL){
                phead = puse;
                ptail = phead;
            }
            else{
                ptail->next = puse;
                ptail = ptail->next;
            }
            l1 = (l1 == NULL ? NULL : l1->next);
            l2 = (l2 == NULL ? NULL : l2->next);
        }
        if(rest > 0){
            ListNode *padd = new ListNode(rest);
            ptail->next = padd;
            ptail = ptail->next;
        }
        return phead;
    }
};


int main(int argc, const char * argv[]) {
    //clock_t start = clock();
    
    Solution S;
    ListNode *p1 = new ListNode(2);
    ListNode *p2 = new ListNode(4);
    ListNode *p3 = new ListNode(3);
    ListNode *p4 = new ListNode(5);
    ListNode *p5 = new ListNode(6);
    ListNode *p6 = new ListNode(4);
    p1->next = p2;
    p2->next = p3;
    
    p4->next = p5;
    p5->next = p6;
    ListNode *result = S.addTwoNumbers(p1, p4);
    while(result != NULL){
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    //cout.setf(ios::fixed);
    //cout << setprecision(31) << double(clock() - start) / CLOCKS_PER_SEC << endl;
    return 0;
}
