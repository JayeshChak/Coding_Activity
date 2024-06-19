class Solution {
//Apply binary search on the result i.e. the result will lie between the min and max values in the array. Iterate through the array with each mid value and check if it is a valid answer.
//You will iterate through the array log(n) times resulting in a final time complexity of nlog(n).
//Binary search is applicable here because the final answer lies in a range and that range is in a sorted order.
private:
    bool validBloom(vector<int>& bloomDay, int day, int bq, int fl, int l) {
        
        int count = 0;
        int totalBq = 0;
        for(int i=0; i<l; i++)
        {
            if(bloomDay[i] <= day)
                count++;
            else
                count = 0;
            
            if(count == fl)
            {
                totalBq++;
                count = 0;
            }
        }
        
        return totalBq >= bq;
    }
    
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int len = bloomDay.size();
        
        int low = INT_MAX, high = INT_MIN;
        
        for(int i=0; i<len; i++)
        {
            low = min(low, bloomDay[i]);
            high = max(high, bloomDay[i]);
        }
        
        int result = -1;
        
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            
            if(validBloom(bloomDay, mid, m, k, len))
            {
                result = mid;
                high = mid-1;
            }
            
            else
            {
                low = mid+1;
            }
        }
        
        return result;
        
    }
};