#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        if (arr.empty()) return 0;

        int count = 1;
        int maxH = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > maxH) {
                maxH = arr[i];
                count++;
            }
        }

        return count;
    }
};

int main() {
    vector<int> arr = {6, 2, 8, 4, 11, 13};

    Solution obj;
    cout << obj.visibleBuildings(arr);

    return 0;
}