//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
       vector<vector<int>>dp(N+1,vector<int>(N+1,0));
       for(int i=N-1;i>=0;i--)
       {
           for(int j=i+2;j<N;j++)
           {
              int ans=INT_MAX;
              for(int k=i+1;k<j;k++)
              {
                  ans=min(ans,arr[i]*arr[k]*arr[j]+dp[i][k]+dp[k][j]);
              }
              dp[i][j]=ans;
           }
       }
       return dp[0][N-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends