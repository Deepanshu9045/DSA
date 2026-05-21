#include <iostream>
using namespace std;

class Solution {
public:
    bool isBitSet(int n) {
        if (n == 0)
            return false;

        return (n & (n + 1)) == 0;
    }
};

int main() {
    Solution obj;
    int n;

    cout << "Enter number: ";
    cin >> n;

    if (obj.isBitSet(n))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}