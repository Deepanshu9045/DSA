#include <iostream>
#include <vector>
using namespace std;

int noOfWays(int m, int n, int x) {
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            for (int k = 1; k <= m && k <= j; k++) {
                dp[i][j] += dp[i - 1][j - k];
            }
        }
    }
    return dp[n][x];
}
int main() {            
    int m, n, x;                

    cout << "Enter number of faces (m): ";
    cin >> m;

    cout << "Enter number of dice (n): ";
    cin >> n;

    cout << "Enter required sum (x): ";
    cin >> x;

    int result = noOfWays(m, n, x);

    cout << "Number of ways to get sum " << x << " = " << result << endl;

    return 0;
}

