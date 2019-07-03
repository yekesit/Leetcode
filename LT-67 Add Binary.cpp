//
// Created by Ke Ye on 2019-07-02.
//

#include <iostream>

using namespace std;



// class Solution {
// public:
//     string addBinary(string a, string b) {

//         string res;
//         res.resize(max(a.length(), b.length()) + 1);

//         int k = res.length() - 1;
//         int i = a.length() - 1;
//         int j = b.length() - 1;
//         char carry = '0';
//         while(i >= 0 && j >= 0){
//             if(a[i] == '0' && b[j] == '0'){
//                 res[k] = carry;
//                 carry = '0';
//             }
//             else if(a[i] == '1' && b[j] == '1'){
//                 res[k] = carry;
//                 carry = '1';
//             }
//             else{
//                 if(carry == '0'){
//                     res[k] = '1';
//                     carry = '0';
//                 }
//                 else{
//                     res[k] = '0';
//                     carry = '1';
//                 }
//             }
//             i--;
//             j--;
//             k--;
//         }
//         while(i >= 0){
//             if(carry == '0'){
//                 res[k] = a[i];
//             }
//             else{
//                 if(a[i] == '1'){
//                     res[k] = '0';
//                     carry = '1';
//                 }
//                 else{
//                     res[k] = '1';
//                     carry = '0';
//                 }
//             }
//             i--;
//             k--;
//         }
//         while(j >= 0){
//             if(carry == '0'){
//                 res[k] = b[j];
//             }
//             else{
//                 if(b[j] == '1'){
//                     res[k] = '0';
//                     carry = '1';
//                 }
//                 else{
//                     res[k] = '1';
//                     carry = '0';
//                 }
//             }
//             j--;
//             k--;
//         }
//         if(carry == '0') return res.substr(1);
//         res[0] = '1';
//         return res;

//     }
// };


//Same with another question. if we are out of bound. just put it as '0'....
//So we don't need do two more loops. lOL.
//Remember this !!!!

//Concise code. lol.
class Solution{
public:
    string addBinary(string a, string b) {
        string res(max(a.length(), b.length()) + 1, ' ');
        int k = res.length() - 1;
        int i = a.length() - 1;
        int j = b.length() - 1;

        char carry = '0';
        while(i >= 0 || j >= 0 || carry == '1'){
            char na = i >= 0 ? a[i--] : '0';
            char nb = j >= 0 ? b[j--] : '0';
            res[k--] = na ^ nb ^ carry;
            carry = na + nb + carry > 145 ? '1' : '0';
        }

        return res[0] == ' ' ? res.substr(1) : res;

    }
};

int main() {


}