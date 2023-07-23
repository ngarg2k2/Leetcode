class Solution {
public:
    int helper(int i,int j,int n,int m,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(i<0||i>=n||j<0||j>=m){
            return 1e9;
        }
        if(i==n-1){
            return grid[i][j];
        }
        if(dp[i][j]!=1e9){
            return dp[i][j];
        }
        int mi=INT_MAX;
        for(int k=0;k<n;k++){
            if(k!=j){
                mi=min(mi,helper(i+1,k,n,m,grid,dp));
            }
        }
        return dp[i][j]=mi+grid[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int ans=INT_MAX;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,1e9));
        for(int j=0;j<n;j++){
            ans=min(ans,helper(0,j,n,m,grid,dp));
        }
        return ans;
    }
};