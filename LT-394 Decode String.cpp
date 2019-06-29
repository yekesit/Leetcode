//
// Created by Ke Ye on 2019-06-28.
//


#include <iostream>

using namespace std;

int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

//Basic solution, meet digit(number) then dfs get the whole string
//Try to make code concise
// class Solution {
// public:
//     int len;
//     string helper(string& s, int& i){
//         if(i == len) return "";
//         //Get the num
//         int num_idx = s.find_first_of('[', i);
//         int num = stoi(s.substr(i, num_idx - i));
//         i = num_idx + 1;
//         //Get the part of string
//         string cur = "";
//         while(s[i] != ']'){
//             if(isalpha(s[i])){
//                 cur += s[i];
//             }
//             else if(isdigit(s[i])){
//                 cur += helper(s, i);
//             }
//             i++;
//         }
//         //Combine together then return
//         string tmp = "";
//         for(int j = 0; j < num; j++){
//             tmp += cur;
//         }
//         return tmp;

//     }

//     string decodeString(string s) {
//         if(s.empty()) return "";
//         len = s.length();
//         int index = 0;
//         string res = "";
//         while(index < len){
//             if(isdigit(s[index])){
//                 res += helper(s, index);
//                 index++;
//             }
//             else{
//                 while(index < len && isalpha(s[index])){
//                     res += s[index];
//                     index++;
//                 }
//             }
//         }
//         return res;
//     }
// };


//actually I just get the thought. If we have "3[a]2[bc]"
//we can assume that is "1[3[a]2[bc]]"
//Then we can put all string into recursion so that the code will be concise
//It's just the original code don't have a '1[]'
//So to avoid overflow, for middle one we use ']' to control bound, for outside, we use < length
//Emmm it's just... I need to implement, not just only think about it...
//So suck, if we have the same format, we can make the code more beautiful. lol
//But here, since we can't do somthing like first calculate num then inside.
//So we change strategy to when we meet a number, we get the string belong to this number.
//Or we can modify the original string lol.

class Solution{
public:
    int len;
    string helper(string& s, int& i){
        string cur = "";
        while(i < len && s[i] != ']'){
            cout << i << endl;
            if(isalpha(s[i])){
                cur += s[i];
                // i++;
            }
            else{
                int num_index = s.find_first_of('[', i); // remember find from current i
                // if don't want to write int this way, we can use
                // num = num * 10 + s[i] - '0';
                // Same.. LOL. I am just familiar with this method
                int num = stoi(s.substr(i, num_index - i));
                i = num_index + 1;
                string next = helper(s, i);
                // i++; // pass ']'
                while(num--){
                    cur += next;
                }
            }
            i++;
        }
        return cur;
    }


    string decodeString(string s){
        if(s.empty()) return "";
        len = s.length();
        int i = 0;
        return helper(s, i);
    }
};


//Emmm two methods have same time comlexcity.
//And second one code is concise. Emmmm
//But I like my code LOL.




int main() {

}
