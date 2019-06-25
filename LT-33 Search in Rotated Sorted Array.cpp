//
// Created by Ke Ye on 2019-06-25.
//

#include <iostream>
#include <vector>

using namespace std;



//If we search in a normal sorted array, we can use simple binary search.
//But here it is rotated, so, we should add some condition to make sure whether we can assume
//current subarray is a good sorted array.
//If so, do as normally.
//If not, compare both sides to see where to go.

class Solution{
public:
    int search(vector<int>& nums, int target){
        if(nums.empty()) return -1;
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = left +  (right - left) / 2;
            if(nums[mid] == target) return mid;
            if(nums[mid] < target){
                //If this is a good sorted array
                if(nums[mid] >= nums[left]){
                    left = mid + 1;
                }
                else {
                    //Compare both sides
                    //Focus on the sorted part
                    if(nums[right] < target){
                        right = mid - 1;
                    }
                    else{
                        left = mid + 1;
                    }
                }
            }
            else {
                //If this is a good sorted array
                if(nums[mid] < nums[right]){
                    right = mid - 1;
                }
                else{
                    //Same with former part.
                    //Focus on the sorted part
                    if(nums[left] > target){
                        left = mid + 1;
                    }
                    else{
                        right = mid - 1;
                    }
                }
            }
        }
        return -1;
    }
};




int main (){
    vector<int> nums{4,5,6,7,0,1,2};
    int target = 4;

}