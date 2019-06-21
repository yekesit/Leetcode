//
// Created by Ke Ye on 2019-06-21.
//
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


class Solution{
public:
    unordered_set<string> res;
    int len;

    vector<string> removeInvalidParentheses(string s){
        if(s.empty()) return {""};
        len = s.length();
        int left_rem = 0;
        int right_rem = 0;
        for(const char& c : s){
            if(c == '('){
                left_rem++;
            }
            else if(c == ')'){
                if(left_rem > 0){
                    left_rem--;
                }
                else{
                    right_rem++;
                }
            }
        }
        if(left_rem == 0 && right_rem == 0) return {s};
        if(left_rem + right_rem == len) return {""};
        helper(s, 0, left_rem, right_rem, 0 , 0, "");
        vector<string> str_res(res.begin(), res.end());
        return str_res;
    }

private:
    void helper(string&s, int index, int left_rem, int right_rem, int left_count, int right_count, string solution){
        if(index == len){
            if(left_rem == 0 && right_rem == 0){
                res.insert(solution);
            }
            return;
        }

        if(s[index] != '(' && s[index] != ')'){
            while(index < len && s[index] != '(' && s[index] != ')'){
                solution += s[index++];
            }
            helper(s, index, left_rem, right_rem, left_count, right_count, solution);
        }

        if(s[index] == '('){
            if(left_rem > 0){
                helper(s, index + 1, left_rem - 1, right_rem, left_count, right_count, solution);
            }
            helper(s, index + 1, left_rem, right_rem, left_count + 1, right_count, solution + '(');
        }
        if(s[index] == ')'){
            if(right_rem > 0){
                helper(s, index + 1, left_rem, right_rem - 1, left_count, right_count, solution);
            }
            if(left_count > right_count){
                helper(s, index + 1, left_rem, right_rem, left_count, right_count + 1, solution + ')');
            }
        }
    }
};


int main(){

}