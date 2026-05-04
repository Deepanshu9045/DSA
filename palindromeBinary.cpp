#include <iostream>
#include <string>
using namespace std;
class Solution {
  public:
    bool isBinaryPalindrome(int n) {
        string binary = "";
        // Convert decimal to binary
        while (n > 0) {
            binary += (n % 2) + '0';
            n /= 2;
        }
        // Check palindrome
        int i = 0, j = binary.size() - 1;
        while (i < j) {
            if (binary[i] != binary[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
int main() {
    int n;
    cin >> n;
    Solution obj;
    if (obj.isBinaryPalindrome(n)) {
        cout << "true";
    } else {
        cout << "false";
    }
    return 0;
}