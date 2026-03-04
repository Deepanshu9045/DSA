#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubarrayXOR(vector<int>& arr, int k) {
    int n = arr.size();

    int currentXor = 0;
    for (int i = 0; i < k; i++) {
        currentXor ^= arr[i];
    }

    int maxXor = currentXor;

    for (int i = k; i < n; i++) {
        currentXor ^= arr[i - k];  // remove left element
        currentXor ^= arr[i];      // add new element
        maxXor = max(maxXor, currentXor);
    }

    return maxXor;
}

int main() {
    int n, k;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: \n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter value of k: ";
    cin >> k;

    int result = maxSubarrayXOR(arr, k);

    cout << "Maximum XOR of subarray of size " << k << " is: " << result << endl;

    return 0;
}
