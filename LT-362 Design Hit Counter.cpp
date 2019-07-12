//
// Created by Ke Ye on 2019-07-12.
//

#include <iostream>
#include <map>
#include <queue>
//Same with using prefix sum in array
//It's just here we don't have an array
//So we use map to record every number...
//The difficult is that.... here we should resolve begin() situations.
//See solutoin, there is a method using fixed 300 size array... Have a try >> sliding window size is 300
// class HitCounter {
// public:
//     /** Initialize your data structure here. */
//     map<int, int> partial;
//     int pre_sum;
//     HitCounter() {
//         pre_sum = 0;
//     }

//     /** Record a hit.
//         @param timestamp - The current timestamp (in seconds granularity). */
//     void hit(int timestamp) {
//         pre_sum++;
//         if(partial.count(timestamp)){
//             partial[timestamp]++;
//         }
//         else{
//             partial[timestamp] = pre_sum;
//         }
//     }

//     /** Return the number of hits in the past 5 minutes.
//         @param timestamp - The current timestamp (in seconds granularity). */
//     int getHits(int timestamp) {
//         if(!partial.count(timestamp)){
//             partial[timestamp] = 0;
//         }
//         auto cur = partial.find(timestamp);
//         if(cur == partial.begin()) return cur->second;
//         auto pre = prev(cur);
//         if(!cur->second) cur->second = pre->second;

//         auto pre_300 = partial.lower_bound(cur->first - 300 + 1);
//         if(pre_300 == partial.begin()) return cur->second;
//         pre_300 = prev(pre_300);
//         return cur->second - pre_300->second;
//     }
// };



//Using sliding window thought 300
class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        count = 0;
    }

    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        while(!window.empty() && timestamp - window.front().first >= 300){
            count -= window.front().second;
            window.pop();
        }
        count++;
        if(!window.empty() && window.back().first == timestamp){
            window.back().second++;
        }
        else{
            window.push(make_pair(timestamp, 1));
        }
    }

    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while(!window.empty() && timestamp - window.front().first >= 300){
            count -= window.front().second;
            window.pop();
        }
        return count;
    }

private:
    queue<pair<int, int>> window;
    int count;
};