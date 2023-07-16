class Solution {
public:
    void helper(int idx,int sum,vector<int>candidates, int target,vector<int>&tmp,vector<vector<int>>&ans){
        if(sum>target || idx>=candidates.size()){
            return;
        }
        if(sum==target){
            ans.push_back(tmp);
            return;
        }
        
        tmp.push_back(candidates[idx]);
        helper(idx,sum,candidates,target-candidates[idx],tmp,ans);
        tmp.pop_back();
        
        helper(idx+1,sum,candidates,target,tmp,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>tmp;
        helper(0,0,candidates,target,tmp,ans);
        return ans;
    }
};