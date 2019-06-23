//
// Created by Ke Ye on 2019-06-23.
//

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;


//Review Memorization

//When we use recursion here. Basic condition is, if next exists, we combine them. If not. means we get failure here.
//Just return original cur, which is empty;
//But here is a situation.
//If string is "tmp", and there is a "tmp" in dict.
//Then we may get the final index which is 3.
//So what kind of information we should return to tell last recursion that, I am the end??
//So we use "" in vector to show that the code reaches the end of string.
class Solution{
public:
    unordered_set<string> dict;
    unordered_map<int, vector<string>> exist;
    int len;
    vector<string> wordBreak(string s, vector<string>& wordDict){
        dict.insert(wordDict.begin(), wordDict.end());
        len = s.length();
        return helper(s, 0);
    }



    vector<string> helper(string& s, int index){
        if(exist.find(index) != exist.end()){
            return exist[index];
        }
        if(index == len){
            return {""};
        }
        vector<string> cur{};
        for(int i = index + 1; i <= len; i++){
            string tmp = s.substr(index, i - index);
            if(dict.find(tmp) != dict.end()){
                vector<string> next = helper(s, i);
                for(auto& n : next){
                    string new_tmp = "";
                    new_tmp += tmp;
                    new_tmp += n == "" ? "" : " ";
                    new_tmp += n;
                    cur.push_back(new_tmp);
                }
            }
        }
        exist[index] = cur;
        return cur;
    }
};

int main() {

}