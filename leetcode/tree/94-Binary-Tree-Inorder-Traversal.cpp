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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return {};
        stack<TreeNode*> st;
        st.push(root);
        unordered_map<TreeNode*,bool> vis;
        vis[root]=true;
        while(!st.empty()){
            auto it=st.top();
            if(it->left && !vis[it->left]){
                st.push(it->left);
                vis[it->left]=true;
            }
            else{
                st.pop();
                res.push_back(it->val);

                if(it->right) st.push(it->right);
            }
        }
        return res;
    }
};