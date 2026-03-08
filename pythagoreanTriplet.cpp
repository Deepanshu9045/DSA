#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool pythagoreanTriplet(vector<int>& arr) {
    int n = arr.size();

    for(int i = 0; i < n; i++) {
        arr[i] = arr[i] * arr[i];
    }

    sort(arr.begin(), arr.end());

    for(int i = n - 1; i >= 2; i--) {
        int left = 0;
        int right = i - 1;

        while(left < right) {
            int sum = arr[left] + arr[right];

            if(sum == arr[i]) {
                return true;
            }
            else if(sum < arr[i]) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    return false;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: \n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if(pythagoreanTriplet(arr)) {
        cout << "Output: true";
    } else {
        cout << "Output: false";
    }

    return 0;
}