//
// Created by Ke Ye on 2019-07-04.
//

#include <iostream>
#include <vector>

using namespace std;

int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

//Assume target is 8
//find the mid, if situatoin is like  XXX8XXX. ok we got it left = right = 4;
//if situation is like XXX888XXX and mid is 3, then we find left, but not right so we go right
//Same for left
//if it is XXX888XXX and mid is 4. then we go both.
//Somehow like divide and conquer

// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         size = nums.size();
//         helper(nums, 0, size - 1, target);
//         return {res_l, res_r};
//     }
// private:
//     int res_l = -1;
//     int res_r = -1;
//     int size;

//     void helper(vector<int>& nums, int left, int right, int target){
//         if(left > right) return;
//         int mid = left + (right - left) / 2;
//         if(nums[mid] < target){
//             left = mid + 1;
//             helper(nums, left, right, target);
//         }
//         else if(nums[mid] > target){
//             right = mid - 1;
//             helper(nums, left, right, target);
//         }
//         else{
//             if(mid == 0 || nums[mid] != nums[mid - 1]){
//                 res_l = mid;
//             }
//             else{
//                 helper(nums, left, mid - 1, target);
//             }
//             if(mid == size - 1 || nums[mid] != nums[mid + 1]){
//                 res_r = mid;
//             }
//             else{
//                 helper(nums, mid + 1, right, target);
//             }
//         }

//     }
// };

//After I see solution, I just wonder why their solutoins are so concise. Then I find that he used two Binary search
//one for left and the other one for right.... Emmmm. But why not do it at the same time then made it as divide and conquer?
///Emmm anyway I don't like solution. LOL


//Then here is an easy method in c++, use lower bound.. very easy. lol
//lower_boudn is binary search, lol. Then two lower_bound, we get left and right. Emmm

class Solution{
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1, -1};
        int left = -1;
        int right = -1;
        auto left_it = lower_bound(nums.begin(), nums.end(), target);
        auto right_it = upper_bound(nums.begin(), nums.end(), target);
        if(right_it != nums.begin()){
            right_it--;
        }
        if(left_it != nums.end() && *left_it == target){
            left = left_it - nums.begin();
        }
        if(right_it != nums.end() && *right_it == target){
            right = right_it - nums.begin();
        }
        return {left, right};
    }
};





int main() {

}