//
// Created by Ke Ye on 2019-06-25.
//

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

//最后一个方法最机智。就是利用读票规则。票最多那个总能留到最后
//从第一个候选者开始，如果有他的票他的赞成数加1， 否则减1。
//如果减到0就意味着到目前位置，这个候选者没用了，赞成的人不够多。。。就换下一个
//根据题目要求， 肯定有个票是最多的。所以最终一定会留下那个最多的票的候选者，其他人都反对不过他。。。23333

//Basic. two traversals. slow and wast space.. EMMM
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         unordered_map<int, int> count;
//         for(int n : nums){
//             count[n]++;
//         }
//         for(auto c : count){
//             if(c.second >= (nums.size() + 1) / 2) return c.first;
//         }
//         return 0;
//     }
// };

//Actually if a number appears more than n / 2 times.... it appears more than all other numbers..
//This thought is good!!!!! Change the problem to find the most occurrs elmeent.. LOL
//Well here we make too many assignments and conditions.... slower. LOL
// class Solution{
// public:
//     int majorityElement(vector<int>& nums){
//         unordered_map<int, int> count;
//         int max_num = 0;
//         int max_count = 0;
//         for(int n : nums){
//             count[n]++;
//             if(count[n] > max_count){
//                 max_count = count[n];
//                 max_num = n;
//             }
//         }
//         return max_num;

//     }
// };

//Approach 6 in solution. Really smart.
//Since the result will appear over half length times. For example
//We have 11 votes, and I have 6 votes. So finally I will beat other 5 votes and 1 vote left.
//So here is the same.
//We just go from the first candidate, if his votes gets zero. OK next.
//Finally we can always find a type of vote that no one can beat it..  Really smart... Can't come up with it..Emmm

//Smart !!!!!
class Solution{
public:
    int majorityElement(vector<int>& nums){
        int res = 0;
        int count = 0;
        for(int& n : nums){
            if(!count) res = n;
            count += n == res ? 1 : -1;
        }
        return res;
    }
};


int main() {

}