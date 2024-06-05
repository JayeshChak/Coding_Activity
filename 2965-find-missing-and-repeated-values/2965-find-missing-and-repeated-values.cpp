class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        
        ios_base :: sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);        
        
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
        }
        
        return result;
    }
};
