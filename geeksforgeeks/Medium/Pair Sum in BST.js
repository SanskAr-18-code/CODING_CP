/* Binary Tree Node Structure
class Node {
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool ispair(Node* root,unordered_set<int> &st,int &target){
        if(!root) return false;
        if(st.count(target-root->data)){
            return true;
        }
        st.insert(root->data);
        bool left=ispair(root->left,st,target);
        bool right=ispair(root->right,st,target);
        
        return left || right;
    }
    bool findTarget(Node *root, int target) {
        unordered_set<int> st;
        return ispair(root,st,target);
    }
};