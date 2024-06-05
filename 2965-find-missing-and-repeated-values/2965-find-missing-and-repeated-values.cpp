class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        
        //  1 3
        //  2 2
        
        int n = grid.size();    // rows count
        
        vector<int> arr(n*n + 1 ,0);
        
        // 0 1 2 3 4
        // 0 1 2 1 0;
        
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<n ; j++){
                arr[grid[i][j]]++;
            }
        }
        
        vector<int> ans(2,0);
        
        for(int i = 1 ; i<arr.size() ; i++){
            if(arr[i] == 0) ans[1]= i;
            if(arr[i] == 2) ans[0]= i;
        }
        
        return ans;      
        
    }
};