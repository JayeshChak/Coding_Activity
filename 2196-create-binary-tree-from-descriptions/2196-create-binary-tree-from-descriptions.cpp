/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> tree;
        unordered_set<int> child;
        
        for (const auto& d : descriptions) {
            if (tree.find(d[0]) == tree.end()) {
                tree[d[0]] = new TreeNode(d[0]);
            }
            if (tree.find(d[1]) == tree.end()) {
                tree[d[1]] = new TreeNode(d[1]);
            }
            child.insert(d[1]);
            if (d[2] == 1) {
                tree[d[0]]->left = tree[d[1]];
            } else {
                tree[d[0]]->right = tree[d[1]];
            }
        }
        
        for (const auto& node : tree) {
            if (child.find(node.first) == child.end()) {
                return node.second;
            }
        }
        
        return nullptr;
    }
};