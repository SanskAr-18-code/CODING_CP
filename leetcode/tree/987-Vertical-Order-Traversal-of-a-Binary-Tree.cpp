/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<pair<pair<int, int>, int>> nodes;
    void traversal(TreeNode* root, int x, int y) {
        if (!root)
            return;
        nodes.push_back({{y, x}, root->val});
        traversal(root->left, x + 1, y - 1);
        traversal(root->right, x + 1, y + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        traversal(root, 0, 0);
        sort(nodes.begin(), nodes.end());
        vector<vector<int>> res;
        int prevCol = INT_MIN;
        for (auto& p : nodes) {

            int col = p.first.first;
            int val = p.second;

            if (col != prevCol) {
                res.push_back({});
                prevCol = col;
            }
            res.back().push_back(val);
        }
        return res;
    }
};