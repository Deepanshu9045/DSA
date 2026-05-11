#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
  public:
    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    bool palindromePair(vector<string>& arr) {
        unordered_map<string, int> mp;

        for (int i = 0; i < arr.size(); i++) {
            string rev = arr[i];
            reverse(rev.begin(), rev.end());
            mp[rev] = i;
        }

        for (int i = 0; i < arr.size(); i++) {
            string word = arr[i];
            int len = word.size();

            for (int cut = 0; cut <= len; cut++) {
                string left = word.substr(0, cut);
                string right = word.substr(cut);

                if (isPalindrome(word, 0, cut - 1)) {
                    if (mp.find(right) != mp.end() && mp[right] != i) {
                        return true;
                    }
                }

                if (cut != len && isPalindrome(word, cut, len - 1)) {
                    if (mp.find(left) != mp.end() && mp[left] != i) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

int main() {
    int n;
    cin >> n;

    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;

    if (obj.palindromePair(arr))
        cout << "true";
    else
        cout << "false";

    return 0;
}