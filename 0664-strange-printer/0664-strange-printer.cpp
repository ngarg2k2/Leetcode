class Solution {
public:
    int helper(int i, int j, string& s,int n,vector<vector<int>>&dp){       
        if (dp[i][j]!=-1) return dp[i][j];
        if (i==j) return dp[i][j]=1;
        int ans;
        if (s[i]==s[j]||s[j-1]==s[j]) ans=helper(i, j-1, s,n,dp);
        else if (s[i]==s[i+1]) ans=helper(i+1, j, s,n,dp);
        else{
            ans=helper(i,j-1, s,n,dp)+1;
            for(int k=i+1; k<j; k++){
                if(s[k]==s[j])
                    ans=min(ans, helper(i, k-1, s,n,dp)+helper(k, j-1, s,n,dp));
            }
        }
        return dp[i][j]=ans;
    }
    int strangePrinter(string s) {
        int n=s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return helper(0, n-1, s,n,dp);
    }
};