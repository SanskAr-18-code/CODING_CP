/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void preorder(TreeNode* root,vector<int> &pre){
        if(root==nullptr) return;
        pre.push_back(root->val);
        preorder(root->left,pre);
        preorder(root->right,pre);
    }
    string serialize(TreeNode* root) {
        string res;
        vector<int> pre;
        preorder(root,pre);
        for(auto it: pre){
            string s=to_string(it);
            res+=s;
            res+=' ';
        }
        return res;
    }
    TreeNode* build(vector<int> &a,int &i,int bound){
        if(a.size()==i || a[i]>bound){
            return nullptr;
        }
        //crete the node 
        TreeNode* root=new TreeNode(a[i++]);
        //add the node 
        //going left changes the bound to root.val 
        root->left=build(a,i,root->val);
        //going right doesnt change bound value 
        //remains same as of previous node 
        root->right=build(a,i,bound);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> nums;
        stringstream ss(data);
        int x;
        while (ss>>x){
            nums.push_back(x);
        }
        TreeNode* root=nullptr;
        int i=0;
        root=build(nums,i,100000);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;