class Solution {
public:
    void helper(vector<int>& nums,vector<int>& vis,vector<int>& tmp,vector<vector<int>>& ans){
        if(tmp.size()==nums.size()){
            ans.push_back(tmp);
        }
        for(int i=0;i<nums.size();i++){
            if(vis[i]==0){
                tmp.push_back(nums[i]);
                vis[i]=1;
                helper(nums,vis,tmp,ans);
                vis[i]=0;
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>tmp;
        int n=nums.size();
        vector<int>vis(n,0);
        helper(nums,vis,tmp,ans);
        return ans;
    }
};