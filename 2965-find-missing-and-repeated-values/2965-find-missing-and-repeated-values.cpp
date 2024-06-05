class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        
        int n = grid.size(); 
        
        vector<int> frequency(n * n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                frequency[grid[i][j]]++;
            }
        }
        
        vector<int> result(2, -1);
        
        for (int i = 1; i < frequency.size(); i++) {
            if (frequency[i] == 0) {
                result[1] = i; // Missing value
            } else if (frequency[i] == 2) {
                result[0] = i; // Repeated value
            }
            
            if (result[0] != -1 && result[1] != -1) {
                break;
            }
        }
        
        return result;
    }
};
