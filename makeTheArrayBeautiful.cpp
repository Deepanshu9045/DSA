#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> makeBeautiful(vector<int> arr) {
        vector<int> stk; // acts as our stack

        for (int num : arr) {

            // If signs are different, remove previous element
            if (!stk.empty() && (stk.back() < 0) != (num < 0)) {
                stk.pop_back();
            }
            else {
                stk.push_back(num);
            }
        }

        return stk;
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

    vector<int> ans = obj.makeBeautiful(arr);

    // Print result
    if (ans.empty()) {
        cout << "Empty Array";
    }
    else {
        for (int x : ans) {
            cout << x << " ";
        }
    }

    return 0;
}