//
// Created by Ke Ye on 2019-06-19.
//

#include <iostream>
#include <unordered_map>

using namespace std;

//In this question, it's hard to use sliding window to do this.
//Since we don't know whether we should continue look for next one.
//So we first record all number of characters. Then we split it into several parts.
//Repeat it until we find that all characters in current substring appear at least k times.
//To split it we can just use a for loop. but maybe the k is very big like 100.
//Ant there is a chracter which has 99 times....
//So just solving it one by one is OK.
class Solution{
public:
    int max_len = 0;
    int k = 0;

    void helper(string& s, int left, int right){
        unordered_map<char, int> count;
        for(int i = left; i < right; i++){
            count[s[i]]++;
        }
        int i = left;
        int j = left;
        //find each valid substring
        while(i < right){
            while(i < right && count[s[i]] < k) i++;
            j = i;
            while(j < right && count[s[j]] >= k) j++;
            if(i == left && j == right){
                max_len = max(max_len, j - i);
            }
            else{
                helper(s, i, j);
            }
            i = j;
        }
    }


    int longestSubstring(string s, int k){
        this->k = k;
        helper(s, 0, s.length());
        return max_len;
    }
};



int main(){


}