//
// Created by Ke Ye on 2019-06-21.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int len;
    int up;
    vector<string> generateParenthesis(int n) {
        len = 2 * n ;
        up = n;
        helper(0, 0, "");
        return res;
    }

private:
    vector<string> res;
    void helper(int left, int right, const string& solution){
        if(left + right == len){
            res.push_back(solution);
            return;
        }
        //If we can add one more left
        if(left < up){
            helper(left + 1, right, solution + '(');
        }
        //If left is more than right
        if(right < left){
            helper(left, right + 1, solution + ')');
        }
    }
};


int main(){

}