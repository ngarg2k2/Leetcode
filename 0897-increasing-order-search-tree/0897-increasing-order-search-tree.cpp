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
    void inorder(TreeNode* root,vector<int>&in){
        if(root==NULL){
            return;
        }
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int>in;
        inorder(root,in);
        TreeNode* ans=new TreeNode(-1);
        TreeNode* head=ans;
        for(auto i:in){
            TreeNode* t=new TreeNode(i);
            ans->right=t;
            ans=t;
        }
        if(in.size()==0){
            return NULL;
        }
        return head->right;
    }
};