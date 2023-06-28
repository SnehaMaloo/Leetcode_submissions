//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[105][105];
    int solve(int start,int end,int N,int arr[])
    {
        if(end-start==1)
        {
            return 0;
        }
        if(dp[end][start]!=-1)
        {
            return dp[end][start];
        }
        else
        {
            int ans=INT_MAX;
            for(int i=start+1;i<end;i++)
            {
                ans=min(ans,arr[start]*arr[end]*arr[i]+solve(start,i,N,arr)+solve(i,end,N,arr));
            }
            return dp[end][start]=ans;
        }
    }
    int matrixMultiplication(int N, int arr[])
    {
        memset(dp,-1,sizeof(dp));
        return solve(0,N-1,N,arr);
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