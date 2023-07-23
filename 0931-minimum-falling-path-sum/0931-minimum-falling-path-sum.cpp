class Solution {
public:
    int helper(int i,int j,int n,int m,vector<vector<int>>&dp,vector<vector<int>>&matrix){
        if(i<0||i>=n||j<0||j>=m){
            return 1e9;
            // which should be greater than any value in matrix
        }
        if(i==n-1){
            return matrix[i][j];
        }
        if(dp[i][j]!=1e9){
            return dp[i][j];
        }
        int d=helper(i+1,j,n,m,dp,matrix);
        int dl=helper(i+1,j-1,n,m,dp,matrix);
        int dr=helper(i+1,j+1,n,m,dp,matrix);
        
        return dp[i][j]=min(d,min(dl,dr))+matrix[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=INT_MAX;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int j=0;j<m;j++){
            vector<vector<int>>dp(n,vector<int>(m,1e9));
            ans=min(helper(0,j,n,m,dp,matrix),ans);
        }
        return ans;
    }
};