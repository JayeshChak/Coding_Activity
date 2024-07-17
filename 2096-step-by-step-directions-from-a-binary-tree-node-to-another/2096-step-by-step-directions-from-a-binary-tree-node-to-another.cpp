/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x, left(left), right(right)) {}
 * };
 */
class Solution {
public:
    bool helper(TreeNode* root, int value, string& path) {
        if (root == NULL) return false;
        if (root->val == value) return true;

        path.push_back('L');
        if (helper(root->left, value, path)) return true;
        path.pop_back();

        path.push_back('R');
        if (helper(root->right, value, path)) return true;
        path.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string startPath, destPath;

        helper(root, startValue, startPath);
        helper(root, destValue, destPath);

        int i = 0;
        while (i < startPath.size() && i < destPath.size() && startPath[i] == destPath[i]) {
            i++;
        }

        string result = string(startPath.size() - i, 'U') + destPath.substr(i);
        return result;
    }
};