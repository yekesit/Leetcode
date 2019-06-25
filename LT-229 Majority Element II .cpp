//
// Created by Ke Ye on 2019-06-25.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int m1 = 0;
        int m2 = 0;
        int c1 = 0;
        int c2 = 0;
        for(int& n : nums){
            if(m1 == n){
                c1++;
            }
            else if(m2 == n){
                c2++;
            }
            else if(c1 == 0){
                m1 = n;
                c1++;
            }
            else if(c2 == 0){
                m2 = n;
                c2++;
            }
            else{
                c1--;
                c2--;
            }
        }
        c1 = 0;
        c2 = 0;
        for(int& n : nums){
            if(n == m1) c1++;
            if(n == m2) c2++;
        }
        int size = nums.size() / 3;
        vector<int> res;
        if(c1 > size) res.push_back(m1);
        if(m2 != m1 && c2 > size) res.push_back(m2);
        return res;
    }
};


int main() {

}
