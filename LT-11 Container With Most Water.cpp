//
// Created by Ke Ye on 2019-06-21.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution{
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int left = 0;
        int right = size - 1;
        int res = 0;
        int cur = 0;
        while(left < right){
            cur = (right - left) * min(height[right], height[left]);
            res = max(res, cur);
            //Change the smaller one to find next bigger one
            //Since our condition is: if next is smaller, we continue doing
            //So when we meet the bigger one, actually we are still at the smaller one.
            //We should increase by one.
            if(height[left] < height[right]){
                while(left < right && height[left + 1] < height[left]) left++;
                left++;
            }
            else{
                while(right > left && height[right - 1] < height[right]) right--;
                right--;
            }
        }
        return res;
    }
};

int main() {

}