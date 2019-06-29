//
// Created by Ke Ye on 2019-06-29.
//

#include <iostream>
#include <vector>


using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

//Basic solution.
//Dfs firsr get the total depth, then do DFS again from root.
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        depth = 0;
        findDepth(nestedList, 0);
        return levelSum(nestedList, depth);
    }
private:
    int depth;
    void findDepth(vector<NestedInteger>& nestedList, int cur_depth){
        for(auto& n : nestedList){
            if(n.isInteger()){
                depth = max(depth, cur_depth + 1);
            }
            else{
                findDepth(n.getList(), cur_depth + 1);
            }
        }
    }

    int levelSum(vector<NestedInteger>& nestedList, int cur_depth){
        int sum = 0;
        for(auto& n : nestedList){
            if(n.isInteger()){
                sum += n.getInteger() * cur_depth;
            }
            else{
                sum += levelSum(n.getList(), cur_depth - 1);
            }
        }
        return sum;
    }
};


//Actually we can't go from top to bottom.
//Because here the situation [[[]], 1]
//Actually [[]] is empty and doesn't effect the height, so finaly result is 1
//If we do from top to bottom, we will get 3.
//So two ways, either use a map to save all number with its depth. Then use max depth to subtract and get the answer
//or like the solution above, get depth first, then dfs again
//If there is no [[]]. we can use bfs to calculate result level by level.
//And in this case we can keep growing our result.(also remembe this, since some interview may no [[]] input).

int main() {

}