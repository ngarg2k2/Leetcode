class Solution {
public:
    bool dfs(int node , vector<vector<int>>& graph , vector<int> &vis , vector<int> &pathvis , vector<int> &check)
    {
        vis[node]=1;
        pathvis[node]=1;
        for(auto a:graph[node])
        {
            if(vis[a]==0)
            {
                if(dfs(a , graph , vis , pathvis , check)==true)
                {
                    return true;
                }
            }
            else if(vis[a] && pathvis[a])
            {
                return true;
            }
        }
        check[node] = 1;
        pathvis[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> check(n,0);  
        vector<int> vis(n,0);  
        vector<int> pathvis(n,0); 
        vector<int> safenode; 
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                dfs(i,graph,vis,pathvis,check);
            }
        } 
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(check[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};