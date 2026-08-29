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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        stack<vector<int>> st;
        queue<TreeNode*> q;
        vector<vector<int>> res;
        if(!root) return {};
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> vec;
            for(int i=1; i<=n; i++){
                auto it=q.front();
                q.pop();
                vec.push_back(it->val);
                if(it->left) q.push(it->left);
                if (it->right) q.push(it->right);
            }
            st.push(vec);
        }
        while(!st.empty()){
            auto it=st.top();
            st.pop();
            res.push_back(it);
        }
        return res;
    }
};