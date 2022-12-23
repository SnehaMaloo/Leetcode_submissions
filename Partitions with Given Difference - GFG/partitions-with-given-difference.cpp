//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int M=1e9+7;
    // int solve(int i,int sum,vector<int>&arr,vector<vector<int>>&dp)
    // {
    //     if(i==arr.size())
    //     {
    //         if(sum==0)
    //         {
    //             return 1;
    //         }
    //         return 0;
    //     }
    //     if(dp[i][sum]!=-1)
    //     {
    //         return dp[i][sum]%M;
    //     }
    //     int pick=0;
    //     int not_pick=solve(i+1,sum,arr,dp)%M;
    //     if(arr[i]<=sum)
    //     {
    //         pick=solve(i+1,sum-arr[i],arr,dp)%M;
    //     }
    //     return dp[i][sum]=(pick+not_pick)%M;
    // }
    int countPartitions(int n, int d, vector<int>& arr) {
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
        }
        if((sum+d)%2==1)
        {
            return 0;
        }
        int m=(sum+d+2)/2;
        int s=(sum+d)/2;
        vector<vector<int>>dp(n+1,vector<int>(m,0));
        dp[n][0]=1;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=s;j++)
            {
                int pick=0;
                int not_pick=dp[i+1][j]%M;
                if(arr[i]<=j)
                {
                    pick=dp[i+1][j-arr[i]]%M;
                }
                dp[i][j]=(pick+not_pick)%M;
            }
        }
        return dp[0][s];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends