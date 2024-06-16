class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        int64_t upper = 0, res = 0, i = 0, m = nums.size();

        while(upper < n){
            if(i < m && nums[i] <= upper+1)
            {
                upper+=nums[i];
                ++i;
            }
            else{
                upper+=upper+1;
                ++res;
            }
        } return res;
    }
};