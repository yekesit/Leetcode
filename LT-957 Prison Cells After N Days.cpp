//
// Created by Ke Ye on 2019-06-27.
//

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Solution{
public:
    void nextDay(vector<int>& cells, int& day){
        vector<int> next(8, 0);
        for(int i = 1; i < 7; i++){
            next[i] = cells[i - 1] == cells[i + 1];
        }
        cells = next;
        cout << setw(2) << day << ":  ";
        for(auto c : cells){
            cout << c << ' ';
        }
        cout << endl;
        day++;
    }
};



int main() {
    vector<int> cells{0, 1, 0, 1, 1, 0, 0, 1};
    int N = 30;
    int day = 0;
    Solution s;
    while(N--){
        s.nextDay(cells, day);
    }
}