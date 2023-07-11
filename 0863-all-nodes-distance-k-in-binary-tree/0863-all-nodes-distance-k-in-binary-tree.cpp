/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void DFS(int src, int prev, unordered_map<int, vector<int> > &mp, int target,vector<int> &ans)
    {
        if(target==0)
        {
        ans.push_back(src);
        return;
        }
        for(auto x:mp[src])
        {
            if(x!=prev)
            DFS(x,src,mp,target-1,ans);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int,vector<int>> mp;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            auto x=q.front();
            q.pop();
            if(x->left)
            {
                q.push(x->left);
                mp[x->val].push_back(x->left->val);
                mp[x->left->val].push_back(x->val);
            }
            if(x->right)
            {
                q.push(x->right);
                mp[x->val].push_back(x->right->val);
                mp[x->right->val].push_back(x->val);
            }
        }
        vector<int> ans;
        DFS(target->val,-1,mp,k,ans);
        return ans;
    }
};