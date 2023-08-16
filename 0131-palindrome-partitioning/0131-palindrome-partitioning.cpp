class Solution {
public:
    bool palindrome(string s, int start, int end) {
        while (start <= end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;    
        }
        return true;
    }
    void helper(int idx,string s,vector<string>&tmp,vector<vector<string>>&ans){
        if(idx==s.size()){
            ans.push_back(tmp);
            return;
        }
        for(int i=idx;i<s.size();i++){
            if(palindrome(s,idx,i)==true){
                tmp.push_back(s.substr(idx, i-idx+1));
                helper(i+1, s, tmp, ans);
                tmp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>tmp;
        helper(0,s,tmp,ans);
        return ans;
    }
};