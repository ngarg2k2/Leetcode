class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int>um;
        int val=0;
        for(auto i:nums){
            um[i]++;
            if(um[i]>val){
                val=um[i];
            }
        }
        set<int>tmp;
        for(auto i:nums){
            if(um[i]==val){
                tmp.insert(i);
            }
        }
        int ans=INT_MAX;
        for(auto i:tmp){
            int s,e,flag;
            s=e=-1;
            flag=0;
            for(int j=0;j<nums.size();j++){
                if(nums[j]==i&&flag==0){
                    s=j;
                    flag=1;
                }else if(nums[j]==i){
                    e=j;
                }
            }
            ans=min(ans,e-s+1);
        }
        
        return max(1,ans);
    }
};