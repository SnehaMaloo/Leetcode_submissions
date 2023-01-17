//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int m, int src){
        vector<int>adj[n];
        for(int i=0;i<m;i++)
        {
            int x=edges[i][0];
            int y=edges[i][1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<int>dist(n,1e9);
        dist[src]=0;
        queue<int>q;
        q.push(src);
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            for(auto it:adj[curr])
            {
                if(dist[curr]+1<dist[it])
                {
                    dist[it]=1+dist[curr];
                    q.push(it);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(dist[i]==1e9)
            {
                dist[i]=-1;
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends