//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int>g[V];
        int i,j;
        for(i=0;i<V;i++)
        {
            for(j=0;j<V;j++)
            {
                if((i!=j)&&adj[i][j]==1)
                {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        vector<int>visit(V,-1);
        int cnt=0;
        for(i=0;i<V;i++)
        {
            if(visit[i]==-1)
            {
                cnt++;
                queue<int>q;
                q.push(i);
                while(!q.empty())
                {
                    int curr=q.front();
                    q.pop();
                    visit[curr]=0;
                    for(auto it:g[curr])
                    {
                        if(visit[it]==-1)
                        {
                            visit[it]=0;
                            q.push(it);
                        }
                    }
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends