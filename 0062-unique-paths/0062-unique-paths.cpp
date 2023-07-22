class Solution {
public:
    int helper(int i,int j,int m,int n,int&ans,vector<vector<int>>&dp){
        if(i<0||i>=m||j<0||j>=n){
            return 0;
        }
        if(i==m-1&&j==n-1){
            // ans++;
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int l=helper(i+1,j,m,n,ans,dp);
        int r=helper(i,j+1,m,n,ans,dp);
        
        return dp[i][j]=l+r;
    }
    int uniquePaths(int m, int n) {
        int ans=0;
        // vector<vector<int>>vis(m,vector<int>(n,0));
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(0,0,m,n,ans,dp);
        // return ans;
    }
};