class Solution {
public:

    
    static bool comp(pair<int, int> a,pair<int, int> b)
    {
        if(a.second<b.second)
        {
            return true;
        }
        else if(a.second>b.second)
        {
            return false;
        }
        else 
        {
            return (a.first>b.first);
        }
    }
    vector<int> frequencySort(vector<int>& nums) {
        //Sort the nums
        sort(nums.begin(),nums.end());

        //add int_max at end of nums for iterator go to last element
        nums.push_back(INT_MAX);

        //create vector of pair
        vector<pair<int,int>> v;

        //count for frequency check 
        int count=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
            {
                //if consicative elements are same inc count by 1
                count++;
            }
            else if(nums[i]!=nums[i-1])
            {
                //else and nums and frequency to vector & set count 1
                v.push_back({nums[i-1],count});
                count=1;
            }
        }

        //use above comp function to sort vector
        sort(v.begin(),v.end(),comp);

        //print output to vector result;
        vector<int> res;
        for(auto i:v)
        {
            for(int k=0;k<i.second;k++)
                res.push_back(i.first);
        }
        return res;
    }
};
