class Solution {
public:
    int helper(int i,int j1,int j2,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp,int n,int m){
        if(i<0||i>=n||j1<0||j1>=m||j2<0||j2>=m){
            return -1;
        }
        if(i==n-1){
            if(j1==j2){
                return grid[i][j1];
            }else{
                return grid[i][j1]+grid[i][j2];
            }
        }
        if(dp[i][j1][j2]!=-1){
            return dp[i][j1][j2];
        }
        int ma=0;
        for(int dj1=-1;dj1<=1;dj1++){
            for(int dj2=-1;dj2<=1;dj2++){
                int val=0;
                if(j1==j2){
                    val=val+grid[i][j1];
                }else{
                    val=val+grid[i][j1]+grid[i][j2];
                }
                val=val+helper(i+1,j1+dj1,j2+dj2,grid,dp,n,m);
                ma=max(ma,val);
            }
        }
        return dp[i][j1][j2]=ma;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return helper(0,0,m-1,grid,dp,n,m);
    }
};