class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int not_grumpy=0,all_customers=0;
        for(int i=0;i<customers.size();i++)
        {
            if(grumpy[i]==0)
            {
                not_grumpy+=customers[i];
            }
            all_customers+=customers[i];
        }
        if(minutes==customers.size())
            return all_customers;
        int maxi=0,managed=0;
        for(int i=0;i<minutes;i++)
        {
            if(grumpy[i]==1)
                managed+=customers[i];
        }
        maxi=max(maxi,managed+not_grumpy);
        int i=0;
        for(int j=minutes;j<customers.size();j++)
        {
            if(grumpy[i]==1)
            {
                managed-=customers[i];
            }
            if(grumpy[j]==1)
            {
                managed+=customers[j];
            }
            i++;
            maxi=max(maxi,managed+not_grumpy);
        }
        maxi=max(maxi,managed+not_grumpy);
        return maxi;
    }
};