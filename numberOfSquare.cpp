#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int countSquare(vector<vector<int>>& mat, int x) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> prefix(n + 1, vector<int>(m + 1, 0));
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                prefix[i][j] = mat[i-1][j-1]
                             + prefix[i-1][j]
                             + prefix[i][j-1]
                             - prefix[i-1][j-1];
            }
        }        
        int count = 0;
        for(int size = 1; size <= min(n, m); size++) {
            for(int i = 0; i + size <= n; i++) {
                for(int j = 0; j + size <= m; j++) {
                    
                    int r1 = i;
                    int c1 = j;
                    int r2 = i + size - 1;
                    int c2 = j + size - 1;
                    
                    int sum = prefix[r2+1][c2+1]
                            - prefix[r1][c2+1]
                            - prefix[r2+1][c1]
                            + prefix[r1][c1];
                    
                    if(sum == x) {
                        count++;
                    }
                }
            }
        }        
        return count;
    }
};

int main() {
    int n, m;
    cout << "Enter number of rows: ";
    cin >> n;
    cout << "Enter number of columns: ";
    cin >> m;

    vector<vector<int>> mat(n, vector<int>(m));

    cout << "Enter matrix elements:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    int x;
    cout << "Enter target sum x: ";
    cin >> x;

    Solution obj;
    int result = obj.countSquare(mat, x);

    cout << "Number of square submatrices with sum " << x << " is: " << result << endl;

    return 0;
}