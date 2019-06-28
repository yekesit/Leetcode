//
// Created by Ke Ye on 2019-06-28.
//

#include <iostream>
#include <vector>

using namespace std;

//Basic thought, use basic greedy. Every loop choose the first (n + 1)th tasks.
//If we can't we should add interval here.
//Pretty slow.. LOL

//Actually we don't care about the name of taske... just number.
//After change to only number, it becomes faster.
int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
// class Solution {
// public:

//     int leastInterval(vector<char>& tasks, int n) {
//         unordered_map<char, int> count;
//         for(auto& t : tasks){
//             count[t]++;
//         }
//         priority_queue<int> que;
//         for(auto& c : count){
//             que.push(c.second);
//         }
//         int step = 0;
//         while(!que.empty()){
//             vector<int> tmp;
//             int i = 0;
//             for(; i <= n && !que.empty(); i++){
//                 int cur = que.top(); que.pop();
//                 if(--cur != 0){
//                     tmp.push_back(cur);
//                 }
//             }
//             if(que.empty() && tmp.empty()){
//                 step += i;
//             }
//             else{
//                 step += n + 1;
//                 for(auto& t : tmp){
//                     que.push(t);
//                 }
//             }

//         }
//         return step;

//     }
// };


//After see the exaplanation I got the idea.
//In this question, the most important problem is the task with lasgest number.
//Every other task should help it to finish within the least intervals.
//Just like, A X X X X X A X X X X X A X X X X X .......
//the largest number split the whole taks series into several parts, and we should use others to fill in every "X"
//And since A is the largest one, if there is any other task has the same numebr with A
//Like A 5 B 5.
//Then what we need is 4 of B, since 5 A has 4 intervals between each A. the last one of B can be just put at the last after
//A since it won't get any ide here(only the largest one will cause idles)
//Then, why only the largest one can get idle, who not others. For example.
//Now we have A X X X A X X X A X X X A
//If we can use something like B C D to fill in these blanks to repalce X. We solve the problem for A
//Since A need the most concentration here to make it use least idles.
//Then what if there are other thing like E F G H???
//I first don't know it since I just limit my thought as we should only execute tasks as interval number
//Then well, actually. we can put all others into these X like
//A X X X E F G A X X X E F A X X X G
//Obviously, if we don't limit that there should be n tasks between two A, we can add more and more.....
//So the question then changes to, whether we can fill in these original X blank. If so, nice. If not, ok we add them to
//the total length.



class Solution{
public:

    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for(auto& t : tasks){
            count[t - 'A']++;
        }
        sort(count.begin(), count.end());
        int max_num = count[25] - 1;
        int idles = max_num * n;
        for(int i = 24; i >= 0 && count[i] != 0; i--){
            //if we have 5A and 5B, we only care about 4B, since there are 4 intervals.
            idles -= min(count[i], max_num);
        }
        return idles > 0 ? tasks.size() + idles : tasks.size();
    }
};


int main() {
    vector<char> input{'A','A','A','B','B','B'};
    int n = 2;
}