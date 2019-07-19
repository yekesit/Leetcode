//
// Created by Ke Ye on 2019-07-18.
//

#include <iostream>


using namespace std;

//O(1) space
//First find half
//Then reverse next half
//Then merge list....

// class Solution {
// public:
//     void reorderList(ListNode* head) {
//         if(!head || !head->next) return;
//         ListNode *p = head;
//         int len = 0;
//         while(p){
//             len++;
//             p = p->next;
//         }
//         int half = (len + 1) / 2;
//         p = head;
//         while(--half){
//             p = p->next;
//         }

//         ListNode *q = p->next;
//         p->next = nullptr;
//         ListNode *next_q1 = q->next;
//         q->next = nullptr;
//         ListNode *next_q2 = next_q1 ? next_q1->next: nullptr;
//         while(next_q1){
//             next_q1->next = q;
//             q = next_q1;
//             next_q1 = next_q2;
//             next_q2 = next_q1 ? next_q1->next : nullptr;
//         }
//         ListNode *dummy = new ListNode(-1);
//         ListNode *cur = dummy;
//         p = head;
//         while(p && q){
//             cur->next = p;
//             cur = cur->next;
//             p = p->next;
//             cur ->next = q;
//             cur = cur->next;
//             q = q->next;
//         }
//         if(p){
//             cur->next = p;
//         }
//     }
// };


//Try to make code concise
//See solution, use slow and fast pointer can easily get the middle one whitout length method
//When stop, we stop at mid. so next part is mid->next;
class Solution{
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *start = slow->next;
        slow->next = nullptr;
        //here if we don't want to do conditions like solution above
        //We just use a nulltpr as final res, here is pre
        //Likst what we do in recursion method
        ListNode *pre = nullptr;
        ListNode *next;
        while(start){
            next = start->next;
            start->next = pre;
            pre = start;
            start = next;
        }
        while(head && pre){
            next = head->next;
            head->next = pre;
            pre = pre->next;
            head->next->next= next;
            head = next;
        }

    }
};



int main(){

}