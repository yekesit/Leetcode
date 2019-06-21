//
// Created by Ke Ye on 2019-06-21.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution{
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> count;
        for(auto& c : cpdomains){
            helper(count, c);
        }
        vector<string> res;
        for(auto& c : count){
            res.push_back(to_string(c.second) + " " + c.first);
        }
        return res;
    }

private:
    void helper(unordered_map<string, int>& count, string& c){
        int index = c.find_first_of(' ');
        int num = stoi(c.substr(0, index));
        index++;//!!!!! ++ here since we need to go to start index of next string....
        while(index < c.length()) {
            count[c.substr(index)] += num;
            while (index < c.length() && c[index] != '.') index++;
            index++; // last line we find '.' Then go to next!!! Don't forget!!!
        }
    }
};

int main(){

}