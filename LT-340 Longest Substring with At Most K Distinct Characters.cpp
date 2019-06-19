//
// Created by Ke Ye on 2019-06-19.
//

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution{
public:
    int lengthOfLongestSubstringKDistinct(string s, int k){
        if(s.empty()) return 0;
        int len = s.length();
        int left = 0, right = 0;
        int res = 0;
        unordered_map<char, int> exist;
        while(right < len){
            char cur = s[right];
            if(exist[cur]++ == 0){
                k--;
            }
            // if(k == 0){
            //     int cur_len = right - left + 1;
            //     res = max(res, cur_len);
            // }
            if(k < 0){
                res = max(res, right - left);
                while(--exist[s[left]] != 0){
                    left++;
                }
                left++;
                k++;
            }
            right++;
        }
        res = max(res, right - left);
        return res;
    }
};

int main(){
    Solution s;
    string input = "a@b$5!a8alskj234jasdf*()@$&%&#FJAvjjdaurNNMa8ASDF-0321jf?>{}L:fh";
    int k = 10;
    cout << s.lengthOfLongestSubstringKDistinct(input, k);
}