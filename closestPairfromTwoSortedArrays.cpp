#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m, x;
    cin >> n;
    vector<int> arr1(n);
    for(int i = 0; i < n; i++) {
        cin >> arr1[i];}
    cin >> m;
    vector<int> arr2(m);
    for(int i = 0; i < m; i++) {
        cin >> arr2[i];
    }
    cin >> x;
    int i = 0;
    int j = m - 1;
    int minDiff = INT_MAX;
    int first = 0, second = 0;
    while(i < n && j >= 0) {
        int sum = arr1[i] + arr2[j];
        int diff = abs(sum - x);
        if(diff < minDiff) {
            minDiff = diff;
            first = arr1[i];
            second = arr2[j];
        }
        if(sum > x) {
            j--;
        } else {
            i++;
        }
    }
    cout << first << " " << second << endl;
    return 0;
}
