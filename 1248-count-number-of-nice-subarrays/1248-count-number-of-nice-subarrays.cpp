class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int prefixSum=0;
        int totalSubArrays=0;
        int n=nums.size();
        map<int,int>::iterator itr;
        map<int,int> m;
        m[0]=1;
     for(int i=0;i<n;i++){
        if(nums[i]%2!=0){
            nums[i]=1;
        }else{
            nums[i]=0;
        }
        prefixSum+=nums[i];
     
       
        if(m.find(prefixSum-k)!=m.end()){
        itr=   m.find(prefixSum-k);
            totalSubArrays+=itr->second;
        }
         m[prefixSum]++;
     }
     return totalSubArrays;
    }
};