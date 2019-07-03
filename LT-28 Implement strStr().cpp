//
// Created by Ke Ye on 2019-07-03.
//

#include <iostream>
#include <vector>

using namespace std;

//KMP......
// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         int h = haystack.length();
//         int n = needle.length();
//         if(n == 0) return 0;
//         int failure[n];
//         for(int i = 0; i < n; i++)
//             failure[i] = 0;
//         int front = 1, tail = 0;
//         while(front < n){
//             if(needle[front] == needle[tail]){
//                 failure[front] = tail + 1;
//                 front++;
//                 tail++;
//             }
//             else if(tail > 0){
//                 tail = failure[tail - 1];
//             }
//             else if(tail == 0){
//                 tail = 0;
//                 front++;
//             }
//         }
//         int i = 0, j = 0;
//         while(i < h){
//             if(haystack[i] == needle[j]){
//                 if(j == n - 1)
//                     return i - j;
//                 i++;
//                 j++;
//             }
//             else if(j > 0){
//                 j = failure[j - 1];
//             }
//             else if(j == 0){
//                 j = 0;
//                 i++;
//             }
//         }
//         return -1;
//     }
// };



//Former solution from CS-600
//After learn something about KMP.
//I write it down


//Acutally we use two KMP. one for find prefix in needle. the other one is used to find needle in haystack
class Solution{
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        int h = haystack.length();
        int n = needle.length();
        //First KMP get next
        vector<int> next(n, -1);
        int i = 0;
        int j = -1;
        while(i < n - 1){
            //if needle[i] == needle[j], then needle[i + 1] has a prefix needle[0..j]
            //So if in the future we failure at needle[i + 1] we know that it will go to j + 1.
            if(j == -1 || needle[i] == needle[j]){
                i++;
                j++;
                next[i] = j;
            }
                //If not -1 and not equal, we know that there is a pair which are [i-j.....i - 1], [0.....j - 1].
                //Two string are same
                //So inorder to get a shorter prefix, assume length is k, we want to get [i-k...... i-1]. So how can we decide k
                //We know that for [j], j already has a failure place, which is next[j] = m. which split [0.....j - 1] as
                //[0.....m-1][m][m+1.....j-1], where [0....m-1] == [m+1....j-1]. According to the next defination
                //Same operation for [i-j.....i-j+m-1][i-j+m][i-j+m+1....i-1]
                //And here [i-j+m+1.....i-1] == [0.....m-1]
                //So if [m] == [i] we know that we get a shorter prefix.
                //So if [i] != [j] we just put j as next[j] to see if we can get a shorter one.
                //until j gets -1. LOL
            else{
                j = next[j];
            }
        }

        //Second KMP to get result
        i = 0;
        j = 0;
        while(i < h){
            if(j == -1 || haystack[i] == needle[j]){
                i++;
                j++;
            }
            else{
                j = next[j];
            }
            if(j == n) return i - n;
        }
        return -1;
    }
};

int main(){

}