class Solution {
public:
    void helper(int i,vector<int>candidates,vector<int>subSet,vector<vector<int>>&tmp,int curSum,int target){
        if(target==curSum){
            tmp.push_back(subSet);
            return;
        }
        if(target<curSum||i>=candidates.size()){
            return;
        }
        subSet.push_back(candidates[i]);
        helper(i+1,candidates,subSet,tmp,curSum+candidates[i],target);
        subSet.pop_back();
        while(i+1<candidates.size()&&candidates[i]==candidates[i+1]){
            i++;
        }
        helper(i+1,candidates,subSet,tmp,curSum,target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>subSet;
        int curSum=0;
        sort(candidates.begin(),candidates.end());
        helper(0,candidates,subSet,ans,curSum,target);
        return ans;
    }
};