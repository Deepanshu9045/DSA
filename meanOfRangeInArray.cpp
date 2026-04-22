#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries) {
        int n = arr.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + arr[i];
        }
        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            long long sum = prefix[r + 1] - prefix[l];
            int len = r - l + 1;

            ans.push_back(sum / len); // floor of mean
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
    int q;
    cin >> q;
    vector<vector<int>> queries(q, vector<int>(2));
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1];
    }
    Solution obj;
    vector<int> result = obj.findMean(arr, queries);
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}