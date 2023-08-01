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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL){
            return ans;
        }
        map<int,map<int,multiset<int>>>m;
        // vertical  level  multiNode
        queue<pair<TreeNode*,pair<int,int>>>q;
        // node vertical level
        q.push({root,{0,0}});
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                pair<TreeNode*,pair<int,int>>pp=q.front();
                q.pop();
                TreeNode*t=pp.first;
                int v=pp.second.first;
                int h=pp.second.second;
                m[v][h].insert(t->val);
                if(t->left){
                    q.push({t->left,{v-1,h+1}});
                }
                if(t->right){
                    q.push({t->right,{v+1,h+1}});
                }
            }
        }
        for(auto it:m){
            vector<int>tmp;
            for(auto i:it.second){
                for(auto j:i.second){
                    tmp.push_back(j);
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};