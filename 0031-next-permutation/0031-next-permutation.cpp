class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        // 2 1 5 4 3 0 0
        // 0 1 2 3 4 5 6 
        int index = -1;
        
        for(int i = n-2 ; i >=0 ; i--){
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }
        
        if(index == -1){
            reverse(nums.begin(),nums.end());
            return;
        }
        
        int toReplace = nums[index];
        
        for(int i = n-1 ; i > index ; i--){
            
            if(nums[i] > nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
        }
        
        reverse(nums.begin() + (index+1), nums.end());
        
    }
};