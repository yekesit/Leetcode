//
// Created by Ke Ye on 2019-06-21.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        if(s.empty()) return 0;
        int len = s.length();
        if(len == 1) return value[s[0]];
        int res = value[s[len - 1]];
        for(int i = len - 2; i >= 0; i--){
            //here we can use >.. Since if current is less than the former one, we subtract it. LOL Nice thought.
            //Then we save space complexity.
            if(prev[s[i + 1]] == s[i]){
                res -= value[s[i]];
            }
            else{
                res += value[s[i]];
            }
        }
        return res;
    }
private:
    unordered_map<char, char> prev{
            {'V', 'I'},
            {'X', 'I'},
            {'L', 'X'},
            {'C', 'X'},
            {'D', 'C'},
            {'M', 'C'},
    };
    unordered_map<char, int> value{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
    };

};

int main() {

}