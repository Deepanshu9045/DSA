#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
  public:
    bool isValid(string str) {
        int balance = 0;

        for (char ch : str) {
            if (ch == '(') {
                balance++;
            } 
            else if (ch == ')') {
                balance--;
                if (balance < 0) return false;
            }
        }

        return balance == 0;
    }

    vector<string> validParenthesis(string &s) {
        vector<string> ans;
        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                string curr = q.front();
                q.pop();

                if (isValid(curr)) {
                    ans.push_back(curr);
                    found = true;
                }

                if (found) continue;

                for (int i = 0; i < curr.size(); i++) {
                    if (curr[i] != '(' && curr[i] != ')') continue;

                    string next = curr.substr(0, i) + curr.substr(i + 1);

                    if (visited.find(next) == visited.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }

            if (found) break;
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    string s;
    cin >> s;

    Solution obj;
    vector<string> result = obj.validParenthesis(s);

    for (string str : result) {
        cout << str << " ";
    }

    return 0;
}