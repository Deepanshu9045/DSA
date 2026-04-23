#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool canSplit(vector<int>& arr) {
        long long total = 0;
        for (int x : arr) total += x;
        if (total % 2 != 0) return false;
        long long target = total / 2;
        long long prefix = 0;
        for (int i = 0; i < arr.size() - 1; i++) {
            prefix += arr[i];
            if (prefix == target) return true;
        }
        return false;
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
    bool ans = obj.canSplit(arr);
    if (ans)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}
