#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int maxProfit(int x, int y, vector<int> &a, vector<int> &b) {
        int n = a.size();

        vector<int> diff;
        int baseProfit = 0;

        // Initially assign all tasks to Machine B
        for (int i = 0; i < n; i++) {
            baseProfit += b[i];
            diff.push_back(a[i] - b[i]);
        }

        // If a task gives more benefit on A, it should come first
        sort(diff.rbegin(), diff.rend());

        int minA = max(0, n - y);   // minimum tasks A must do
        int maxA = min(x, n);       // maximum tasks A can do

        int ans = 0;
        int extra = 0;

        for (int i = 0; i <= maxA; i++) {
            if (i >= minA) {
                ans = max(ans, baseProfit + extra);
            }

            if (i < n) {
                extra += diff[i];
            }
        }

        return ans;
    }
};

int main() {
    int x, y, n;
    cin >> x >> y >> n;

    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    Solution obj;
    cout << obj.maxProfit(x, y, a, b);

    return 0;
}