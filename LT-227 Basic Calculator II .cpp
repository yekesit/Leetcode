//
// Created by Ke Ye on 2019-07-02.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
//First solution, according to priority to calculate one by one by using stack... So I have to modify solution about
//expression tree.. LOL
// class Solution {
// public:
//     int calculate(string s) {
//         if(s.empty()) return 0;
//         stack<char> ope;
//         stack<int> res;
//         int len = s.length();
//         int i = 0;
//         int j = 0;
//         int num1, num2;
//         char cur_ope;
//         while(i < len){
//             if(s[i] == ' '){
//                 i++;
//                 continue;
//             }
//             if(isdigit(s[i])){
//                 j = i + 1;
//                 while(j < len && isdigit(s[j])) j++;
//                 res.push(stoi(s.substr(i, j - i)));
//                 i = j - 1;
//             }
//             else{
//                 if(ope.empty()){
//                     ope.push(s[i]);
//                 }
//                 else{
//                     while(!ope.empty() && pri[ope.top()] >= pri[s[i]]){
//                         num2 = res.top(); res.pop();
//                         num1 = res.top(); res.pop();
//                         cur_ope = ope.top(); ope.pop();
//                         res.push(calculate(num1, num2, cur_ope));
//                     }
//                     ope.push(s[i]);
//                 }
//             }
//             i++;
//         }
//         while(!ope.empty()){
//             num2 = res.top(); res.pop();
//             num1 = res.top(); res.pop();
//             cur_ope = ope.top(); ope.pop();
//             res.push(calculate(num1, num2, cur_ope));
//         }
//         return res.top();
//     }
// private:
//     unordered_map<char, int> pri{
//         {'+', 1},
//         {'-', 1},
//         {'*', 2},
//         {'/', 2}
//     };
//     int calculate(int num1, int num2, char ope){
//         switch(ope){
//             case '+': return num1 + num2;
//             case '-': return num1 - num2;
//             case '*': return num1 * num2;
//             case '/': return num1 / num2;
//         }
//         return 0;
//     }
// };


//See a solution. Not so complext
//It's just, do it one by one. use a variable to record all result before
//Use another variable to record previous number. Since if we meet / or *, we should keep current number
//And get next number to calculte the current one.. then keep it again.

//And learn another good thing... use istringsteam to get one by one... Since
// str >> int . we get int.. str >> char we get char... and it automatically skip the space ' '.
//Very nice thought. Try it.


class Solution{
public:
    int calculate(string s) {
        istringstream str(s);
        int pre, cur;
        int res = 0;
        int sign = 1;
        char ope;
        str >> pre;
        while(str >> ope){
            if(ope == '+' || ope == '-'){
                res += pre;
                sign = ope == '+'? 1 : -1;
                str >> pre;
                pre *= sign;
            }
            else{
                str >> cur;
                if(ope == '*'){
                    pre *= cur;
                }
                else{
                    pre /= cur;
                }
            }
        }
        res += pre;
        return res;
    }
};








int main(){

}