#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        int n = arr.size();

        int totalOnes = 0;
        for (int x : arr) {
            if (x == 1) totalOnes++;
        }

        if (totalOnes == 0) return -1;

        int onesInWindow = 0;

        for (int i = 0; i < totalOnes; i++) {
            if (arr[i] == 1) onesInWindow++;
        }

        int maxOnes = onesInWindow;

        for (int i = totalOnes; i < n; i++) {
            if (arr[i] == 1) onesInWindow++;
            if (arr[i - totalOnes] == 1) onesInWindow--;

            maxOnes = max(maxOnes, onesInWindow);
        }

        return totalOnes - maxOnes;
    }
};

int main() {
    vector<int> arr = {1, 0, 1, 0, 1};

    Solution obj;
    cout << obj.minSwaps(arr) << endl;

    return 0;
}