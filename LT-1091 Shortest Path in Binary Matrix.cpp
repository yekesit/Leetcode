//
// Created by Ke Ye on 2019-06-17.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//妈蛋好气。。又是一个bfs没看出来
//shortest path!!!
class Solution {
public:
    vector<vector<int>> directs{{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty() || grid[0][0] == 1 || grid[grid.size() - 1][grid.size() - 1] == 1) return -1;
        int size = grid.size();
        queue<pair<int, int>> bfs;
        bfs.push(make_pair(0, 0));
        grid[0][0] = 1;
        int step = 1;
        while(!bfs.empty()){
            int loops = bfs.size();
            step++;
            while(loops--){
                //never, never put this sentence in wrong place !!!!
                pair<int, int> cur = bfs.front(); bfs.pop();
                for(auto& d : directs){
                    int next_i = cur.first + d[0];
                    int next_j = cur.second + d[1];
                    if(next_i == size - 1 && next_j == size - 1) return step;
                    if(next_i < size && next_j < size && next_i >= 0 && next_j >= 0 && grid[next_i][next_j] == 0){
                        grid[next_i][next_j] = 1;
                        bfs.push(make_pair(next_i, next_j));
                    }
                }
            }
        }
        return -1;
    }
};



int main(){
    vector<vector<int>> grid{{0,0,0},{0,1,0},{0,0,0}};
    Solution s;
    cout << s.shortestPathBinaryMatrix(grid) << endl;
}