#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    long long gcdLL(long long a, long long b) {
        while (b) {
            long long t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    long long lcmLL(long long a, long long b) {
        if (a == 0 || b == 0) return 0;
        return (a / gcdLL(a, b)) * b;
    }

    void build(int idx, int low, int high, vector<int>& arr, vector<long long>& seg) {
        if (low == high) {
            seg[idx] = arr[low];
            return;
        }

        int mid = (low + high) / 2;

        build(2 * idx + 1, low, mid, arr, seg);
        build(2 * idx + 2, mid + 1, high, arr, seg);

        seg[idx] = lcmLL(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    void update(int idx, int low, int high, int pos, int val, vector<long long>& seg) {
        if (low == high) {
            seg[idx] = val;
            return;
        }

        int mid = (low + high) / 2;

        if (pos <= mid) {
            update(2 * idx + 1, low, mid, pos, val, seg);
        } else {
            update(2 * idx + 2, mid + 1, high, pos, val, seg);
        }

        seg[idx] = lcmLL(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    long long query(int idx, int low, int high, int l, int r, vector<long long>& seg) {
        // No overlap
        if (high < l || low > r) {
            return 1;
        }

        // Complete overlap
        if (low >= l && high <= r) {
            return seg[idx];
        }

        // Partial overlap
        int mid = (low + high) / 2;

        long long left = query(2 * idx + 1, low, mid, l, r, seg);
        long long right = query(2 * idx + 2, mid + 1, high, l, r, seg);

        return lcmLL(left, right);
    }

    vector<long long> RangeLCMQuery(vector<int> &arr, vector<vector<int>> &queries) {
        int n = arr.size();

        vector<long long> seg(4 * n);
        build(0, 0, n - 1, arr, seg);

        vector<long long> ans;

        for (auto &q : queries) {
            int type = q[0];

            if (type == 1) {
                int index = q[1];
                int value = q[2];

                arr[index] = value;
                update(0, 0, n - 1, index, value, seg);
            } 
            else {
                int L = q[1];
                int R = q[2];

                ans.push_back(query(0, 0, n - 1, L, R, seg));
            }
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

    vector<vector<int>> queries(q, vector<int>(3));

    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
    }

    Solution obj;
    vector<long long> ans = obj.RangeLCMQuery(arr, queries);

    for (long long x : ans) {
        cout << x << " ";
    }

    return 0;
}