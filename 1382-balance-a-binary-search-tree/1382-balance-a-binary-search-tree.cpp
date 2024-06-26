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
    vector<int> nums; // Vector to store inorder traversal values
    
    // Function to perform inorder traversal and collect node values
    void dfs(TreeNode* root) {
        if (root->left) {
            dfs(root->left);
        }
        nums.push_back(root->val);
        if (root->right) {
            dfs(root->right);
        }
    }
    
    // Function to construct a balanced BST from the sorted array
    TreeNode* formBalanceBST(int start, int end) {
        if (start > end) return nullptr;

        int mid = (start + end) / 2; // Find the middle element
        TreeNode* root = new TreeNode(nums[mid]); // Create the root node
        root->left = formBalanceBST(start, mid - 1); // Construct the left subtree
        root->right = formBalanceBST(mid + 1, end); // Construct the right subtree
        return root;
    }
public:
    // Main function to balance the BST
    TreeNode* balanceBST(TreeNode* root) {
        dfs(root); // Perform inorder traversal to collect node values
        int n = nums.size(); // Get the number of nodes
        return formBalanceBST(0, n - 1); // Construct and return the balanced BST
    }
};