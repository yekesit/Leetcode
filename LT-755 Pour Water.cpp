//
// Created by Ke Ye on 2019-07-12.
//

#include <iostream>
#include <vector>

using namespace std;

int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
//Two stacks
//See https://leetcode.com/problems/pour-water/discuss/113003/C%2B%2BJavaPython-O(V%2BN)-time-solution-using-2-pointers-and-2-stacks

//Very nice thought... can learn it. LOL


//Since general method is not hard... Just look left and right to find current smallest one and then
//fix there....
// class Solution {
// public:
//     vector<int> pourWater(vector<int>& heights, int V, int K) {
//         stack<int> left;
//         stack<int> right;
//         int size = heights.size();
//         int left_bound = K;
//         int right_bound = K;

//         for(int i = 0; i < V; i++){
//             //using this kind of condition to avoid another left_bound++ after this while
//             while(left_bound > 0 && heights[left_bound] >= heights[left_bound - 1]){
//                 left_bound--;
//                 if(heights[left_bound] < heights[left_bound + 1]){
//                     left.push(left_bound);
//                 }
//             }
//             while(right_bound < size - 1 && heights[right_bound + 1] <= heights[right_bound]){
//                 right_bound++;
//                 if(heights[right_bound] < heights[right_bound - 1]){
//                     right.push(right_bound);
//                 }
//             }

//             if(!left.empty()){
//                 int idx = left.top();
//                 ++heights[idx];
//                 if(heights[idx] == heights[idx + 1]) left.pop();
//                 if(idx > left_bound) left.push(idx - 1);
//             }
//             else if(!right.empty()){
//                 int idx = right.top();
//                 ++heights[idx];
//                 if(heights[idx] == heights[idx - 1]) right.pop();
//                 if(idx < right_bound) right.push(idx + 1);
//             }
//             else{
//                 heights[K]++;
//                 if(K > left_bound) left.push(K - 1);
//                 if(K < right_bound) right.push(K + 1);
//             }
//         }
//         return heights;
//     }
// };

//Simple step by step
//
class Solution{
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        int size = heights.size();
        int next = 0;
        for(int i = 0; i < V; i++){
            next = K;
            for(int j = K - 1; j >= 0; j--){
                if(heights[j] < heights[j + 1]) next = j;
                if(heights[j] > heights[j + 1]) break;
            }
            if(next == K){
                for(int j = K + 1; j < size; j++){
                    if(heights[j] < heights[j - 1]) next = j;
                    if(heights[j] > heights[j - 1]) break;
                }
            }
            heights[next]++;
        }
        return heights;
    }
};
int main() {

}