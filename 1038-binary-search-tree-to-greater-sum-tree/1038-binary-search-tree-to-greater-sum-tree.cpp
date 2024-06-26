class Solution {
public:

    void solve(TreeNode* root, int& nodeSum){
        if(!root){
            return;
        }
        solve(root->right, nodeSum);
        nodeSum += root->val;
        root->val = nodeSum;
        solve(root->left, nodeSum);
    }

    TreeNode* bstToGst(TreeNode* root) {
        int nodeSum = 0;
        solve(root, nodeSum);
        return root;
    }
};