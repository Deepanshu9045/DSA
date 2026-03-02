#include <iostream>
#include <vector>
using namespace std;
void pushZerosToEnd(vector<int>& arr) {
    int n = arr.size();
    int j = 0;  
    for(int i = 0; i < n; i++) {
        if(arr[i] != 0) {
            arr[j] = arr[i];
            j++;
        }
    }
    while(j < n) {
        arr[j] = 0;
        j++;
    }
}
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: \n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    pushZerosToEnd(arr);
    cout << "Array after moving zeros to end: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}


