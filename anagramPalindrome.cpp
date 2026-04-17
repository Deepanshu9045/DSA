#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool canFormPalindrome(string &s) {
    vector<int> freq(256, 0);
    for (char ch : s) {
        freq[ch]++;
    }

    int oddCount = 0;
    for (int count : freq) {
        if (count % 2 != 0) {
            oddCount++;
        }
    }
    return oddCount <= 1;
}
int main() {
    string s;
    cin >> s;
    if (canFormPalindrome(s)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}
