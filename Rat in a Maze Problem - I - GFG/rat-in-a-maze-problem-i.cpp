//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    private:
    vector<string>ans;
    bool vis[6][6];
    void f(int i, int j, vector<vector<int>> &m, int n,string s){
        if(i<0 || j<0 || i>=n || j>=n || m[i][j]==0 || vis[i][j])return;
        if(i==n-1 && j==n-1){
            ans.push_back(s);
        }
        vis[i][j]=true;
        f(i+1,j,m,n,s+'D');
        f(i,j+1,m,n,s+'R');
        f(i-1,j,m,n,s+'U');
        f(i,j-1,m,n,s+'L');
        vis[i][j]=false;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        string s="";
        memset(vis,0,sizeof(vis));
        f(0,0,m,n,s);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends