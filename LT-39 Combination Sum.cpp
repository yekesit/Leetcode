//
// Created by Ke Ye on 2019-07-03.
//

#include <iostream>
#include <vector>

using namespace std;




class Solution{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.empty()) return {};
        vector<vector<int>> res;
        vector<int> cur;
        backtracking(res, candidates, cur, 0, target);
        return res;
    }

private:
    void backtracking(vector<vector<int>>& res, vector<int>& nums, vector<int>& cur, int index, int target){
        if(target <= 0){
            if(target == 0){
                res.push_back(cur);
            }
            return;
        }

        for(int i = index; i < nums.size(); i++){
            cur.push_back(nums[i]);
            backtracking(res, nums, cur, i, target - nums[i]);
            cur.pop_back();
        }
    }
};

int main() {

}