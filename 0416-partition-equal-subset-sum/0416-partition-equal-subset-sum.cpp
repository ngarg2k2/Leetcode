class Solution {
public:
    int helper(int index,int target,vector<int>&nums,vector<vector<int>>&dp){
    int n=nums.size();
    if(index>=n){
        return false;
    }
    if(target==0){
        return true;
    }
    if(target<0){
        return false;
    }
    if(dp[index][target]!=-1){
        return dp[index][target];
    }
    bool include=helper(index+1,target-nums[index],nums,dp);
    bool exclude=helper(index+1,target,nums,dp);
    dp[index][target]=( include||exclude);
    return dp[index][target];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto i:nums){
            sum+=i;
        }
        if(sum%2){
            return false;
        }
        cout<<sum<<endl;
        // return true;
        int n=nums.size();
        int target=sum/2;
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return helper(0,target,nums,dp);
    }
};