class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.length();
        for(int i=1;i<=n/2;i++){
            if(n%i==0){
                string substring=s.substr(0,i);
                string repeat;
                for(int j=0;j<n/i;j++){
                    repeat+=substring;
                }
                if(repeat==s){
                    return true;
                }
            }
        }
        return false;
    }
};
