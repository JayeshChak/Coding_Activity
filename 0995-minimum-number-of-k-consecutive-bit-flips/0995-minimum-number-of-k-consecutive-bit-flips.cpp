class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size(), prefixSum = 0, ans = 0;
        vector<int> flipped(n + 1);
        for(int i = 0 ; i < n ; i++){
            prefixSum += flipped[i];
            int tmp = nums[i];
            if(prefixSum & 1)
                tmp ^= 1;
            if(!tmp){
                if(i + k - 1 < n){
                    flipped[i + k] += -1;
                    prefixSum++;
                    ans++;
                }
                else
                    return -1;
            }
        }
        return ans;
    }
};