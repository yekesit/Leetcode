//
// Created by Ke Ye on 2019-06-23.
//

#include <iostream>
#include <vector>

using namespace std;

class UnionFind{
public:
    vector<int> parent;
    int island;
    UnionFind(int row, int col) : island(0){
        parent.resize(row * col, -1);
    }


    int find(int child){
        if(parent[child] == -1){
            island++;
            parent[child] = child;
        }
        return parent[child] == child ? parent[child] : parent[child] = find(parent[child]);
    }

    void Union(int c1, int c2){
        int p1 = find(c1);
        int p2 = find(c2);
        if(p1 == p2) return;
        island--;
        parent[p1] = p2;
    }


};

//First made a mistake....
//To calculate index in a matrix, it's index = i * col + j. EMMMMM I Just write i * row + j. Stupid.
//Then my condition is that, if current is '1' then check if there are '1' around this position.
//If so we union.
//But the problem is. if there only one '1' in the grid.. We don't have neighbor, then we miss one island..
//So when there is a new '1' we just call find
//Or we can make another method to set parent.
//I think it's better to make another method.. Or the code may make people confused.
//Well, here another question.... We can't setparent for neighbors....Emmm.... So using find is ok. LOL
//Then from solution I see that we can assign the visited '1' as '0' to save time
//Obviously we do it in dfs and bfs... Why I forget here.. Emmmm. so stupid.

class Solution{
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int row = grid.size();
        int col = grid[0].size();
        UnionFind uf(row, col);
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1'){
                    grid[i][j] = '0';
                    int cur = i * col + j;
                    uf.find(cur);
                    if(i - 1 >= 0 && grid[i - 1][j] == '1'){
                        uf.Union(cur, (i - 1) * col + j);
                    }
                    if(i + 1 < row && grid[i + 1][j] == '1'){
                        uf.Union(cur, (i + 1) * col + j);
                    }
                    if(j - 1 >= 0 && grid[i][j - 1] == '1'){
                        uf.Union(cur, i * col + j - 1);
                    }
                    if(j + 1 < col && grid[i][j + 1] == '1'){
                        uf.Union(cur, i * col + j + 1);
                    }
                }
            }
        }
        return uf.island;
    }
};


int main(){
    vector<vector<char>> grid{
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    Solution s;
    cout << s.numIslands(grid);
}