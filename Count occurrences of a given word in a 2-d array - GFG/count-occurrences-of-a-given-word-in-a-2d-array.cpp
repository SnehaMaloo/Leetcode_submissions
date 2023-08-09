//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int solve(int i,int j,int x,vector<vector<char> > &mat, string &target)
    {
        int n=mat.size();
        int m=mat[0].size();
        int len=target.size();
        if(x==len)
        {
            return 1;
        }
        if((i>=n) ||(i<0)||(j>=m)||(j<0)||(mat[i][j]=='&'))
        {
            return 0;
        }
        char c=mat[i][j];
        mat[i][j]='&';
        int cnt=0;
        if(i+1<n && mat[i+1][j]==target[x])
        {
            cnt+=solve(i+1,j,x+1,mat,target);
        }
        if(i-1>=0 && mat[i-1][j]==target[x])
        {
            cnt+=solve(i-1,j,x+1,mat,target);
        }
        if(j+1<m && mat[i][j+1]==target[x])
        {
            cnt+=solve(i,j+1,x+1,mat,target);
        }
        if(j-1>=0 && mat[i][j-1]==target[x])
        {
            cnt+=solve(i,j-1,x+1,mat,target);
        }
        mat[i][j]=c;
        return cnt;
    }
    int findOccurrence(vector<vector<char> > &mat, string target){
        int cnt=0;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(target[0]==mat[i][j])
                {
                    
                    cnt+=solve(i,j,1,mat,target);
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
        int R, C;
        cin >> R >> C;
        vector<vector<char> > mat(R);
        for (int i = 0; i < R; i++) {
            mat[i].resize(C);
            for (int j = 0; j < C; j++) cin >> mat[i][j];
        }
        string target;
        cin >> target;
        Solution obj;
        cout<<obj.findOccurrence(mat,target)<<endl;
    }
}

// } Driver Code Ends