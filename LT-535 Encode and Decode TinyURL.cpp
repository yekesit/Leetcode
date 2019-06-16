//
// Created by Ke Ye on 2019-06-16.
//
#include <iostream>
#include <random>
#include <unordered_map>
using namespace std;

//Link in problem is how to save short URL
//Here the problem is how to convert long URL to short URL
class Solution {
public:

    unordered_map<string, string> map;
    string alphabet = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        srand(int(time(nullptr)));
        string key = "";
        for(int i = 0; i < 6; i++){
            int index = rand() % 62;
            key += to_string(alphabet[index]);
        }
        if(map.find(key) == map.end()){
            map[key] = longUrl;
        }
        return "http://tinyurl.com/" + key;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int key_index = shortUrl.find_last_of('/');
        string key = shortUrl.substr(key_index + 1);
        return map[key];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));


int main(){
}