#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minSteps(vector<int>& arr, int start, int end) {
        
        // Distance array
        vector<int> dist(1000, -1);

        queue<int> q;

        q.push(start);
        dist[start] = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            // Try all multiplications
            for (int num : arr) {

                int next = (curr * num) % 1000;

                // If not visited
                if (dist[next] == -1) {

                    dist[next] = dist[curr] + 1;

                    // If target reached
                    if (next == end)
                        return dist[next];

                    q.push(next);
                }
            }
        }

        return -1;
    }
};

int main() {

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int start, end;
    cin >> start >> end;

    Solution obj;

    cout << obj.minSteps(arr, start, end);

    return 0;
}