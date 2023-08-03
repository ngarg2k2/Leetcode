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
    bool helper(TreeNode* rootleft,TreeNode* rootright){
        if(rootleft==NULL || rootright==NULL){
            return rootleft==rootright;
        }
        
        if(rootleft->val!=rootright->val){
            return false;
        }
       
       return helper(rootleft->left,rootright->right)&&helper(rootleft->right,rootright->left);
    }
    bool isSymmetric(TreeNode* root) {
	    if(root==NULL){
	        return true;
	    }
	    return helper(root->left,root->right);
    }
};