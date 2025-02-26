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
    TreeNode* trav(TreeNode* root, TreeNode* p,TreeNode* q){
        if(root==NULL) return NULL;
        if(root==p) return p;
        if(root==q) return q;

        TreeNode* a=trav(root->left,p,q);
        TreeNode* b=trav(root->right,p,q);

        if(!a && !b){
            return NULL;
        }
        else if(!a) return b;
        else if(!b) return a;
        else return root;

        
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       
        TreeNode* ans = trav(root,p,q);
       
        return ans;

    }
};