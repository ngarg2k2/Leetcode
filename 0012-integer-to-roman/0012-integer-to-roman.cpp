class Solution {
public:
    string intToRoman(int num) {
        vector<int>val{1,4,5,9,10,40,50,90,100,400,500,900,1000};
        vector<string>ch{"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        reverse(val.begin(),val.end());
        reverse(ch.begin(),ch.end());
        string ans; 
        for(int i=0;num!=0;i++){
            while(num>=val[i]){
                num-=val[i];
                ans+=ch[i];
            }
        }
        return ans;
    }
};