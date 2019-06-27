//
// Created by Ke Ye on 2019-06-26.
//


#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;


// class Solution {
// public:

//     vector<string> findItinerary(vector<vector<string>>& tickets) {
//         if(tickets.empty()) return {};
//         for(auto& t : tickets){
//             map[t[0]][t[1]]++;
//         }

//         total = tickets.size() + 1;
//         helper({}, "JFK", 0);
//         return res;
//     }
// private:
//     unordered_map<string, unordered_map<string, int>> map;
//     vector<string> res;
//     int total;
//     void helper(vector<string> solution, const string& cur, int count){
//         solution.push_back(cur);
//         count++;
//         if(count == total){
//             if(res.empty() || res > solution){
//                 res = solution;
//             }
//             return;
//         }
//         for(auto& m : map[cur]){
//             if(m.second > 0){
//                 m.second--;
//                 helper(solution, m.first, count);
//                 m.second++;
//             }
//         }
//     }
// };

//Solution above is a brute-force solution.... Just go over every possible path and see if it is a valid one
//Then compare to exist path to see which one is smaller...
//Obvioulsy it works, but also TLE... So sad.


//First, I don't use set recently....
//Here is a complex directed graph, so my original thought is using a vector to save all neighbors
//But then I find that it requires small solution... So I should sort the neighbors and use the smallest if possible.
//Then I meet new problem.. If we always choose the smallest one, then pop it from neighbors, we may not get a full path
//Since we may not go to next node through this smallest node.. Then no valid result here.
//Then I think for backtracking, if this node doesn't make sense, we pop it then we push it again
//But if we push it back... we will keep doing same thing again and again, then code dead...
//So finally I use a map to save all information for each node,.... Then brute-force... So sad.

//Then I see solution that, they use multiset. Very clever, since multiset can sort automatically, which means you can
//always get the smallest one by using multiset.begin()
//Then I still feel confused, because multiset is same with my sorted vector solution. I thought they may do duplicate
//things again and again. But they don't
//Then I try to understand their solution...

//Then I find, my problem is that, no matter what kind of method I use, I just add the node into path when I meet the node.
//Then step by step until I add all nodes and check bigger or smaller. So my solution is really slow. Check all path.
//Their solution is, we don't immediately add the current node because this place may not be the right place for this node.
//Just find again and again, if we find a node that has no other neighbors, which means
//1. this node is the original final node, which means we can only get in that node but not get out originally.
//Then we know this node should be the last one. we just push_back it into result vector
//2. this node is not the original final node, but we already go from all neighbors from this node
//Ok add it into path

//The thought is, we always find the current last one, since if we choose from begin, there are many possible ways,
//Which finally leads to brute-force.
//But here in this question, it guarantees that there is a valid path for reaching all nodes according to tickests
//So we just find the last one again and again.（反正最终一定能走完，就每次从当前最后一个做，最后倒过来就行）

//To be simple, it's just, every time we check if we can go through the whole path with current smallest node
//If so, this smallest node is the desired result. If not, ok it should be located near the end.


//从起始点出发，一直延小的走下去，如果能走完，意味着这条路是对的。如果走不完，意味着我们要先从其他地方走，最后再走到这里
//核心问题在于，这条路根据题意，是一定能走完的，数据是ok的。所以只要遇到这条走不完的路，那就意味着我们不可能先走这部分。
//就一定要先走另外一部分。那么这部分就放在最后走，也就是上面说的一个一个push_back，最后整个转回来就行了。
//主要是充分利用了题目说的这个行程一定是走得完的，也就是这个有向图一定是可以从JFK出发走成功的。。。
//所以才每次可以从最小的走，反正只要走不完就放最后走就行。。。反正能走完。。23333

class Solution{
public:
    vector<string> findItinerary(vector<vector<string>>& tickets){
        if(tickets.empty()) return {};
        unordered_map<string, multiset<string>> go;
        for(auto& t : tickets){
            go[t[0]].insert(t[1]);
        }

        vector<string> res;
        helper(go, "JFK", res);
        reverse(res.begin(), res.end());
        return res;
    }

    void helper(unordered_map<string, multiset<string>>& go, const string& cur, vector<string>& res){
        while(!go[cur].empty()){
            auto small = go[cur].begin();
            string tmp = *small;
            go[cur].erase(small);
            helper(go, tmp, res);
        }
        res.push_back(cur);
    }

};

int main(){
    vector<vector<string>> tickets{
            {"AXA","EZE"},{"EZE","AUA"},{"ADL","JFK"},{"ADL","TIA"},{"AUA","AXA"},{"EZE","TIA"},
            {"EZE","TIA"},{"AXA","EZE"},{"EZE","ADL"},{"ANU","EZE"},{"TIA","EZE"},{"JFK","ADL"},
            {"AUA","JFK"},{"JFK","EZE"},{"EZE","ANU"},{"ADL","AUA"},{"ANU","AXA"},{"AXA","ADL"},
            {"AUA","JFK"},{"EZE","ADL"},{"ANU","TIA"},{"AUA","JFK"},{"TIA","JFK"},{"EZE","AUA"},
            {"AXA","EZE"},{"AUA","ANU"},{"ADL","AXA"},{"EZE","ADL"},{"AUA","ANU"},{"AXA","EZE"},
            {"TIA","AUA"},{"AXA","EZE"},{"AUA","SYD"},{"ADL","JFK"},{"EZE","AUA"},{"ADL","ANU"},
            {"AUA","TIA"},{"ADL","EZE"},{"TIA","JFK"},{"AXA","ANU"},{"JFK","AXA"},{"JFK","ADL"},
            {"ADL","EZE"},{"AXA","TIA"},{"JFK","AUA"},{"ADL","EZE"},{"JFK","ADL"},{"ADL","AXA"},
            {"TIA","AUA"},{"AXA","JFK"},{"ADL","AUA"},{"TIA","JFK"},{"JFK","ADL"},{"JFK","ADL"},
            {"ANU","AXA"},{"TIA","AXA"},{"EZE","JFK"},{"EZE","AXA"},{"ADL","TIA"},{"JFK","AUA"},
            {"TIA","EZE"},{"EZE","ADL"},{"JFK","ANU"},{"TIA","AUA"},{"EZE","ADL"},{"ADL","JFK"},
            {"ANU","AXA"},{"AUA","AXA"},{"ANU","EZE"},{"ADL","AXA"},{"ANU","AXA"},{"TIA","ADL"},
            {"JFK","ADL"},{"JFK","TIA"},{"AUA","ADL"},{"AUA","TIA"},{"TIA","JFK"},{"EZE","JFK"},
            {"AUA","ADL"},{"ADL","AUA"},{"EZE","ANU"},{"ADL","ANU"},{"AUA","AXA"},{"AXA","TIA"},
            {"AXA","TIA"},{"ADL","AXA"},{"EZE","AXA"},{"AXA","JFK"},{"JFK","AUA"},{"ANU","ADL"},
            {"AXA","TIA"},{"ANU","AUA"},{"JFK","EZE"},{"AXA","ADL"},{"TIA","EZE"},{"JFK","AXA"},
            {"AXA","ADL"},{"EZE","AUA"},{"AXA","ANU"},{"ADL","EZE"},{"AUA","EZE"}
    };
    Solution s;
    vector<string> res = s.findItinerary(tickets);
    for(auto& r : res){
        cout << r << ' ';
    }
}