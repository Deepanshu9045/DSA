#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isProduct(vector<int>& arr, long long target) {
        unordered_set<long long> seen;

        for (long long num : arr) {

            // Special case when target is 0
            if (target == 0) {
                if (num == 0 && !seen.empty())
                    return true;

                for (long long x : seen) {
                    if (x == 0)
                        return true;
                }
            }
            else {
                // Check if target is divisible by num
                if (num != 0 && target % num == 0) {
                    long long need = target / num;

                    if (seen.count(need))
                        return true;
                }
            }

            seen.insert(num);
        }

        return false;
    }
};

int main() {
    Solution obj;

    vector<int> arr = {10, 20, 9, 40};
    long long target = 400;

    if (obj.isProduct(arr, target))
        cout << "true";
    else
        cout << "false";

    return 0;
}