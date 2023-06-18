//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int timer=1;
  void dfs(int node,int parent,vector<int>&low,vector<int>&tin,vector<int>&vis,vector<int>adj[])
  {
      vis[node]=0;
      low[node]=tin[node]=timer;
      timer++;
      int child=0;
      for(auto it:adj[node])
      {
          if(it==parent){continue;}
          else if(vis[it]==-1)
          {
              dfs(it,node,low,tin,vis,adj);
              low[node]=min(low[node],low[it]);
              if(low[it]>=tin[node] && parent!=-1)
              {
                  vis[node]=1;
              }
              child++;
          }
          else
          {
              low[node]=min(low[node],tin[it]);
          }
      }
      if(child>1 && parent==-1)
      {
          vis[node]=1;
      }
  }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
       vector<int>vis(V,-1);
       vector<int>res;
       vector<int>low(V,0),tin(V,0);
       for(int i=0;i<V;i++)
       {
           if(vis[i]==-1)
           {
               dfs(i,-1,low,tin,vis,adj);
           }
       }
       for(int i=0;i<V;i++)
       {
           if(vis[i]==1)
           {
               res.push_back(i);
           }
       }
       if(res.empty())
       {
           return {-1};
       }
       return res;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends