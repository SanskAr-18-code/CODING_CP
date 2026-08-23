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
    unordered_map<int,int> mp;
private: 
    void inorder(TreeNode* root){
        if (root==nullptr) return;

        inorder(root->left);
        mp[root->val]++;
        inorder(root->right);
    }
public:
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        int freq=INT_MIN;
        for(auto it: mp){
            if(it.second>freq){
                freq=it.second;
            }
        }
        vector<int> res;
        for(auto it: mp){
            if(it.second==freq){
                res.push_back(it.first);
            }
        }
        return res;
    }
};