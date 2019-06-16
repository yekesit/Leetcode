//
// Created by Ke Ye on 2019-06-16.
//

#include <vector>
#include <iostream>

using namespace std;

bool cmp(vector<int>& v1, vector<int>& v2){
    return v1[1] < v2[1];
}



int maximumMeetings(vector<vector<int>>& interval){
    if(interval.empty()) return 0;
    sort(interval.begin(), interval.end(), cmp);
    int sum = 1;
    int last = 0;
    int cur = 1;
    while(cur < interval.size()){
        if(interval[cur][0] > interval[last][1]){
            sum++;
            last = cur;
        }
        cur++;
    }
    return sum;
}


int main(){
    vector<vector<int>> interval{
            {1, 2},
            {3, 4},
            {0, 6},
            {5, 7},
            {8, 9},
            {5, 9}
    };
    vector<vector<int>> interval1{
            {75250, 112960},
            {50074, 114515},
            {43659, 81825},
            {8931, 93424},
            {11273, 54316},
            {27545, 35533},
            {50879, 73383},
            {7924, 160252}
    };
    cout << maximumMeetings(interval) << endl;
    cout << maximumMeetings(interval1) << endl;

}