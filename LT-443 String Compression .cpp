//
// Created by Ke Ye on 2019-06-29.
//

#include <iostream>
#include <vector>


using namespace std;


class Solution{
public:
    int compress(vector<char>& chars){
        if(chars.empty()) return 0;
        int len = 0;
        int count = 0;
        int size = chars.size();
        for(int i = 0; i < size; i++){
            if(i + 1 == size || chars[i] != chars[i + 1]){
                count++; //current one
                chars[len++] = chars[i]; //write the current character
                //'1' doesn't count
                if(count != 1){
                    string num = to_string(count);
                    for(char& n : num){
                        chars[len++] = n;
                    }
                }
            }
            else{
                count++;
            }
        }
        //Since len is the length of final output
        //And we can use len to always point to next begin of next character.
        //No overflow and code will be concise.(index = len - 1) LOL
        return len;
    }
};

int main() {

}