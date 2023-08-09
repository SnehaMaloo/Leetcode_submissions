//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool solve(int i,int j,int x,int k,vector<vector<char>>&grid, string &word)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(x==word.length())
        {
            return true;
        }
        if((i<0) || (i>=n) ||(j<0) ||(j>=m) || (grid[i][j]=='&'))
        {
            return false;
        }
        int dx[8]={-1,-1,-1,0,0,1,1,1};
        int dy[8]={-1,0,1,-1,1,-1,0,1};
        bool ans=false;
        char c=grid[i][j];
        grid[i][j]='&';
            int ni=i+dx[k];
            int nj=j+dy[k];
            if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj]==word[x])
            {
                ans|=solve(ni,nj,x+1,k,grid,word);
            }
        grid[i][j]=c;
        return ans;
    }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    vector<vector<int>>res;
	    int n=grid.size();
	    int m=grid[0].size();
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(word[0]==grid[i][j])
	            {
	                if(solve(i,j,1,0,grid,word)||solve(i,j,1,1,grid,word)||solve(i,j,1,2,grid,word)||solve(i,j,1,3,grid,word)||solve(i,j,1,4,grid,word)||solve(i,j,1,5,grid,word)||solve(i,j,1,6,grid,word)||solve(i,j,1,7,grid,word))
	                {
	                    res.push_back({i,j});
	                }
	            }
	        }
	    }
	    return res;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends