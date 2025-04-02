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
    void searchel(TreeNode* &root,int key){
        if(root==NULL) return;
        // if(root->right) int rightvalue = root->right->val;
        // if(root->left) int leftvalue = root->left->val;
        
        if((root->val==key && root->right) || (root->right && key==root->right->val)){
            TreeNode* temp;
            if(root->val==key){
                temp=root;
            }
            else temp=root->right;
            if(temp->right){
                TreeNode* temp2=temp->right;
                while(temp2->left) temp2=temp2->left;
                temp2->left=temp->left;
                if(root->val==key) root=temp->right;
                else root->right=temp->right;
            }else{
                root->right=temp->left;
            }
        }
        else if((root->val==key && root->left) || (root->left && key==root->left->val)){
            TreeNode* temp;
            if(root->val==key){
                temp=root;
            }
            else temp=root->left;

            if(temp->left){
                TreeNode* temp2=temp->left;
                while(temp2->right){
                    temp2=temp2->right;
                }
                temp2->right=temp->right;
                if(root->val==key) root=root->left;
                else root->left=temp->left;
            }else{  
                root->left=temp->right;
            }
        }
        else if(root->val==key){
            // cout<<"Hello";
            root=NULL;
        }
        else if(key>root->val){
            searchel(root->right,key);
        }
        else{
            searchel(root->left,key);
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        searchel(root,key);
        return root;
    }
};