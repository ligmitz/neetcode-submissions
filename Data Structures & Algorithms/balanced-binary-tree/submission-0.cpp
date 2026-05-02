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
    int findHeight(TreeNode* root, bool& is_balanced) {
        if (!root) return 0;
        int leftHeight = 1 + findHeight(root->left, is_balanced);
        int rightHeight = 1 + findHeight(root->right, is_balanced);
        if (abs(leftHeight - rightHeight) > 1) is_balanced = false;
        return max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {
        bool is_balanced = true;
        findHeight(root, is_balanced);
        return is_balanced;
    }
};
