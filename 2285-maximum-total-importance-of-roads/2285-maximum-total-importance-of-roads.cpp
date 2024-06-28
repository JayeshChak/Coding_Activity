class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<int> adj(n);

        for (int i = 0; i < roads.size(); i++) {
            adj[roads[i][0]]++;
            adj[roads[i][1]]++;
        }

        sort(adj.begin(), adj.end());
        long long count = 0;

        for (int i = 0; i < adj.size(); i++) {
            count += ((long long)(i + 1) * (adj[i]));
        }
        return count;
    }
};