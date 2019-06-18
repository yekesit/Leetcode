//
// Created by Ke Ye on 2019-06-17.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         unordered_set<int> exist; //don't needd it. kth element in a min_heap, just keep last k elements and return
//                                      //the top is ok
//         priority_queue<int, vector<int>, greater<int>> kth;
//         for(auto n : nums){
//             if(exist.find(n) != exist.end()) continue;
//             else{
//                 kth.push(n);
//                 if(kth.size() > k) kth.pop();
//             }
//         }
//         return kth.top();
//     }
// };

// class Solution{
// public:
//     int findKthLargest(vector<int>& nums, int k){
//         priority_queue<int, vector<int>, greater<int>> kth;
//         for(auto n : nums){
//             kth.push(n);
//             if(kth.size() > k) kth.pop();
//         }
//         return kth.top();
//     }
// };

//Try quick select
class Solution{
public:

    int partition(vector<int>& nums, int left, int right){
        int i = left;
        int j = right;

        int pivot = left + rand() % (right - left);
        swap(nums[i], nums[pivot]);
        while(i < j){
            while(i < j && nums[j] >= nums[left]) j--;
            while(i < j && nums[i] <= nums[left]) i++;
            swap(nums[i], nums[j]);
        }
        swap(nums[left], nums[i]);
        return i;
    }

    //use kSmall so that we don't need do many minus operation here
    int quickSelect(vector<int>& nums, int left, int right, int kSmall){
        if(left == right) return nums[left];
        int pivot = partition(nums, left, right);
        //want to get kth largest, so we use kSmall
        //If we want to find kSmall before current pivot
        //then the index of current should be kSmall.
        if(pivot == kSmall){
            return nums[pivot];
        }
        else if(pivot < kSmall){
            return quickSelect(nums, pivot + 1, right, kSmall);
        }
        else{
            return quickSelect(nums, left, pivot - 1, kSmall);
        }
    }

    int findKthLargest(vector<int>& nums, int k){
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }
};


int main() {
    vector<int> test{1,3,5,2,4,6};
    sort(test.rbegin(), test.rend());
    for(auto t : test)
        cout << t << ' ';

}