//
// Created by Ke Ye on 2019-07-04.
//

#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        if(s.empty()) return 0;
        stack<long> nums;
        stack<char> opes;
        int len = s.length();
        int i = 0;
        long num1 = 0;
        long num2 = 0;
        char ope;
        char pre = '+';
        int sign = 1;
        while(i < len){
            if(s[i] == ' '){
                //do nothing
            }
            else if(s[i] == '('){
                opes.push(s[i]);
                pre = '(';
            }
            else if(s[i] == ')'){
                while(opes.top() != '('){
                    num2 = nums.top(); nums.pop();
                    num1 = nums.top(); nums.pop();
                    ope = opes.top(); opes.pop();
                    nums.push(calculate(num1, num2, ope));
                }
                opes.pop(); // '('
            }
            else if(pri.find(s[i]) != pri.end()){
                if(pri.find(pre) != pri.end()){
                    sign = s[i] == '-' ? -1 : 1;
                }
                else{
                    while(!opes.empty() && pri[opes.top()] >= pri[s[i]]){
                        num2 = nums.top(); nums.pop();
                        num1 = nums.top(); nums.pop();
                        ope = opes.top(); opes.pop();
                        nums.push(calculate(num1, num2, ope));
                    }
                    opes.push(s[i]);
                }
            }
            else{
                int j = i;
                while(j < len && isdigit(s[j])){
                    j++;
                }
                nums.push(stol(s.substr(i, j - i)) * sign);
                i = j - 1;
                pre = '0';
                sign = 1;
            }
            i++;
        }
        while(!opes.empty()){
            num2 = nums.top(); nums.pop();
            num1 = nums.top(); nums.pop();
            ope = opes.top(); opes.pop();
            nums.push(calculate(num1, num2, ope));
        }
        return nums.top();

    }
private:
    unordered_map<char, int> pri{
            {'(', 0},
            {'+', 2},
            {'-', 2},
            {'*', 3},
            {'/', 3}
    };
    long calculate(long num1, long num2, char ope){
        switch(ope){
            case '+': return num1 + num2;
            case '-': return num1 - num2;
            case '*': return num1 * num2;
            case '/': return num1 / num2;
        }
        return 0;
    }
};

int main() {

}