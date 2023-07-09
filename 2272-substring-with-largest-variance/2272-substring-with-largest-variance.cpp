class Solution {
public:
    int largestVariance(string s) {
        int ans=0;
        vector<int>freq(26,0);
        for(auto i:s){
            freq[i-'a']++;
        }
        for(char ch1='a';ch1<='z';ch1++){
            for(char ch2='a';ch2<='z';ch2++){
                if(ch1==ch2||freq[ch1-'a']==0||freq[ch2-'a']==0){
                    continue;
                }
                for(int tmp=1;tmp<=2;tmp++){
                    int cnt1,cnt2;
                    cnt1=cnt2=0;
                    for(auto it:s){
                        if(it==ch1){
                            cnt1++;
                        }else if(it==ch2){
                            cnt2++;
                        }
                        if(cnt2>cnt1){
                            cnt1=cnt2=0;
                        }
                        if(cnt1>0&&cnt2>0){
                            ans=max(ans,cnt1-cnt2);
                        }
                    }
                    reverse(s.begin(),s.end());
                }
            }
        }
        return ans;
    }
};