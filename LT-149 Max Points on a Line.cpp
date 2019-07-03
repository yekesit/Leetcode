//
// Created by Ke Ye on 2019-07-02.
//

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

//I want to use a simple for loop to solve the problem
//But here duplicate exist... so failed..
//We still need do it one by one... LOL.

//Well. I just figured out that... different line can have same slope... So if we put them together
//We will get many mistakse.... So we should do it one by one... Emmm
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() <= 2) return points.size();
        int size = points.size();
        int res = 0;
        for(int i = 0; i < size; i++){
            unordered_map<double, int> count;
            int ver = 0;
            int hor = 0;
            int same = 0;
            for(int j = 0; j < size; j++){
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                if((x1 == x2) && (y1 == y2)){
                    same++;
                }
                else{
                    if(x1 == x2) {
                        ver++;
                    }
                    else if(y1 == y2) {
                        hor++;
                    }
                    else{
                        double slope = (double)(x1 - x2) / (y1 - y2);
                        count[slope]++;
                    }
                }

            }
            for(auto& c : count){
                res = max(res, c.second + same);
            }
            res = max(res, ver + same);
            res = max(res, hor + same);
        }
        return res;
    }
};


int main() {

}