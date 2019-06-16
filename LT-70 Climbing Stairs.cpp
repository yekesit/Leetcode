#include <iostream>
#include <cmath>
using namespace std;

// Basci two pointes dp
// class Solution {
// public:
//     int climbStairs(int n) {
//         if(n <= 2) return n;
//         int one = 1;
//         int two = 2;
//         for(int i = 3; i <= n; i++){
//             int cur = one + two;
//             one = two;
//             two = cur;
//         }
//         return two;
//     }
// };

//Binets Method..... emmmm matrix.
//Don't understand, lol. Remember.
// class Solution{
// public:
//     int climbStairs(int n) {
//         int base[2][2] = {{1, 1}, {1, 0}};
//         int res[2][2] = {{1, 0}, {0, 1}};
//         pow(base, res, n);
//         return res[0][0];
//     }

//     void pow(int base[2][2], int res[2][2], int n){
//         while(n > 0){
//             if((n & 1) == 1){
//                 multiply(base, res);
//             }
//             n >>= 1;
//             multiply(base, base);
//         }
//     }

//     void multiply(int base[2][2], int res[2][2]){
//         long long next[2][2];
//         for(int i = 0; i < 2; i++)
//             for(int j = 0; j < 2; j++){
//                 next[i][j] = long(base[i][0]) * long(res[0][j]) + long(base[i][1]) * long(res[1][j]);
//             }
//         for(int i = 0; i < 2; i++)
//             for(int j = 0; j < 2; j++)
//                 res[i][j] = next[i][j];
//     }
// };

//fibonacci formula

class Solution{
public:
    int climbStairs(int n){
        double sqrt5 = sqrt(5);
        double fibn = pow((1 + sqrt5) / 2, n + 1) - pow((1 - sqrt5) / 2, n + 1);
        return (int)(fibn / sqrt5);
    }
};

int main(){
    Solution s;
    cout << s.climbStairs(35);
}