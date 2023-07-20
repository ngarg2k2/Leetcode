class Solution {
public:
    int helper(int idx,vector<int>&nums,vector<int>&dp){
        if(idx==0){
            return dp[0];
        }
        if(idx<0){
            return 0;
        }
        int pick,notPick;
        if(dp[idx]==-1){
            pick=nums[idx]+helper(idx-2,nums,dp);
            notPick=0+helper(idx-1,nums,dp);
        }else{
            return dp[idx];
        }
        return dp[idx]=max(pick,notPick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        dp[0]=nums[0];
        return helper(n-1,nums,dp);
    }
};