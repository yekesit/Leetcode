//
// Created by Ke Ye on 2019-06-28.
//

#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return nullptr;
        ListNode* p = head;
        int len = 0;
        while(p){
            len++;
            p = p->next;
        }
        int total = len / k;
        int loops = 0;
        k--;
        p = head;
        ListNode *p1, *p2, *p3;
        while(loops < total){
            int time = k;
            p1 = p;
            p2 = p1->next;
            p3 = p2 == nullptr? nullptr : p2->next;
            while(time){
                p2->next = p1;
                p1 = p2;
                p2 = p3;
                p3 = p2 == nullptr ? nullptr : p2->next;
                time--;
            }
            if(!loops){
                head = p1;
            }
            p->next = p2;
            p = p2;
            loops++;
        }
        return head;
    }
};

int main() {
    ListNode *head = new ListNode(1);
    ListNode *p = head;
    p->next = new ListNode(2);
    p = p->next;
    p->next = new ListNode(3);
    p = p->next;
    p->next = new ListNode(4);
    p = p->next;
    p->next = new ListNode(5);

    Solution s;
    head = s.reverseKGroup(head, 2);
    while(head){
        cout << head->val << ' ';
        head = head->next;
    }
}