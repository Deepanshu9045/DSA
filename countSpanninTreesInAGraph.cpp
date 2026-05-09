#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
  public:
    int countSpanTree(int n, vector<vector<int>>& edges) {
        if (n == 1) return 1;

        vector<vector<long double>> lap(n, vector<long double>(n, 0));

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            lap[u][u]++;
            lap[v][v]++;
            lap[u][v]--;
            lap[v][u]--;
        }

        int size = n - 1;

        vector<vector<long double>> mat(size, vector<long double>(size));

        // Create minor matrix by removing last row and last column
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                mat[i][j] = lap[i][j];
            }
        }

        long double det = 1.0;

        for (int i = 0; i < size; i++) {
            int pivot = i;

            for (int j = i; j < size; j++) {
                if (fabsl(mat[j][i]) > fabsl(mat[pivot][i])) {
                    pivot = j;
                }
            }

            if (fabsl(mat[pivot][i]) < 1e-9) {
                return 0;
            }

            if (pivot != i) {
                swap(mat[pivot], mat[i]);
                det = -det;
            }

            det *= mat[i][i];

            for (int j = i + 1; j < size; j++) {
                long double factor = mat[j][i] / mat[i][i];

                for (int k = i; k < size; k++) {
                    mat[j][k] -= factor * mat[i][k];
                }
            }
        }

        return (int)llround(fabsl(det));
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    Solution obj;
    cout << obj.countSpanTree(n, edges);

    return 0;
}