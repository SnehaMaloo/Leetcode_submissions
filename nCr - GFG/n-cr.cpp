//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

int M=1e9+7;
class Solution{
public:
    int nCr(int n, int r){
        if(n<r)
        {
            return 0;
        }
        vector<vector<long long int>>dp(n+1,vector<long long int>(r+1,0));
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }
        for(int i=0;i<=r;i++)
        {
            dp[0][i]=1;
        }
        for(int i=0;i<=r;i++)
        {
            dp[i][i]=1;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=r;j++)
            {
                if(i==j)
                {
                    dp[i][j]=1;
                }
                else
                {
                    dp[i][j]=(dp[i-1][j]%M+dp[i-1][j-1]%M)%M;
                }
                
            }
        }
        return dp[n][r]%M;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends