class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=INT_MIN;
        for(int i=0;i<nums.size()/2;i++){
            ans=max(ans,nums[i]+nums[nums.size()-1-i]);
        }
        return ans;
    }
};