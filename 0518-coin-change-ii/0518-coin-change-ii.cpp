class Solution {
public:
    int helper(int idx,vector<int>coins,int amount,vector<vector<int>>&dp){
        if(amount==0){
            return 1;
        }
        if(amount<0){
            return 0;
        }
        if(idx>=coins.size()){
            return 0;
        }
        if(dp[idx][amount]!=-1){
            return dp[idx][amount];
        }
        int take=helper(idx,coins,amount-coins[idx],dp);
        int notTake=helper(idx+1,coins,amount,dp);
        
        return dp[idx][amount]=take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return helper(0,coins,amount,dp);
    }
};