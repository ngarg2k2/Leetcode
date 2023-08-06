//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void helper(int n,vector<string>&ans,string s){
        if(n==s.length()){
            ans.push_back(s);
        }
        for(int i=n;i<s.length();i++){
            swap(s[i],s[n]);
            helper(n+1,ans,s);
            swap(s[i],s[n]);
        }
    }
    vector<string> permutation(string s)
    {
        //Your code here
        vector<string>ans;
        int n=s.length();
        helper(0,ans,s);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends