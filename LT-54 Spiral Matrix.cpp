//
// Created by Ke Ye on 2019-06-25.
//

#include <iostream>
#include <vector>

using namespace std;

// class Solution {
// public:
//     vector<int> spiralOrder(vector<vector<int>>& matrix) {
//         if(matrix.empty() || matrix[0].empty()) return {};
//         int row = matrix.size();
//         int col = matrix[0].size();
//         int total = row * col;
//         int count = 0;
//         int loop = 0;
//         vector<int> res;
//         //Don't need use while. Just a for loop. save code lines... LOL
//         while(count < total){
//             int i = loop;
//             int j = loop;
//             while(j < col - loop){
//                 res.push_back(matrix[i][j]);
//                 count++;
//                 j++;
//             }
//             if(count == total) break;
//             j--;
//             i++;
//             while(i < row - loop){
//                 res.push_back(matrix[i][j]);
//                 count++;
//                 i++;
//             }
//             if(count == total) break;
//             i--;
//             j--;
//             while(j >= loop){
//                 res.push_back(matrix[i][j]);
//                 count++;
//                 j--;
//             }
//             if(count == total) break;
//             j++;
//             i--;
//             while(i > loop){
//                 res.push_back(matrix[i][j]);
//                 count++;
//                 i--;
//             }
//             if(count == total) break;
//             loop++;
//         }
//         return res;
//     }
// };

//Try to make code concise. After see solution.
//Well my solution also works... Just a little ugly. lol.

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return {};
        //not use loop to control every loop.
        //use up bottom left and right bound to control.
        //So that we can change end condition and we don't need to check count one by one...
        int up = 0;
        int down = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        vector<int> res;
        while(up <= down && left <= right){
            for(int j = left; j <= right; j++)
                res.push_back(matrix[up][j]);
            for(int i = up + 1; i <= down; i++)
                res.push_back(matrix[i][right]);
            //It's ok to go right and down
            //But we should not go back
            //Since if there is only one row or one column.
            //We may add some duplicate elements.
            //That's why I write so many conditions in first solution... Then it became ugly
            if(left < right && up < down){
                for(int j = right -1; j >= left; j--)
                    res.push_back(matrix[down][j]);
                for(int i = down - 1; i >= up + 1; i--)
                    res.push_back(matrix[i][left]);
            }
            up++;
            down--;
            left++;
            right--;
        }
        return res;
    }
};






int main() {

}