#include <iostream>
#include <vector>
using namespace std;

bool isToeplitz(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (mat[i][j] != mat[i - 1][j - 1]) {
                return false;
            }
        }
    }
    return true;
}
int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    if (isToeplitz(mat))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}