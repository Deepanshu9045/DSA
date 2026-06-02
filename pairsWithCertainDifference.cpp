#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sumDiffPairs(vector<int>& arr, int k) {
    int n = arr.size();

    if (n < 2) return 0;

    sort(arr.begin(), arr.end());

    vector<int> dp(n, 0);

    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1];

        if (arr[i] - arr[i - 1] < k) {
            int pairSum = arr[i] + arr[i - 1];

            if (i >= 2)
                pairSum += dp[i - 2];

            dp[i] = max(dp[i], pairSum);
        }
    }

    return dp[n - 1];
}

int main() {
    int n, k;

    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> k;

    cout << sumDiffPairs(arr, k) << endl;

    return 0;
}