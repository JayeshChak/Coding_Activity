class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size();
        if(edges[0][0]==edges[n-1][0]||edges[0][0]==edges[n-1][1]) return edges[0][0];
        return edges[0][1];
    }
};