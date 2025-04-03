/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void solve(TreeNode* root,TreeNode* p,TreeNode* q,TreeNode* &ans){
        if(root->val==p->val || root->val==q->val){
            ans=root;
            return;
        }
        else if(p->val<root->val && q->val<root->val){
            solve(root->left,p,q,ans);
        }
        else if((p->val<root->val && q->val>root->val) || (p->val>root->val && q->val<root->val)){
            ans=root;
            
        }
        else{
            solve(root->right,p,q,ans);
        }

    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=root;
        solve(root,p,q,ans);
        return ans;
    }
};