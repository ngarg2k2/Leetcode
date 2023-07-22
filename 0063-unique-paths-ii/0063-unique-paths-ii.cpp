class Solution {
public:
    int helper(int i,int j,int m,int n,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(i<0||i>=m||j<0||j>=n||grid[i][j]==1){
            return 0;
        }
        if(i==m-1&&j==n-1){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int l=helper(i+1,j,m,n,grid,dp);
        int r=helper(i,j+1,m,n,grid,dp);
        
        return dp[i][j]=l+r;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(0,0,m,n,grid,dp);
    }
};