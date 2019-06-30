//
// Created by Ke Ye on 2019-06-30.
//

#include <iostream>
#include <vector>

using namespace std;

// class Solution {
// public:
//     int splitArray(vector<int>& nums, int m) {
//         int max_sum = 0;
//         vector<int> partial(nums.size() + 1);
//         partial_sum(nums.begin(), nums.end(), partial.begin() + 1);
//         int total = partial.back();
//         int each = total / m;
//         int increase = each;
//         int left = 0;
//         int right = 1;
//         for(int i = 1; i < m; i++){
//             while(partial[right] < each){
//                 right++;
//             }
//             if(partial[right] == each){
//                 max_sum = max(max_sum, partial[right] - partial[left]);
//             }
//             if(partial[right] > each){
//                 if(partial[right] - each > each - partial[right]){
//                     max_sum = max(max_sum, partial[right - 1] - partial[left]);
//                     left = right - 1;
//                 }
//                 else{
//                     max_sum = max(max_sum, partial[right] - partial[left]);
//                     left = right;
//                 }
//             }
//             each += increase;
//         }
//         max_sum = max(max_sum, partial[partial.size() - 1] - partial[left]);
//         return max_sum;
//     }
// };


//After see solution, I figure out how can solve it by DP,
//It is somehow like brute-force. The difference is that we record all situations and we don't go back again
//Means we cut many redundant branches.
//We just record the minimum maximum sum for all kinds of m split for current interval.
//If it can not be splitted by m, means the length <= m. We just assign it as INT_MAX.
//Since we want the minmum maximum sum. so INT_MAX will always be ignored.
//We can only update those valid split.

//Why partial sum >> save time
//Why length + 1 >> if we want to get sum from [0....i] We need partial[i] - partial[-1] which we can't reach.
//So we use a length + 1 vector to save all partial sum, easy to use partial[i] - partial[0] to get the sum

//Same for dp vector. assgian as length + 1.
//Since for nums.size(), we should go from 1 because of partial sum
//for m.... if we want to get value for split into m parts
//We should get [m]. so the length should be m + 1. Just set 0 as INT_MAX except [0][0]. Since [0][0] means
//Split 0 element into 0 part.... so it's 0. LOL(empty)

//Emmm should use long here
//And should be familiar with such problem. Dp in split something into several parts
//Record current situation. Then go to next to use previous records... Emmm Many problems.
// class Solution{
// public:
//     int splitArray(vector<int>& nums, int m) {
//         if(nums.empty()) return 0;
//         int n = nums.size();
//         vector<long> part(n + 1, 0);
//         // partial_sum(nums.begin(), nums.end(), part.begin() + 1);
//         for(int i = 1; i <= n; i++){
//             part[i] = part[i - 1] + nums[i - 1];
//         }

//         vector<vector<long>> dp(n + 1, vector<long>(m + 1, INT_MAX));
//         dp[0][0] = 0;

//         for(int i = 1; i <= n; i++){
//             for(int j = 1; j <= m; j++){
//                 for(int k = 0; k < i; k++){
//                     dp[i][j] = min(dp[i][j], max(dp[k][j - 1], part[i] - part[k]));
//                 }
//             }
//         }
//         return dp[n][m];
//     }
// };





//For greedy, I first use the total / m to get each subarray sum.....
//But obvioulsy, if the input is not balanced, which means, we can't split all array into m subarrays in perfect
//toatl / m... My thought will get problem here. For example, 1 2 3 4 5 6 7 m =  2
//It should be 12345 and 67.
//So here we should use 15 as bound to split the array into two parts.
//But my thought uses 14.... So it becomes 1234 567... Then wrong.
//And my thought is hard to update this boundary... Because I don't know when to stop.... So... I failed.
//After see solution.... Emmm the author just use binary search to update the mid(the boundary).
//And see if it can split the array into m parts....
//If so, we update the final solution.. Until we can't update the boundary which is left > right...
//Well, my original though is somehow same for part of this solution... Anyway, I get the thought that I should use greedy
//It's just I don't know how to update and when I can get wanted result.. Emmm

//!!!!!!
//Oh I got the final thougtht
//They just use greedy to find the number that eqaul the desired minimum maximum sum!!!!
//besides < and  > (easy understand). when we get the proper m splits.
//Will it be the final choice?? Obiviously not. what if we can make it small and then still get m splits?
//So just check it again and again... Finally we get the wanted result.


//To make the thougth simple, which is
//We want to find the desired sum that split the array into m parts.
//So basically we can go from the total sum and minus one by one to find the result
//But it too slow... Since we wanto reduce the situation fast..
//here binary search is good Since we can reduce half in each loop!!!

//Here the problem!!! why left is max(left, n);
//Since no matter how many splits we have, even if we split them into each one...
//The minimum maximum sum is the biggest number in this array...
//So the lower bound should be the max number ... but not the  min number...
class Solution{
public:
    int splitArray(vector<int>& nums, int m) {
        if(nums.empty()) return 0;
        long left = 0;
        long right = 0;
        int size = nums.size();
        for(long n : nums){
            left = max(left, n);
            right += n;
        }

        long res = right;
        //Why <= not < since one single element can be the final result like 111111111 9
        while(left <= right){
            long pivot = left + (right - left) / 2;
            long part_sum = 0;
            int count = 1;//Since there is a last part we can't count from for loop
            for(int& n : nums){
                if(part_sum + n > pivot){
                    count++;
                    part_sum = n;
                }
                else{
                    part_sum += n;
                }
            }
            //If <= means we can reduce the pivot to get more count
            //Or the better solution
            if(count <= m){
                res = min(res, pivot);
                right = pivot - 1;
            }
                //If > means the pivot is too smale,, we need bigger one.
            else{
                left = pivot + 1;
            }
        }
        return res;
    }
};




int main() {

}
