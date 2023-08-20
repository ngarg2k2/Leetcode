class Solution {
public:
    int minimumSum(int n, int k) {
        int tmp=n+k+1;
        vector<int>v(tmp,0);

        int cnt=0;
        int i=1;
        int ans=0;
        while(cnt!=n){
            if(v[i]!=-1){
                if(i<=k){
                    ans+=i;
                    cnt++;
                    v[i]=1;
                    v[k-i]=-1;
                }else{
                    cnt++;
                    ans+=i;
                    v[i]=1;
                }   
            }
            i++;
        }
        // for(auto i:v){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        return ans;
    }
};