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
    void insertatright(TreeNode* &root,int val){
        TreeNode* newNode = new TreeNode(val);
        root->right=newNode;
    }

    void insertatleft(TreeNode* &root,int val){
        TreeNode* newNode = new TreeNode(val);
        root->left=newNode;
    }

    void solve(TreeNode* root, int val){
        
        if(root->val<val){
            if(root->right==NULL) insertatright(root,val);
            else{
                
                solve(root->right,val);
            } 
        }else{
            if(root->left==NULL) insertatleft(root,val);
            else{
                
                solve(root->left,val);
            } 
        }
    }


    TreeNode* insertIntoBST(TreeNode* root, int val) {
       if(root==NULL){
            TreeNode* newNode = new TreeNode(val);
            return newNode;
       }
        solve(root,val);

        return root;
    }
};