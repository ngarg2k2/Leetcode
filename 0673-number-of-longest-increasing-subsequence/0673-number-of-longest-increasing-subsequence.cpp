class Solution {
public:
    int helper(vector<int>&nums,vector<int>&dp,vector<int>&count){
        int maxLen = 1;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }
                    else if (dp[j] + 1 == dp[i]) 
                        count[i] += count[j];
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0){
            return 0;
        } 
        vector<int> dp(n, 1); 
        vector<int> count(n, 1); 
        int maxLen=helper(nums,dp,count);
        int ans=0;
        for (int i = 0; i < n; i++){
            if (dp[i] == maxLen){
                ans += count[i];
            } 
        }
        return ans;
    }
};