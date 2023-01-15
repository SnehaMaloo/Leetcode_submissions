//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool ischeck(int i,vector<int>&visit,vector<int>adj[])
    {
        visit[i]=2;
        for(auto it:adj[i])
        {
            if(visit[it]==-1)
            {
                if(ischeck(it,visit,adj))
                {
                    return true;
                }
            }
            else if(visit[it]==2)
            {
                return true;
            }
        }
        visit[i]--;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>visit(V,-1);
        for(int i=0;i<V;i++)
        {
            if(visit[i]==-1)
            {
                if(ischeck(i,visit,adj))
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends