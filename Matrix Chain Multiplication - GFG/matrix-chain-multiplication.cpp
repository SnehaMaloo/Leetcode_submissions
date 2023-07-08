//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int start,int end,int N,int arr[],vector<vector<int>>&dp)
    {
        if(end-start==1)
        {
            return 0;
        }
        else if(dp[start][end]!=-1)
        {
            return dp[start][end];
        }
        else
        {
            int ans=INT_MAX;
            for(int i=start+1;i<end;i++)
            {
                ans=min(ans,arr[start]*arr[i]*arr[end]+solve(start,i,N,arr,dp)+solve(i,end,N,arr,dp));
            }
            return dp[start][end]=ans;
        }
    }
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>>dp(N+1,vector<int>(N+1,-1));
        return solve(0,N-1,N,arr,dp);
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