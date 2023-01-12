//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
//   int dp[51][51];
//     int f(int row , int col ,int n, int m ,vector<vector<int>> &M){
//         if(col==m-1)return M[row][col];
//         int dig_up=0;
//         int forward=0;
//         int dig_down=0;
//         if(dp[row][col]!=-1){
//             return dp[row][col];
//         }
//         if((row-1>=0) and (col+1<m)){
//              dig_up=f(row-1,col+1,n,m,M)+M[row][col];
//         }
//         if(col+1<m){
//              forward=f(row,col+1,n,m,M)+M[row][col];
//         }
//         if((row+1<n) and (col+1<m)){
//              dig_down=f(row+1,col+1,n,m,M)+M[row][col];
//         }
//         return dp[row][col]=max(dig_up,max(forward,dig_down));
        
        
//     }
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        int ans=0;
        for(int j=m-1;j>=0;j--)
        {
            for(int i=0;i<n;i++)
            {
                 int dig_up=0;
                int forward=0;
                int dig_down=0;
                if((i-1>=0) and (j+1<=(m))){
                    dig_up=dp[i-1][j+1]+M[i][j];
                }
                if(j+1<=(m)){
                    forward=dp[i][j+1]+M[i][j];
                }
                if((i+1<(n)) and (j+1<=(m))){
                    dig_down=dp[i+1][j+1]+M[i][j];
                }
                dp[i][j]=max(dig_up,max(forward,dig_down));
                if(j==0)
                {
                    ans=max(ans,dp[i][j]);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends