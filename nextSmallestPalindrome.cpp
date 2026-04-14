#include <iostream>
#include <vector>
using namespace std;
vector<int> nextPalindrome(vector<int>& num) {
    int n = num.size();
    vector<int> ans = num;
    for (int i = 0; i < n / 2; i++) {
        ans[n - 1 - i] = ans[i];
    }
    if (ans > num) return ans;
    int carry = 1;
    int mid = (n - 1) / 2;
    while (mid >= 0 && carry) {
        ans[mid] += carry;
        carry = ans[mid] / 10;
        ans[mid] %= 10;
        mid--;
    }
    if (carry) {
        vector<int> res(n + 1, 0);
        res[0] = 1;
        res[n] = 1;
        return res;
    }
    for (int i = 0; i < n / 2; i++) {
        ans[n - 1 - i] = ans[i];
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    vector<int> ans = nextPalindrome(num);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i != ans.size() - 1) cout << " ";
    }
    cout << endl;
    return 0;
}
