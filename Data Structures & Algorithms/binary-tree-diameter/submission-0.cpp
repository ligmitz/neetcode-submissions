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
    int dfs(TreeNode* root, int& maxdiam) {
        if (root == nullptr) return 0;
        int leftHeight = dfs(root->left, maxdiam);
        int rightHeight = dfs(root->right, maxdiam);
        maxdiam = max(maxdiam, leftHeight + rightHeight);
        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxdiam = 0;
        dfs(root, maxdiam);
        return maxdiam;
    }
};
