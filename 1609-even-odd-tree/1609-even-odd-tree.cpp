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
    bool isEvenOddTree(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int>tmp;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                tmp.push_back(node->val);
            }
            ans.push_back(tmp);
        }
        // int flag=0;
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].size();j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++){
            if(i%2==0){
                if(ans[i][0]%2==0){
                    return false;
                }
                if(ans[i][ans[i].size()-1]%2==0){
                    return false;
                }
                for(int j=0;j<ans[i].size()-1;j++){
                    if(ans[i][j]%2==0){
                        return false;
                    }
                    if(ans[i][j]>=ans[i][j+1]){
                        return false;
                    }
                }
            }else{
                if(ans[i][0]%2!=0){
                    return false;
                }
                if(ans[i][ans[i].size()-1]%2!=0){
                    return false;
                }
                for(int j=0;j<ans[i].size()-1;j++){
                    if(ans[i][j]%2!=0){
                        return false;
                    }
                    if(ans[i][j]<=ans[i][j+1]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};