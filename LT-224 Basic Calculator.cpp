//
// Created by Ke Ye on 2019-06-25.
//

#include <iostream>
#include <stack>

using namespace std;


class Solution {
public:
    int calculate(string s) {
        if(s.empty()) return 0;
        stack<char> ope;
        stack<int> num;
        int i = 0;
        int len = s.length();
        while(i < len){
            while(i < len && s[i] == ' ') i++;
            if(i == len) break;
            if(s[i] == '(') {
                ope.push(s[i]);
            }
            else if(s[i] == ')') {
                while(ope.top() != '('){
                    int num2 = num.top(); num.pop();
                    int num1 = num.top(); num.pop();
                    if(ope.top() == '+'){
                        num.push(num1 + num2);
                    }
                    else{
                        num.push(num1 - num2);
                    }
                    ope.pop();
                }
                ope.pop();
            }
            else if(s[i] == '+' || s[i] == '-'){
                if(ope.empty() || ope.top() == '('){
                    ope.push(s[i]);
                }
                else{
                    int num2 = num.top(); num.pop();
                    int num1 = num.top(); num.pop();
                    if(ope.top() == '+'){
                        num.push(num1 + num2);
                    }
                    else{
                        num.push(num1 - num2);
                    }
                    ope.pop();
                    ope.push(s[i]);
                }
            }
            else{
                int j = i;
                while(j <  len && s[j] >= '0' && s[j] <= '9') j++;
                string cur = s.substr(i, j - i);
                int cur_num = stoi(cur);
                num.push(cur_num);
                i = j - 1;
            }
            i++;
        }
        while(!ope.empty()){
            int num2 = num.top(); num.pop();
            int num1 = num.top(); num.pop();
            if(ope.top() == '+'){
                num.push(num1 + num2);
            }
            else{
                num.push(num1 - num2);
            }
            ope.pop();
        }
        return num.top();
    }
};

int main() {
    Solution s;
    string input = " 2-1 + 2 ";
    cout << s.calculate(input);
}