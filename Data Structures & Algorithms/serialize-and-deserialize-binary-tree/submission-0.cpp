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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        string result;
        q.push(root);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node == nullptr) {
                result += ("N|");
                continue;
            }
            result += (to_string(node->val) + '|');
            q.push(node->left);
            q.push(node->right);
        }
        cout<<result<<endl;
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes;
        stringstream s(data);
        string part;
        while (getline(s, part, '|')) {
            if (!part.empty()) nodes.push_back(part);
        }
        if (nodes.empty() || nodes[0] == "N") return nullptr;
        TreeNode* root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while (!q.empty() && i < nodes.size()) {
            TreeNode* node = q.front();
            q.pop();

            if (i < nodes.size() && nodes[i] != "N") {
                node->left = new TreeNode(stoi(nodes[i]));
                q.push(node->left);
            }
            i++;
            if (i < nodes.size() && nodes[i] != "N") {
                node->right = new TreeNode(stoi(nodes[i]));
                q.push(node->right);
            }
            i++;
        }
        return root;
    }
};
