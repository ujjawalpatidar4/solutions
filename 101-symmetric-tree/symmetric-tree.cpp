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
    bool trav(TreeNode* p,TreeNode* q){
        if(p==NULL && q==NULL) return true;
        if(p==NULL) return false;
        if(q==NULL) return false;
        if(p->val!=q->val) return false;

        bool a= trav(p->left,q->right);
        bool b= trav(p->right,q->left);

        if(!a || !b) return false;
        return true;
        

    }

    bool isSymmetric(TreeNode* root) {
        if(root== NULL) return false;
        bool ans =trav(root->left,root->right);
        return ans;
    }
};