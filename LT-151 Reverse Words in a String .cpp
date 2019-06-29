//
// Created by Ke Ye on 2019-06-29.
//

#include <iostream>

using namespace std;

class Solution{
public:
    string reverseWords(string& s) {
        if(s.empty()) return "";
        int len = s.length();
        int i = len - 1;
        int j = i;
        string res;
        while(i >= 0){
            //Find all space
            while(j >= 0 && s[j] == ' ') j--;
            i = j;
            //Find the word
            while(i >= 0 && s[i] != ' ') i--;
            string str = s.substr(i + 1, j - i);
            res += " ";
            res += str;
            j = i;
        }

        //Since here problem requires now space at both two ends.
        //So we should write down a condition
        //Our solution has two formation
        //_xxxxx_xxxxx_xxxx_
        //_xxxxx_xxxxx_xxxx
        //the last _ depends on whether there are space in the front of original string
        if(res.back() == ' ')
            return res.substr(1, res.length() - 2);
        else
            return res.substr(1);

    }
};
int main() {

}