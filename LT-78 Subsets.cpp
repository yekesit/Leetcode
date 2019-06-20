//
// Created by Ke Ye on 2019-06-19.
//

#include <vector>
#include <iostream>

using namespace std;

//Try backtracking
//Different from permutation. Since we have an order here and no duplicate.
//We just push current i and continue from next one of current i.
//Unlike permutation. swap current one and then from next index.... Since we swap to index, and continue from index.
//Should be familiar with this method!!
// class Solution {
// public:
//     vector<vector<int>> res;

//     void helper(vector<int>& nums, int index, vector<int>& cur){
//         if(index > nums.size()) return;
//         res.push_back(cur);
//         for(int i = index; i < nums.size(); i++){
//             cur.push_back(nums[i]);
//             helper(nums, i + 1, cur);
//             cur.pop_back();
//         }
//     }



//     vector<vector<int>> subsets(vector<int>& nums) {
//         if(nums.empty()) return {{}};
//         vector<int> cur;
//         helper(nums, 0, cur);
//         return res;
//     }
// };


//Simple iterative
//It's just when we meet a new element, combine it with all former vector to make new elements...
//Well, why I don't get this solution first?? so stupid...
// class Solution{
// public:
//     vector<vector<int>> subsets(vector<int>& nums){
//         if(nums.empty()) return {};
//         vector<vector<int>> res{{}};
//         for(int i = 0; i < nums.size(); i++){
//             //Ok in Ide, wrong in leetcode.. emmm
//             // for(auto& r : res){
//             //     vector<int> next = r;
//             //     next.push_back(nums[i]);
//             //     res.push_back(next);//emmm can do this @-@.... it only use the former size. lol
//             // }
//             int size = res.size();
//             for(int j = 0; j < size; j++){
//                 // vector<int> next = res[j];
//                 // next.push_back(nums[i]);
//                 // res.push_back(next);

//                 //a nice code. XD
//                 res.push_back(res[j]);
//                 res.back().push_back(nums[i]);
//             }
//         }
//         return res;
//     }
// };


//There is a solution about bit-manipulation
//See https://blog.csdn.net/gh6267/article/details/88116764
//If we have n bits to be filled in these numbers. Then we can easier to choose whether add it or not.
//According to the bits
//Like if current set is 0011(the forth sets). means the first and the second one appear. Then we make the set!!
//Very  nice thought and an entry to bit manipulation!!!.
class Solution{
public:
    vector<vector<int>> subsets(vector<int>& nums){
        if(nums.empty()) return{};
        int size = nums.size();
        int total = 1 << size;
        vector<vector<int>> res(total);
        for(int i = 0; i < total; i++){
            for(int j = 0; j < size; j++){
                if(i & (1 << j)){
                    res[i].push_back(nums[j]);
                }
            }
        }
        return res;
    }

};

int main(){
    vector<int> nums{1,2,3};
    Solution s;
    cout << s.subsets(nums).size() << endl;
}