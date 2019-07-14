//
// Created by Ke Ye on 2019-07-14.
//

#include <iostream>
#include <vector>

using namespace std;

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        if(grid.empty()) return nullptr;
        int n = grid.size();
        return dfs_back(grid, 0, 0, n - 1, n - 1);
    }


private:
    Node* dfs_back(vector<vector<int>>& grid, int left, int top, int right, int down){
        if(top == down && left == right){
            return new Node(grid[top][left] == 1, true, nullptr, nullptr, nullptr, nullptr);
        }
        int top_down_mid = top + (down - top) / 2;
        int left_right_mid = left + (right - left) / 2;

        Node *top_left = dfs_back(grid, left, top, left_right_mid, top_down_mid);
        Node *top_right = dfs_back(grid, left_right_mid + 1, top, right, top_down_mid);
        Node *down_left = dfs_back(grid, left, top_down_mid + 1, left_right_mid, down);
        Node *down_right = dfs_back(grid, left_right_mid + 1, top_down_mid + 1, right, down);

        if(top_left->isLeaf && top_right->isLeaf && down_left->isLeaf && down_right->isLeaf){
            if(top_left->val == top_right->val &&
               top_right->val == down_left->val &&
               down_left->val == down_right->val){
                return new Node(top_left->val, true, nullptr, nullptr, nullptr, nullptr);
            }
        }

        return new Node(false, false, top_left, top_right, down_left, down_right);
    }
};


int main() {

}