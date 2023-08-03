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
    void helper(TreeNode*root,string s,vector<string>&tmp){
        if(root==NULL){
            return;
        }
        if(root->left==NULL&&root->right==NULL){
            s=s+to_string(root->val);
            cout<<s<<endl;
            tmp.push_back(s);
        }
        s=s+to_string(root->val);
        helper(root->right,s,tmp);
        helper(root->left,s,tmp);
    }
    int sumNumbers(TreeNode* root) {
        int ans=0;
        string s;
        vector<string>tmp;
        helper(root,s,tmp);
        for(auto i:tmp){
            int n=0;
            for(auto j:i){
                n=n*10+(j-'0');
            }
            ans=ans+n;
        }
        return ans;
    }
};