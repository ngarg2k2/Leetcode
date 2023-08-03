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
    void helper(TreeNode* root,string s,vector<string>&ans){
        if(root==NULL){
            return;
        }
        if(root->left==NULL&&root->right==NULL){
            s=char(root->val+'a')+s;
            ans.push_back(s);
        }
        s=char(root->val+'a')+s;
        helper(root->left,s,ans);
        helper(root->right,s,ans);
    }
    string smallestFromLeaf(TreeNode* root) {
        vector<string>ans;
        string s;
        helper(root,s,ans);
        sort(ans.begin(),ans.end());
        return ans[0];
    }
};