class Solution {
public:
    int maxProfit(vector<int>& prices) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int mini = prices[0];
        int profit = 0;
        
        for(int i = 0 ; i< prices.size();i++){
            int val = prices[i]-mini;
            profit = max(profit,val);
            mini = min(mini,prices[i]);
        }
        return profit;
    }
};