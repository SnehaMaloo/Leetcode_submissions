//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void dfs(int i,vector<pair<int,int>>adj[],vector<int>&vis,stack<int>&st)
    {
        vis[i]=1;
        for(auto it:adj[i])
        {
            if(vis[it.first]==0)
            {
                dfs(it.first,adj,vis,st);
            }
        }
        st.push(i);
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int,int>>adj[N];
        for(int i=0;i<M;i++)
        {
            int x=edges[i][0];
            int y=edges[i][1];
            int z=edges[i][2];
            adj[x].push_back({y,z});
        }
        stack<int>st;
        vector<int>vis(N,0);
        for(int i=0;i<N;i++)
        {
            if(vis[i]==0)
            {
                dfs(i,adj,vis,st);
            }
        }
        vector<int>res(N,1e9);
        res[0]=0;
        while(!st.empty())
        {
            int curr=st.top();
            int dist=res[curr];
            for(auto it:adj[curr])
            {
                int u=it.first;
                int wt=it.second;
                if(wt+dist<res[u])
                {
                    res[u]=wt+dist;
                }
            }
            st.pop();
        }
        for(int i=0;i<N;i++)
        {
            if(res[i]==1e9)
            {
                res[i]=-1;
            }
        }
        return res;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends