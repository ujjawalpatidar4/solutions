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
 class BSTIterator{
    stack<TreeNode*>st;
    bool reverse=true;  // true <-> before  &  false <-> next
    public:
     BSTIterator (TreeNode* root, bool isReverse){
        reverse=isReverse;
        pushAll(root);
     }
     bool hasNext(TreeNode* node){
        return !st.empty();
     }
     void pushAll(TreeNode* root){
        for(;root!=NULL;){
            st.push(root);
            if(reverse==true){
                root=root->right;
            }else{
                root=root->left;
            }
        }
     }
     int next(){
        TreeNode* temp=st.top();
        st.pop();
        if(reverse==true){
            pushAll(temp->left);
        }else{
            pushAll(temp->right);
        }
        return temp->val;
     }
 };
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL){
            return false;
        }
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        int i=l.next();
        int j=r.next(); // r.before() - instead used r.next()to resuce LOC
        while(i<j){
            if((i+j)==k){
                return true;
            }else if((i+j)<k){
                i=l.next();
            }else{
                j=r.next();
            }
        }
        return false;
    }
};