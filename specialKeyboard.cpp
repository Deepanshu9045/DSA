#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int optimalKeys(int n) {
        if (n <= 6) return n;

        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + 1;

            for (int j = 1; j <= i - 3; j++) {
                int pasteCount = i - j - 2;
                dp[i] = max(dp[i], dp[j] * (pasteCount + 1));
            }
        }

        return dp[n];
    }
};

int main() {
    int n;
    cin >> n;

    Solution obj;
    cout << obj.optimalKeys(n);

    return 0;
}