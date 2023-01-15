//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool dfs(int i,vector<int>&vis,vector<int>adj[],set<int>&res)
    {
        vis[i]=2;
        if(adj[i].size()==0)
        {
            res.insert(i);
            vis[i]--;
            return true;
        }
        else
        {
            bool ok1=false,ok2=true;
            for(auto it:adj[i])
            {
                if(vis[it]==0||vis[it]==1)
                {
                    ok2=ok2&&(dfs(it,vis,adj,res));
                }
                else
                {
                    ok2=false;
                }
            }
            if(ok2)
            {
                res.insert(i);
            }
            vis[i]--;
            return ok2;
        }
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int>vis(V,0);
        vector<int>curr;
        set<int>res;
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
                dfs(i,vis,adj,res);
            }
        }
        for(auto it:res)
        {
            curr.push_back(it);
        }
        return curr;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends