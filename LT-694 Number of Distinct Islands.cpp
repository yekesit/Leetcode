//
// Created by Ke Ye on 2019-06-15.
//


#include <iostream>
#include <vector>
#include <set>

using namespace std;



//First want to save whole path, which is up down left right.. Then I meet this situation
// 110
// 011
// 000
// 111
// 010
//Obviously it only works when my order is up down left right. But I think even if I change order. there is still
//some other input make me wrong.
//So After see their code I find that, we should save the relative position compared with the original position.
//Then we make it.

//Again, make sure use the same method. Which is,
//if set value at begin of dfs, all in there.
//if set value before going to dfs, all here.
//...Forget to delete the setting value code in main loops.... make me no answer.. lol.

class Solution {
public:
    set<vector<pair<int, int>>> paths;
    int rows;
    int cols;

    void fillPath(vector<vector<int>>& grid, int i, int j, int oi, int oj, vector<pair<int, int>>& path){
        if(i < 0 || j < 0 || i == rows || j == cols) return;
        if(grid[i][j] == 0) return;
        grid[i][j] = 0;
        path.emplace_back({i - oi, j - oj});
        fillPath(grid, i - 1, j, oi, oj, path);
        fillPath(grid, i + 1, j, oi, oj, path);
        fillPath(grid, i, j - 1, oi, oj, path);
        fillPath(grid, i, j + 1, oi, oj, path);
    }


    int numDistinctIslands(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        rows = grid.size();
        cols = grid[0].size();
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1){
                    vector<pair<int, int>> path;
                    fillPath(grid, i, j, i, j, path);
                    paths.insert(path);
                }
            }
        return paths.size();
    }
};

int main(){
    vector<vector<int>> grid{
        {1,1,0},
        {0,1,1},
        {0,0,0},
        {1,1,1},
        {0,1,0}
    };
    Solution s;
    cout << s.numDistinctIslands(grid) << endl;
}