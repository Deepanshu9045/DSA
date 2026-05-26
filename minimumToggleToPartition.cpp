#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minToggle(vector<int>& arr) {
        int n = arr.size();

        // Prefix count of 1s
        vector<int> prefixOne(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefixOne[i + 1] = prefixOne[i] + (arr[i] == 1);
        }

        int totalOnes = prefixOne[n];
        int ans = n;

        // Try every partition
        for (int i = 0; i <= n; i++) {

            // Left part should be all 0s
            int leftToggles = prefixOne[i];

            // Right part should be all 1s
            int onesRight = totalOnes - prefixOne[i];
            int rightSize = n - i;
            int rightToggles = rightSize - onesRight;

            ans = min(ans, leftToggles + rightToggles);
        }

        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;

    cout << obj.minToggle(arr) << endl;

    return 0;
}