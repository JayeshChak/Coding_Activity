class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size();
        int n = colSum.size();
        vector<vector<int>> v(m,vector<int>(n,0));
        for(int i = 0 ; i < m ; i++){
            for(int j=0 ; j < n ; j++){
                v[i][j] = min(rowSum[i],colSum[j]);
                rowSum[i] -= v[i][j];
                colSum[j] -= v[i][j];
            }
        }
        return v;
    }
};