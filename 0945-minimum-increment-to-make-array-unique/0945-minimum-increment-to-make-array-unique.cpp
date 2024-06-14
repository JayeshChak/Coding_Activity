class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        if (nums.empty()) return 0;

        sort(nums.begin(), nums.end());
        int moves = 0;

        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] <= nums[i - 1]) {
                int increment = nums[i - 1] - nums[i] + 1;
                nums[i] += increment;
                moves += increment;
            }
        }
        
        return moves;
    }
};
