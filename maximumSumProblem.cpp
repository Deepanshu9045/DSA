#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Memoization map to store already computed results
    unordered_map<int, int> memo;

    int maxSum(int n) {
        // Base cases
        if (n == 0) return 0;
        if (n == 1) return 1;

        // Return cached result if already computed
        if (memo.count(n)) 
            return memo[n];

        // Option 1: Take n as-is
        int noSplit = n;

        // Option 2: Split recursively
        int splitSum = maxSum(n / 2) + 
                       maxSum(n / 3) + 
                       maxSum(n / 4);

        // Store and return maximum
        return memo[n] = max(noSplit, splitSum);
    }
};

int main() {
    int n;

    // Input
    cin >> n;

    Solution obj;

    // Output
    cout << obj.maxSum(n) << endl;

    return 0;
}