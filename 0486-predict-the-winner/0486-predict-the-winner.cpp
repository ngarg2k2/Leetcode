class Solution {
public:
    vector<vector<vector<long>>> dp;
    int dfs(int i , int j ,vector<int>& nums , int turn){
        if(i == nums.size() || j == -1) return 0;
        if(i > j) return 0;
        if(dp[i][j][turn] != -1) return dp[i][j][turn];
        if(turn == 0){
            return dp[i][j][turn] = max(nums[i] + dfs(i + 1 , j , nums , 1), nums[j] + dfs(i , j - 1 , nums , 1));
        }
        else{
            return dp[i][j][turn] = min(-nums[i] + dfs(i + 1 , j , nums , 0),-nums[j] + dfs(i , j - 1 , nums , 0));
        }
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n , vector<vector<long>>(n , vector<long>(2 , -1)));
        int val = dfs(0 , n - 1 , nums , 0);
        return val >= 0;
    }
};