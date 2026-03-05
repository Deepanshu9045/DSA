#include <bits/stdc++.h>
using namespace std;

int longestKSubstr(string s, int k) {
    unordered_map<char, int> freq;
    int left = 0;
    int maxLen = -1;

    for (int right = 0; right < s.length(); right++) {
        freq[s[right]]++;

        while (freq.size() > k) {
            freq[s[left]]--;
            if (freq[s[left]] == 0)
                freq.erase(s[left]);
            left++;
        }

        if (freq.size() == k) {
            maxLen = max(maxLen, right - left + 1);
        }
    }

    return maxLen;
}

int main() {
    string s;
    int k;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter value of k: ";
    cin >> k;

    int result = longestKSubstr(s, k);

    cout << "Longest substring length with exactly " << k 
         << " distinct characters: " << result << endl;

    return 0;
}

