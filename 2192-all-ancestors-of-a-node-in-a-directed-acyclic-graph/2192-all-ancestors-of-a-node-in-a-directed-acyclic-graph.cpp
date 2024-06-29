class Solution {
public:
    void bfs(int startNode, vector<vector<int>> adj,vector<vector<int> > &ancestors,int n){
        vector<int> visited(n,0);
        queue<int> q;
        q.push(startNode);
        visited[startNode] =1;

        while(!q.empty()){
            int ele = q.front();
            q.pop();

            for(auto i: adj[ele]){
                if(visited[i] == 0){
                    visited[i] =1;
                    q.push(i);
                    ancestors[i].push_back(startNode);
                }
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
       
        vector<vector<int>> ancestors(n);
        vector<vector<int> > adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }

        for(int i=0; i<n;i++){
            bfs(i,adj,ancestors,n);
        }
        return ancestors;
    }
};