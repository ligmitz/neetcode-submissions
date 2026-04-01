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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> pq;
        vector<int> result;
        if (!root) return result;
        pq.push(root);
        while (!pq.empty()) {
            int level = pq.size();
            for (int i = 0; i < level; i++) {
                TreeNode* node = pq.front(); pq.pop();
                if (i == (level - 1)) result.push_back(node->val);
                if (node->left) pq.push(node->left);
                if (node->right) pq.push(node->right);
            }
        }
        return result;
    }
};
