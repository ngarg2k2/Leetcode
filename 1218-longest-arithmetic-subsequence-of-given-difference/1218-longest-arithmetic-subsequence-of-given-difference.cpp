class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int>um;
        int ans=1;
        for(int i=0;i<arr.size();i++)
        {
            um[arr[i]]=um[arr[i]-difference]+1;
            ans=max(ans,um[arr[i]]);
        }
        return ans;
    }
};