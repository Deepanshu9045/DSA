#include <iostream>
using namespace std;

class Solution {
  public:
    int findPosition(int n) {
        if (n == 0) return -1;

        // If more than one set bit exists
        if ((n & (n - 1)) != 0) return -1;

        int position = 1;

        while (n > 1) {
            n = n >> 1;
            position++;
        }

        return position;
    }
};

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    Solution obj;
    cout << obj.findPosition(n) << endl;

    return 0;
}