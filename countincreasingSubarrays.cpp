#include <iostream>
#include <vector>
using namespace std;

int countIncreasing(vector<int> &arr) {
    int n = arr.size();
    int ans = 0;
    int len = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            len++;
        } else {
            ans += (len * (len - 1)) / 2;
            len = 1;
        }
    }
    ans += (len * (len - 1)) / 2;
    return ans;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
     for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
     }
    cout << "Number of increasing subarrays: " << countIncreasing(arr) << endl;
    return 0;

}