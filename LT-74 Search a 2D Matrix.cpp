//
// Created by Ke Ye on 2019-06-16.
//

#include <iostream>
#include <vector>

//find from last element then one by one.
//Actually slower than real binary search...
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         if(matrix.empty() || matrix[0].empty()) return false;
//         int row = 0;
//         int col = matrix[0].size() - 1;
//         while(row < matrix.size() && matrix[row][col] < target){
//             if(matrix[row][col] < target)
//                 row++;
//         }
//         if(row == matrix.size()) return false;
//         while(col >= 0){
//             if(matrix[row][col] == target){
//                 return true;
//             }
//             else if(matrix[row][col] < target){
//                 return false;
//             }
//             col--;
//         }
//         return false;
//     }
// };

//drag it into one array we can see it is a sorted array. So just use single binary search
//Maybe the test case is not large, so two time costs are similar.. XD
class Solution{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target){
        if(matrix.empty() || matrix[0].empty()) return false;
        int row = matrix.size();
        int col = matrix[0].size();
        int left = 0;
        int right = row * col - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            int mid_row = mid / col;
            int mid_col = mid % col;
            if(matrix[mid_row][mid_col] < target){
                left = mid + 1;
            }
            else if(matrix[mid_row][mid_col] > target){
                right = mid - 1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};

int main() {

}

