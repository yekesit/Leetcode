//
// Created by Ke Ye on 2019-07-14.
//


#include <iostream>

using namespace std;

//So many possible path... Boom
// class Solution {
// public:
//     bool reachingPoints(int sx, int sy, int tx, int ty) {
//         return dfs(sx, sy, tx, ty);
//     }
// private:
//     bool dfs(int sx, int sy, int tx, int ty){
//         if(sx > tx || sy > ty) return false;
//         if(sx == tx && sy == ty) return true;
//         return dfs(sx + sy, sy, tx, ty) || dfs(sx, sx + sy, tx, ty);
//     }
// };

//here we should come up with the rule that
//for final tx ty. Assume they are not same like 3 5
//Then 3 5 must come from 3, 2... Only one way here
//So if we can get this rule... we just go back from tx and ty.... then
//Recursion won't be 2 ^ N.... it will be at most ty - tx if one of them is 1
//Then still TLE... EMMM sine if there is a 1 after subtract..... the loop becomes very large...
//LOL. solve it after going back home.


//According to the rule, we go back from tx and ty
//so we keep reduce tx and ty
//Then there are some situations
//case 1 : tx < sx or ty < sy  >> means we can't get to original point
//case 2 : tx == sx and ty == sy >> we reach the original point
//case 3 : tx == sx but ty != sy >> meas we reach the same column with original point but different rows
//         So now, we can only reduce ty, and each we reduce is tx. so we just see the difference between
//         ty and sy which is (ty - sy) % tx == 0 or not. If so means we can get to that original point
//case 4 : tx != sx but ty == sy.. same with case 3
//This question is about math rule... not so many algorithms...
//So if we can't find the rule.. we die... LOL

class Solution{
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while(tx >= sx && ty >= sy){
            if(tx == sx && ty == sy) return true;
            if(tx == sx){
                return (ty - sy) % tx == 0;
            }
            if(ty == sy){
                return (tx - sx) % ty == 0;
            }
            if(tx > ty){
                tx -= ty;
            }
            else{
                ty -= tx;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    cout<< s.reachingPoints(35, 13, 455955547, 420098884);
}