#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maxOnes(vector<int>& arr) {
    int ones = 0;
    for (int x : arr) {
        if (x == 1) ones++;
    }
    int maxGain = 0, currGain = 0;

    for (int x : arr) {
        int val = (x == 0) ? 1 : -1;
        currGain = max(val, currGain + val);
        maxGain = max(maxGain, currGain);
    }
    return ones + maxGain;
}
int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << maxOnes(arr) << endl;
    return 0;
}