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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//Basic solution, use reverse list as recursion helper function,
//And then do it one by one.
//Basic function is
//After every recursion, we get.
// -1  ->  1  ->  2  ->  3  ->  4  ->  5
//List changes to
// -1  ->  1  <-  2  <-  3  ->  4  ->  5
//save -> prev ->   cur_head -> next
//prev is the return value.
//Then we write code as
//save->next = cur_head;
//prev->next = next;
//save = prev;
//Then it changes to
// -1  ->  3  ->  2  ->  1  ->   4  ->  5
//    cur_head  ->  save/prev -> next
//Then again, we pass save->next to make another loop.
// class Solution {
// public:
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         count = k - 1;
//         int len = 0;
//         ListNode *p = head;
//         while(p){
//             len++;
//             p = p->next;
//         }
//         int loops = len / k;
//         ListNode *dummy = new ListNode(-1);
//         dummy->next = head;
//         ListNode *save = dummy;
//         while(loops--){
//             prev = reverse(save->next, 0);
//             save->next = cur_head;
//             prev->next = next;
//             save = prev;
//         }
//         return dummy->next;
//     }

// private:
//     int count;
//     ListNode *next;
//     ListNode *prev;
//     ListNode *cur_head;

//     ListNode* reverse(ListNode* node, int cur_count){
//         if(cur_count == count){
//             cur_head = node;
//             next = node->next;
//             return node;
//         }
//         ListNode *rev = reverse(node->next, cur_count + 1);
//         rev->next = node;
//         return node;
//     }
// };

//Try to use iterative, got failure yeasterday.
//Same thought with recursion
//Since we have a dummy head,
//We just keep putting node next to dummy head
//Then we get a part k reverse list. So nice
//Emm code is concise now. LOL. same time complexity.
class Solution{
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 1) return head;
        int len = 0;
        ListNode *pre_tail  = head;
        while(pre_tail){
            len++;
            pre_tail = pre_tail->next;
        }
        int loops = len / k;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        pre_tail = dummy;
        ListNode *cur_tail, *next_head;
        while(loops--){
            cur_tail = pre_tail->next;
            next_head = cur_tail->next;
            for(int i = 1; i < k; i++){
                cur_tail->next = next_head->next;
                next_head->next = pre_tail->next;
                pre_tail->next = next_head;
                next_head = cur_tail->next;
            }
            pre_tail = cur_tail;
        }
        return dummy->next;
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