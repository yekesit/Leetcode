//
// Created by Ke Ye on 2019-07-02.
//

#include <iostream>
#include <vector>

using namespace std;

int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();


//Actually if an interval exist, then the left should <= right
//So we can just calculate left and right, and check. if <=, we push_back. if not we move...
//Save two conditions!!! Nice
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        if(A.empty() || B.empty()) return {};
        vector<vector<int>> res;
        int i = 0;
        int j = 0;
        int lenA = A.size();
        int lenB = B.size();
        int left = 0;
        int right =0;
        while(i < lenA && j < lenB){
            left = max(A[i][0], B[j][0]);
            right = min(A[i][1], B[j][1]);
            if(left <= right){
                res.push_back({left, right});
            }
            if(A[i][1] < B[j][1]){
                i++;
            }
            else{
                j++;
            }
        }
        return res;
    }
};

int main() {

}