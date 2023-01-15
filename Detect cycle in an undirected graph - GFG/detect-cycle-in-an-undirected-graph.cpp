//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.4
    bool ischeck(vector<int>adj[],int i,vector<int>&vis,int parent)
    {
        vis[i]=0;
        for(auto it:adj[i])
        {
            if(vis[it]==-1)
            {
                if(ischeck(adj,it,vis,i))
                {
                    return true;
                }
            }
            else if(it!=parent)
            {
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int>vis(V,-1);
        for(int i=0;i<V;i++)
        {
            if(vis[i]==-1)
            {
                if(ischeck(adj,i,vis,-1))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends