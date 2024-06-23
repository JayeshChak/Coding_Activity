class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int>st;
        int i=0,j=0,n=nums.size(),ans=1;

        while(i<n){
            st.insert(nums[i]);
            
            while(st.size()>1 && ((*prev(st.end())-*st.begin()))>limit){
                st.erase(st.find(nums[j]));
                j++;
            }
            ans=max(ans,(int)st.size());
            i++;
        }
        return ans;
    }
};