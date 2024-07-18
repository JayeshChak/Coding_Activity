class Solution {
public:
     int countPairs(TreeNode* root, int distance) {
        int result = 0;
        dfs(root, distance, result);
        return result;}

        vector<int> dfs(TreeNode* n, int d, int& res) {
        if (!n) return {};
        if (!n->left && !n->right) return {1};
        
        vector<int> l_d = dfs(n->left, d, res);
        vector<int> r_d = dfs(n->right, d, res);
        
        for (int l : l_d) {
            for (int r : r_d) {
                if (l + r <= d) {
                    res++;
                }
            }
        }
        
        vector<int> cur_d;
        for (int l : l_d) {
            if (l + 1 < d) {
                cur_d.push_back(l + 1);
            }
        }
        for (int r : r_d) {
            if (r + 1 < d) {
                cur_d.push_back(r + 1);
            }
        }
        
        return cur_d;
    }

};