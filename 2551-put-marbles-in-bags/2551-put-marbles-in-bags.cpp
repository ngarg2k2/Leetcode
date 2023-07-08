class Solution {
public:
    long long putMarbles(vector<int>& wt, int k) {
        vector<long long>ma;   
        vector<long long>mi;
        for(int i=0;i<wt.size()-1;i++){
            ma.push_back(wt[i]+wt[i+1]);
        }   
        mi=ma;
        sort(ma.begin(),ma.end());
        sort(mi.begin(),mi.end());
        reverse(ma.begin(),ma.end());
        long long ans=0;
        int i=0;
        // for(int i=0;i<ma.size();i++){
        //     cout<<ma[i]<<" "<<mi[i]<<endl;
        // }
        k--;
        while(k>0){
            ans=ans+(ma[i]-mi[i]);
            i++;
            k--;
        }
        return ans;
    }
};