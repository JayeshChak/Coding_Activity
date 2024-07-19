class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> minRow(m, INT_MAX);
        vector<int> maxCol(n, INT_MIN);
        vector<int> result;

        // Find the minimum element in each row
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                minRow[i] = min(minRow[i], matrix[i][j]);
            }
        }

        // Find the maximum element in each column
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                maxCol[j] = max(maxCol[j], matrix[i][j]);
            }
        }

        // Find lucky numbers
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == minRow[i] && matrix[i][j] == maxCol[j]) {
                    result.push_back(matrix[i][j]);
                }
            }
        }

        return result;
    }
};