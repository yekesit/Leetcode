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
    UnionFind(int row, int col): island(0){
        parent.resize(row * col, -1);
    }

    int find(int child){
        if(parent[child] == -1){
            island++;
            parent[child] = child;
            return child;
        }

        return parent[child] == child? child : parent[child] = find(parent[child]);
    }

    void Union(int c1, int c2){
        int p1 = find(c1);
        int p2 = find(c2);
        if(p1 == p2) return;
        island--;
        parent[p1] = p2;
    }

    bool isIsland(int child){
        return parent[child] != -1;
    }
};


class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        if(positions.empty()) return {};
        UnionFind uf(m, n);
        vector<int> res;
        for(auto& p : positions){
            int row = p[0];
            int col = p[1];
            int cur = row * n + col;
            uf.find(cur);
            //No need to create a new 2d matrix. Use UnionFind to check whether it is an island.
            if(row - 1 >= 0 && uf.isIsland((row - 1) * n + col)){
                uf.Union(cur, (row - 1) * n + col);
            }
            if(row + 1 < m && uf.isIsland((row + 1) * n + col)){
                uf.Union(cur, (row + 1) * n + col);
            }
            if(col - 1 >= 0 && uf.isIsland(row * n + col - 1)){
                uf.Union(cur, row * n + col - 1);
            }
            if(col + 1 < n && uf.isIsland(row * n + col + 1)){
                uf.Union(cur, row * n + col + 1);
            }
            res.push_back(uf.island);
        }
        return res;
    }
};

int main() {

}