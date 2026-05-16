#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findSmallest(vector<int> &arr) {
        sort(arr.begin(), arr.end());

        long long res = 1;

        for (int x : arr) {
            // If x is greater than res,
            // then res cannot be formed
            if (x > res)
                break;

            // Extend the range
            res += x;
        }

        return res;
    }
};

int main() {
    int n;
    
    // Input size of array
    cin >> n;

    vector<int> arr(n);

    // Input array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;

    // Output result
    cout << obj.findSmallest(arr);

    return 0;
}