class Solution {
public:
    void rotate(vector<vector<int>>& nums) {
       
        ios::sync_with_stdio(false);  
        cin.tie(nullptr);            
        cout.tie(nullptr);

        // int n = nums.size();

        // vector<vector<int>> mpp( n , vector<int> (n));

        // for(int i = 0; i<n ; i++){
        //     for(int j = 0; j<n ; j++){
        //         mpp[j][(n-1)-i] = nums[i][j];
        //     }
        // }
        
        // for(int i = 0; i<n ; i++){
        //     for(int j = 0; j<n ; j++){
        //         nums[i][j] = mpp[i][j];
        //     }
        // }

        int n = nums.size();

        for(int i=0;i<n-1; i++){
            for(int j=i+1; j<n ;j++){
                swap(nums[i][j], nums[j][i]);
            }
        }

        for(int i=0;i<n;i++){
            reverse(nums[i].begin(), nums[i].end());
        }
        
        
    }
};