#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    void dfs(vector<vector<int>>& grid, int i, int j, int n, int m) {
        
        // Boundary check or water check
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0)
            return;

        // Mark visited
        grid[i][j] = 0;

        // Move in 4 directions
        dfs(grid, i + 1, j, n, m);
        dfs(grid, i - 1, j, n, m);
        dfs(grid, i, j + 1, n, m);
        dfs(grid, i, j - 1, n, m);
    }

    int cntOnes(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        // Remove boundary connected 1s

        // First and last column
        for(int i = 0; i < n; i++) {

            if(grid[i][0] == 1)
                dfs(grid, i, 0, n, m);

            if(grid[i][m - 1] == 1)
                dfs(grid, i, m - 1, n, m);
        }

        // First and last row
        for(int j = 0; j < m; j++) {

            if(grid[0][j] == 1)
                dfs(grid, 0, j, n, m);

            if(grid[n - 1][j] == 1)
                dfs(grid, n - 1, j, n, m);
        }

        // Count remaining 1s
        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 1)
                    count++;
            }
        }

        return count;
    }
};

int main() {

    int n, m;

    // Input rows and columns
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    // Input matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj;

    cout << obj.cntOnes(grid) << endl;

    return 0;
}