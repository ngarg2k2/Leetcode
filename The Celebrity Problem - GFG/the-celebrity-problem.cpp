//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        vector<pair<int,int>>pp(n,pair<int,int>({0,0}));
        for(int j=0;j<n;j++){
            int cnt=0;
            for(int i=0;i<n;i++){
                if(M[i][j]==1){
                    cnt++;
                }
            }
            if(cnt==n-1){
                pp[j].first=1;
            }
        }
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(M[i][j]==1){
                    cnt++;
                }
            }
            if(cnt==0){
                pp[i].second=1;
            }
        }
        int ans=-1;
        for(int i=0;i<n;i++){
            if(pp[i].first==1&&pp[i].second==1){
                ans=i;
                break;
            }
            // cout<<pp[i].first<<" "<<pp[i].second<<endl;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends