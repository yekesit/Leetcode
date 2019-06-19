//
// Created by Ke Ye on 2019-06-19.
//

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

//Simple brute force. TLE LOL
// class Solution {
// public:
//     int subarraysDivByK(vector<int>& A, int K) {
//         if(A.empty()) return 0;
//         int res = 0;
//         for(int i = 0; i < A.size(); i++){
//             for(int j = i; j < A.size(); j++){
//                 int sum = 0;
//                 for(int k = i; k <= j; k++){
//                     sum += A[k];
//                 }
//                 if(sum % K == 0) res++;
//             }

//         }
//         return res;
//     }
// };

//Partial sum. still slow... emmm
// class Solution{
// public:
//     int subarraysDivByK(vector<int>& A, int K){
//         partial_sum(A.begin(), A.end(), A.begin());
//         int res = 0;
//         for(int i = 0; i < A.size(); i++){
//             if(A[i] % K == 0) res++;
//             for(int j = i - 1; j >= 0; j--){
//                 if((A[i] - A[j]) % K == 0) res++;
//             }
//         }
//         return res;
//     }
// };

//After see solution...
//not simple partial sum
//here we used following thought
//Assum we already get a patial sum vector s
//If s[0...i] % k == s[0...j] % k
//Then we know, s[i....j] is a good result. we add it.
//So when we meet s[0...j] % k. We just find how many same prefix appear before. Then we add the number into result..
//Really smart thought!!!! LOL
//And also we don't need to get partial first. just do it following the array.
int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution{
public:
    int subarraysDivByK(vector<int>& A, int K){
        if(A.empty()) return 0;
        int res = 0;
        unordered_map<int, int> prefix_count;
        prefix_count[0] = 1;//Since if we meet the first one which makes a modulo as 0, then it should be a result.
        //For other situation, we first find the prefix, so the original value is 0.
        int cur_sum = 0;
        for(int i = 0; i < A.size(); i++){
            cur_sum = (cur_sum + A[i] % K + K) % K; // + K to make sure it is positive.
            res += prefix_count[cur_sum]++;
        }
        return res;
    }

};

int main() {

}