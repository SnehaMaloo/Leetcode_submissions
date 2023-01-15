//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<char>>res(n,vector<char>(m,'$'));
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            if(mat[i][0]=='O')
            {
                q.push({i,0});
            }
            if(mat[i][m-1]=='O')
            {
                q.push({i,m-1});
            }
        }
        for(int i=0;i<m;i++)
        {
            if(mat[0][i]=='O')
            {
                q.push({0,i});
            }
            if(mat[n-1][i]=='O')
            {
                q.push({n-1,i});
            }
        }
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            res[x][y]='O';
            for(int k=0;k<4;k++)
            {
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx>=0&&ny>=0&&nx<n&&ny<m&&(mat[nx][ny]=='O')&&res[nx][ny]=='$')
                {
                    res[nx][ny]='O';
                    q.push({nx,ny});
                }
            }
            q.pop();
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(res[i][j]=='$')
                {
                    res[i][j]='X';
                }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends