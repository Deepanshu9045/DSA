#include <iostream>
#include <vector>
#include <climits>
using namespace std;
string minWindow(string s, string p) {
    vector<int> freq(256, 0);
    for(char c : p){
        freq[c]++;
    }
    int left = 0;
    int count = p.length();
    int minLen = INT_MAX;
    int start = 0;
    for(int right = 0; right < s.length(); right++){
        if(freq[s[right]] > 0){
            count--;
        }
        freq[s[right]]--;
        while(count == 0){
            if(right - left + 1 < minLen){
                minLen = right - left + 1;
                start = left;
            }

            freq[s[left]]++;

            if(freq[s[left]] > 0){
                count++;
            }

            left++;
        }
    }
    if(minLen == INT_MAX) return "";
    return s.substr(start, minLen);
}

int main(){

    string s, p;

    cout << "Enter string s: ";
    cin >> s;

    cout << "Enter string p: ";
    cin >> p;

    string result = minWindow(s, p);

    if(result == "")
        cout << "No valid substring found" << endl;
    else
        cout << "Smallest substring: " << result << endl;

    return 0;
}