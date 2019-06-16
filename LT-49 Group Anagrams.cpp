//
// Created by Ke Ye on 2019-06-15.
//

#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>

using namespace std;

//If we want to use vector, then we should use map, and map is slower than unordered_map
// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         map<vector<int>, vector<string>> res_map;
//         for(auto& str : strs){
//             vector<int> count(26, 0);
//             for(auto&s : str){
//                 count[s - 'a']++;
//             }
//             res_map[count].push_back(str);
//         }
//         vector<vector<string>> res;
//         for(auto& r : res){
//             res.push_back(r.second);
//         }
//         return res;
//     }
// };

// //Try solution..... so long the string, slower
// class Solution{
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs){
//         unordered_map<string, vector<string>> res;
//         vector<vector<string>> ans;
//         for(const auto& str : strs){
//             vector<int> count(26, 0);
//             for(auto& s : str){
//                 count[s - 'a']++;
//             }
//             string tmp = "";
//             for(auto c: count){
//                 tmp += to_string(c) + "#";
//             }
//             res[tmp].emplace_back(str);
//         }
//         for(auto& r : res){
//             ans.emplace_back(r.second);
//         }
//         return ans;
//     }
// };

//Maybe the sort function is perfect
//Sort is much more clever.....
//Similar string has similar number , also can be rearrange in same order!!!!
class Solution{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs){
        unordered_map<string, vector<string>> res_map;
        for(auto& str: strs){
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            res_map[tmp].push_back(str);
        }
        vector<vector<string>> res(res_map.size());
        int index = 0;
        for(auto& r : res_map){
            res[index++] = r.second;
        }
        return res;
    }
};


int main(){

}