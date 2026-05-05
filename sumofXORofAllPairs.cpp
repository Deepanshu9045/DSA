#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    long long sumXOR(vector<int> &arr) {
        long long ans = 0;
        int n = arr.size();

        for (int bit = 0; bit < 32; bit++) {
            long long countOnes = 0;
            long long countZeros = 0;

            for (int i = 0; i < n; i++) {
                if (arr[i] & (1LL << bit))
                    countOnes++;
                else
                    countZeros++;
            }

            ans += countOnes * countZeros * (1LL << bit);
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
    cout << obj.sumXOR(arr) << endl;

    return 0;
}