class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n=customers.size();
        double sum=0,chef=customers[0][0];
        for(int i=0;i<n;i++)
        {
            double arrival=customers[i][0];
            double time=customers[i][1];
            if(arrival<=chef)
            chef+=time;
            else
            chef=arrival+time;
            sum+=(chef-arrival);
        }
        return (sum*1.0)/(n*1.0);
    }
};