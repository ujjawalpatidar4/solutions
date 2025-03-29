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
// int height(TreeNode* root){
//     if(root==NULL) return 0;
//     int left=height(root->left);
//     int right=height(root->right);
//     return 1+left+right;
// }

void solve(TreeNode* root,int key,int &cnt,int &ans){
    if(root==NULL) return;
    
    solve(root->left,key,cnt,ans);
    cnt++;

    if(cnt==key){
        ans=root->val;
        return;
    }

    solve(root->right,key,cnt,ans);
}

    int kthSmallest(TreeNode* root, int k) { 
        int ans=0;
        int cnt=0;
        solve(root,k,cnt,ans);
        return ans;
    }
};