#include <iostream>
#include <string>
#include <climits>
using namespace std;
class Solution {
public:
    int myAtoi(string &s) {
        int i = 0, n = s.size();
        // Ignore leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }
        // Check sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }
        // Read digits
        long long num = 0;
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';
            num = num * 10 + digit;

            // Handle overflow
            if (sign == 1 && num > INT_MAX) return INT_MAX;
            if (sign == -1 && -num < INT_MIN) return INT_MIN;

            i++;
        }
        return (int)(sign * num);
    }
};

int main() {
    string s;
    getline(cin, s);

    Solution obj;
    cout << obj.myAtoi(s) << endl;

    return 0;
}