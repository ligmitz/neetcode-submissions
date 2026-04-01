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
    void dfs(TreeNode* root, vector<int>& preorder, vector<int>& inorder, int curr, int left, int right, bool left_sub, const unordered_map<int, int>& indices) {
        if (left > right) return;
        TreeNode* node = new TreeNode(preorder[curr]);
        int root_index = indices.at(preorder[curr]);
        if (left_sub) {
            root->left = node;
        } else {
            root->right = node;
        }
        dfs(node, preorder, inorder, curr + 1, left, root_index - 1, true, indices);
        dfs(node, preorder, inorder, curr + (root_index - left) + 1, root_index + 1, right, false, indices);
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        if (!size) return nullptr;
        int left = 0, right = size - 1, curr = 0;
        unordered_map<int, int> indices;
        for (int i = 0; i < size; i++) {
            indices[inorder[i]] = i;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        int root_index = indices[preorder[0]];
        dfs(root, preorder, inorder, curr + 1, left, root_index - 1, true, indices);
        dfs(root, preorder, inorder, curr + (root_index - left) + 1, root_index + 1, right, false, indices);
        return root;
    }
};
