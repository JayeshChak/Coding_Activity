class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int zeros=0,ones=0,twos=0;
        
        for(auto i : nums){
            if(i == 0) zeros++;
            if(i == 1) ones++;
            if(i == 2) twos++;            
        }
        
        for(int i = 0 ; i< zeros ; i++){
            nums[i] = 0;
        }
        
        for(int i = zeros ; i< (ones+zeros) ; i++){
            nums[i] = 1;
        }
        
        for(int i = ones+zeros ; i< nums.size() ; i++){
            nums[i] = 2;
        }
        
        return;
    }
};