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
class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        st.push(root);
        while(root->left){
            root=root->left;
            st.push(root);
        }   
    }
    
    int next() {
        TreeNode* temp=st.top();
        TreeNode* temp2=temp;
        st.pop();
        if(temp->right){
            temp=temp->right;
            st.push(temp);
            while(temp->left){
                temp=temp->left;
                st.push(temp);
            }
        }
        return temp2->val;

    }
    
    bool hasNext() {
        if(st.empty()) return false;
        return true; 
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */