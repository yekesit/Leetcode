//
// Created by Ke Ye on 2019-06-21.
//

#include <iostream>
#include <vector>

using namespace std;

//Wow faster and use less space. LOL.
//Nice split into two parts.
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<pair<string, string>> letter;
        vector<string> digit;
        for(auto l : logs){
            int index = l.find_first_of(' ');
            char next = l[index + 1];
            if(next >= 'a' && next <= 'z'){
                letter.push_back(make_pair(l.substr(index), l.substr(0, index)));
            }
            else{
                digit.push_back(l);
            }
        }
        //if we save string as first is value and second is log number.
        //Then we can easily use sort to get final result.
        //Then just combina them together. LOL.
        sort(letter.begin(), letter.end());
        vector<string> res;
        for(auto l : letter){
            res.push_back(l.second + l.first);
        }
        res.insert(res.end(), digit.begin(), digit.end());
        return res;
    }
};

//review. old solution use pair to save string and log number then easy to sort.
//What if we use personality sort?

// class Solution{
// public:
//     vector<string> reorderLogFiles(vector<string>& logs) {
//         vector<string> letter;
//         vector<string> digit;
//         for(auto& l : logs){
//             int index = l.find_first_of(' ') + 1;
//             if(l[index] >= '0' && l[index] <= '9'){
//                 digit.emplace_back(l);
//             }
//             else{
//                 letter.emplace_back(l);
//             }
//         }
//         sort(letter.begin(), letter.end(), [](string& s1, string& s2){
//             int i1 = s1.find_first_of(' ');
//             int i2 = s2.find_first_of(' ');
//             string t1 = s1.substr(i1 + 1);
//             string t2 = s2.substr(i2 + 1);
//             if(t1 == t2){
//                 return s1.substr(0, i1) < s2.substr(0, i2);
//             }
//             else{
//                 return t1 < t2;
//             }
//         });
//         vector<string> res(letter.begin(), letter.end());
//         res.insert(res.end(), digit.begin(), digit.end());
//         return res;
//     }
// };

//Seems split it into two parts is good.
//Since when we use sort for pair<>, it automatically compare the first one, and then if first one equals, compare second one.
//Just conciser than the second solution. Emmmmm


int main() {

}