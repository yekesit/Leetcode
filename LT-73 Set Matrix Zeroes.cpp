//
// Created by Ke Ye on 2019-06-15.
//

#include <iostream>
#include <vector>

using namespace std;

//Some examples show why we leave first line and first row at the first pass.
//Use two variables to record the situation of first row and first column
//Since later we want to use both two lines to decide whether a position should change or not.
//If we first traverse all positions, both two lines will be influenced by value in the same row or column.
//Like matrix 1
//For matrix 2. it shows, we should not change both two lines at the second pass. Since internal values depends on them
//So we first change inner positions then two lines.
//Now two variables do work. we change two lines according to the value. XD

/*
 * 1 1 1        0 0 1
 * 0 1 0        1 1 1
 * 0 1 0        0 0 1
 *
 */




class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        //Problem here is that we can't direcly change the first column and first row. eg.
        //For the right result.
        // 0 1 1    0 0 0
        // 1 1 1 >> 0 0 1
        // 1 0 1    0 0 0
        // So to get this case, after first pass, we should get
        // 0 0 1
        // 1 1 1
        // 0 0 1
        // Then we know when we meet [1][2], where [1][0] and [0][2] are both 1, then here should be 1
        //After the second pass, we put [1][0] and [0][2] as zero.
        //And the reason we know why we should set two positions are zero is, there is a zero in [0][0]
        //So we need another two variables to record whether the first row and first column should be set into 0;
        bool row_0 = false;
        bool col_0 = false;
        for(int i = 0; i < rows; i++){
            if(matrix[i][0] == 0){
                col_0 = true;
                break;
            }
        }

        for(int j = 0; j < cols; j++){
            if(matrix[0][j] == 0){
                row_0 = true;
                break;
            }
        }
        for(int i = 1; i < rows; i++){
            for(int j = 1; j < cols; j++){
                if(!matrix[i][j]){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        for(int i = 1; i < rows; i++)
            for(int j = 1; j < cols; j++){
                if(!matrix[i][0] || !matrix[0][j])
                    matrix[i][j] = 0;
            }
        if(row_0){
            for(int j = 0; j < cols; j++){
                matrix[0][j] = 0;
            }
        }
        if(col_0){
            for(int i = 0; i < rows; i++){
                matrix[i][0] = 0;
            }
        }
    }
};



int main(){

}