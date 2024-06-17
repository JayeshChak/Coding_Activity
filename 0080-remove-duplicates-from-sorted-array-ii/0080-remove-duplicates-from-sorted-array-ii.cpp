class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
       int prev = INT_MIN;
       int count = 0;
        
       for(int i = 0 ; i<nums.size() ; i++){
                      
           if(nums[i] == prev){
               count++;
               if(count>=2){
                   prev = nums[i];
                   nums[i] = INT_MAX;
               }
           }else{
               prev = nums[i];
               count = 0;
           }
           
       }
        
        sort(nums.begin(),nums.end());
        
        for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i] == INT_MAX){
                return i;
            }
        }
        
        return nums.size();
          
    }
};