// C++ program to find sub-array having maximum
// sum of elements modulo m.
#include <iostream>
#include <set>
using namespace std;

// Return the maximum sum subarray mod m.
int maxSubarray(int arr[], int n, int m)
{
    int x, prefix = 0, maxim = 0;

    set<int> S;
    S.insert(0);

    // Traversing the array.
    for (int i = 0; i < n; i++)
    {
        // Finding prefix sum.
        prefix = (prefix + arr[i])%m;
        // Finding maximum of prefix sum.
        maxim = max(maxim, prefix);

        // Finding iterator pointing to the first
        // element that is not less than value
        // "prefix + 1", i.e., greater than or
        // equal to this value.
        auto it = S.lower_bound(prefix+1);

        if (it != S.end()) {
            cout << prefix - (*it) + m << endl;
            maxim = max(maxim, prefix - (*it) + m);
        }

        // Inserting prefix in the set.
        S.insert(prefix);
    }

    return maxim;
}

// Driver Program
int main()
{
    int arr[] = { 4, 2, 3, 3 };
    int n = sizeof(arr)/sizeof(arr[0]);
    int m = 9;
    cout << maxSubarray(arr, n, m) << endl;
    return 0;
}
