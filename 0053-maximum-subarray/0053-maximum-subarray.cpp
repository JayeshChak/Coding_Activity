class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);


        long long sum = 0;
        long long maxi = INT_MIN;
        
        int ansStart = -1;
        int ansEnd = -1;
        int start = 0;
        
        for(int i = 0 ; i  < nums.size() ;i++){
            if(sum == 0) start = i;
            
            sum = sum + nums[i];
            maxi = max(sum,maxi);
            ansStart = start;
            ansEnd = i;
            
            if(sum < 0 ) sum = 0;
        }

        return maxi;
        
    }
};