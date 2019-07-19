//
// Created by Ke Ye on 2019-07-18.
//


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> level(row, vector<int>(col, 0));
        vector<vector<int>> dist(row, vector<int>(col, 0));
        vector<vector<int>> directs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int cur_level = 1;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 1){
                    cur_level--;
                    queue<pair<int, int>> que;
                    que.push({i, j});
                    int step = 0;
                    while(!que.empty()){
                        int loops = que.size();
                        step++;
                        while(loops--){
                            auto cur = que.front(); que.pop();
                            int cur_i = cur.first;
                            int cur_j = cur.second;
                            for(auto& d : directs){
                                int next_i = cur_i + d[0];
                                int next_j = cur_j + d[1];
                                if(next_i >= 0 && next_j >= 0 && next_i < row && next_j < col){
                                    if(!grid[next_i][next_j] && level[next_i][next_j] == cur_level){
                                        level[next_i][next_j]--;
                                        dist[next_i][next_j] += step;
                                        que.push({next_i, next_j});
                                    }
                                }
                            }
                        }
                    }
                }

            }
        }

        cur_level--;
        int min_dist = INT_MAX;
        for(int i = 0; i < row; i++){
            for(int j = 0 ; j < col; j++){
                if(!grid[i][j] && level[i][j] == cur_level){
                    min_dist = min(min_dist, dist[i][j]);
                }
            }
        }
        return min_dist == INT_MAX ? -1 : min_dist;
    }
};

int main(){}
