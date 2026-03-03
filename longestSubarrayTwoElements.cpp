#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int totalElements(vector<int> &arr) {
        unordered_map<int, int> freq;
        int left = 0, maxLen = 0;

        for (int right = 0; right < arr.size(); right++) {
            freq[arr[right]]++;

            while (freq.size() > 2) {
                freq[arr[left]]--;
                if (freq[arr[left]] == 0) {
                    freq.erase(arr[left]);
                }
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: " << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    int result = obj.totalElements(arr);

    cout << "Length of longest subarray with at most 2 distinct integers: " 
         << result << endl;

    return 0;
}