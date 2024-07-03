#include <vector>
#include <algorithm>

class Solution {
public:
    
    int minDifference(std::vector<int>& nums) {
        int numElements = nums.size(); // Store the number of elements in nums

        if (numElements < 5) {
            return 0;
        }

        // Sort the array in non-decreasing order
        std::sort(nums.begin(), nums.end());

        // Initialize the answer to a large number
        long long answer = 1LL << 60;
      
        for (int leftRemoved = 0; leftRemoved <= 3; ++leftRemoved) {
            int rightRemoved = 3 - leftRemoved;
            answer = std::min(answer, static_cast<long long>(nums[numElements - 1 - rightRemoved] - nums[leftRemoved]));
        }

        return static_cast<int>(answer);
    }
};