//
// Created by Ke Ye on 2019-06-27.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int cur_length = 0;
        int cur_str_len = 0;
        int cur_count = 0;
        int left = 0;
        int right = 0;
        int size = words.size();
        vector<string> ans;
        while(left < size){
            while(right < size && cur_length + words[right].length() <= maxWidth){
                cur_length += words[right].length() + 1;
                cur_str_len += words[right].length();
                cur_count++;
                right++;
            }
            cur_count--; // 4 people has 3 intervals
            //If meet the final line
            if(right == size){
                string res(maxWidth, ' ');
                int index = 0;
                while(left < right){
                    for(int i = 0; i < words[left].length(); i++, index++){
                        res[index] = words[left][i];
                    }
                    index++;
                    left++;
                }
                ans.push_back(res);
            }
                //If not the final line.
            else{
                int space = maxWidth - cur_str_len;
                string res(maxWidth, ' ');
                int index = 0;
                while(left < right){
                    for(int i = 0; i < words[left].length(); i++, index++){
                        res[index] = words[left][i];
                    }
                    left++;
                    if(!cur_count) break;
                    int interval = space / cur_count;
                    if(space % cur_count != 0) interval++;
                    cur_count--;
                    index += interval;
                    space -= interval;

                }
                ans.push_back(res);
            }
            cur_length = 0;
            cur_count = 0;
            cur_str_len = 0;
        }
        return ans;
    }
};



int main() {
    vector<string> input{"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;
    Solution s;
    vector<string> output = s.fullJustify(input, maxWidth);
    for(auto& o : output){
        cout << '{' << o <<  '}' << endl;
    }
}