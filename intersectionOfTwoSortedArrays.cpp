#include <iostream>
#include <vector>
using namespace std;
vector<int> intersection(vector<int>& a, vector<int>& b) {
    vector<int> ans;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (i > 0 && a[i] == a[i - 1]) {
            i++;
            continue;
        }
        if (j > 0 && b[j] == b[j - 1]) {
            j++;
            continue;
        }
        if (a[i] == b[j]) {
            ans.push_back(a[i]);
            i++;
            j++;
        } else if (a[i] < b[j]) {
            i++;
        } else {
            j++;
        }
    }
    return ans;
}
int main() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    vector<int> result = intersection(a, b);

    for (int x : result) {
        cout << x << " ";
    }
    return 0;
}
