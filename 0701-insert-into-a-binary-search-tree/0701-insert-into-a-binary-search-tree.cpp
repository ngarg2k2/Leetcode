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
    TreeNode* insertIntoBST(TreeNode* head, int val) {
        TreeNode*t=new TreeNode(val);
        if(head==NULL){
            return t;
        }
        TreeNode*root=head;
        while(root!=NULL){
            if(root->val>val){
                if(root->left){
                    root=root->left;    
                }else{
                    root->left=t;
                    break;
                }
                
            }else{
                if(root->right){
                    root=root->right;    
                }else{
                    root->right=t;
                    break;
                }
            }
        }
        return head;
    }
};