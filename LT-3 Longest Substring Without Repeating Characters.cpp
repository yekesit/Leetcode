//
// Created by Ke Ye on 2019-06-19.
//

#include <iostream>
#include <vector>

using namespace std;

//Review
//Obviously we can do same thing like. if we find the repeat one, check one by one to find the before one.
//waste some time.
//Just record the index last appearance. Then put the left index(start of the string) to the next one, perfect.
//Start on -1. every character appears at -1 first.


class Solution{
public:
    int lengthOfLongestSubstring(string s){
        int left = -1; //If never appears, index is -1, so the left most is -1;
        int max_len = 0;
        vector<int> index(256, -1); // 256 since all ASCII characters.
        for(int i = 0; i < s.length(); i++){
            left = max(index[s[i]] + 1, left);
            index[s[i]] = i;
            max_len = max(max_len, i - left + 1);
        }
        return max_len;
    }
};


int main() {

}