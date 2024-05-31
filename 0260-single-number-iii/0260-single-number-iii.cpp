class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
//         vector<int> pos(INT_MAX,0);
//         vector<int> neg(INT_MAX,0);
        
//         vector<int> ans;
        
//         for(int i = 0 ; i< nums.size()-1 ; i++){
            
//             if(nums[i]>=0){
//                 pos[nums[i]]++;
//             }else{
//                 neg[abs(nums[i])]++;
//             }
            
//         }
        
//         for(int i = 1 ; i< neg.size() ; i++){
//             if(neg[i] == 1){
//                 ans.push_back(-1*i);
//             }
//         }
        
//         for(int i = 0 ; i< pos.size() ; i++){
//             if(pos[i] == 1){
//                 ans.push_back(i);
//             }
//         }
        
        
//         return ans;
        
        unordered_map<int, int> countMap;
        vector<int> ans;

        for (int num : nums) {
            countMap[num]++;
        }

        for (const auto& entry : countMap) {
            if (entry.second == 1) {
                ans.push_back(entry.first);
            }
        }

        return ans;
    }
};