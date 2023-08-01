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
   int solve(TreeNode*root,int &sum)
   {
       if(root==NULL){
           return 0;
       }
       int left=solve(root->left,sum);
       int right=solve(root->right,sum);
        sum= max(left+right,sum);
        return max(left,right)+1;
   }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int ans=0;
        solve(root,ans);
        return ans;
    }
};
