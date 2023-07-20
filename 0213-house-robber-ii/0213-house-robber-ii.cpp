// the ques is every such same as of case 1 of this problem but in this the another csae is given we cant take 0th and last element 
// so basically the ans could be max of from (0 to n-1) or (1 to n) which simply mean they both dont come together

class Solution {
public:
    int helper(vector<int>&nums){
        int n=nums.size();
        int prev1=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int pick=nums[i];
            if(i>1){
                pick+=prev2;
            }
            int dontPick=0+prev1;
            int cur=max(pick,dontPick);
            prev2=prev1;
            prev1=cur;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        vector<int>tmp1;
        vector<int>tmp2;
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        for(int i=0;i<n;i++){
            if(i!=0){
                tmp1.push_back(nums[i]);
            }
            if(i!=n-1){
                tmp2.push_back(nums[i]);
            }
        }
        return max(helper(tmp1),helper(tmp2));
    }
};