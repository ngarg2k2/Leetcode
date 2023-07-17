class Solution {
public:
    void helper(int idx,vector<int>& nums,vector<int>& tmp,set<vector<int>>& s){
        if(idx==nums.size()){
            // sort(tmp.begin(),tmp.end());
            s.insert(tmp);
            return;
        }
        tmp.push_back(nums[idx]);
        helper(idx+1,nums,tmp,s);
        tmp.pop_back();
        helper(idx+1,nums,tmp,s);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>s;
        vector<int>tmp;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        helper(0,nums,tmp,s);
        for(auto i:s){
            ans.push_back(i);
        }
        return ans;
    }
};