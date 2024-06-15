class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
      int n=profits.size();
      vector<pair<int,int>>ans(n);
      for(int i=0;i<n;i++){
        ans[i]={capital[i],profits[i]};
      }
      sort(begin(ans),end(ans));
      
      int i=0;
      priority_queue<int>pq;
      while(k--){
        while(i<n && ans[i].first<=w){
            pq.push(ans[i].second);
            i++;
        }
        if(pq.empty())
        break;
        w+=pq.top();
        pq.pop();

      }
      return w;
        
        
    }
};