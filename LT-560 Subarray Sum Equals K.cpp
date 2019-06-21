//
// Created by Ke Ye on 2019-06-21.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        count[0] = 1;
        int sum = 0;
        int res = 0;
        for(int& n : nums){
            sum += n;
            res += count[sum - k];
            count[sum]++;
        }
        return res;
    }
};


int main(){

}