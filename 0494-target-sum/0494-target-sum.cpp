class Solution {
public:
    int code(int a , int sum , int total , int d , vector<vector<int>> &dp , vector<int> arr)
    {
        if(a < 0)  return (total-2*sum == d);
        if(dp[a][sum] != -1) return dp[a][sum];
        int x = code(a-1 , sum+arr[a] , total , d, dp , arr);
        int y = code(a-1 , sum , total , d , dp ,arr);
        return dp[a][sum] = (x+y)%1000000007;
    }
    int findTargetSumWays(vector<int>& arr, int target) {
        int total = 0;
        int n=arr.size();
        for(int i = 0 ; i < n ; i++)  total += arr[i];
        // s1+s2=total
        // s1-s2=target
        // 2s2=total-target -----> s2=(total-target)/2
        vector<vector<int>> dp(n , vector<int> (total+1 , -1));
        return code(n-1 , 0 , total , target , dp , arr);
    }
};