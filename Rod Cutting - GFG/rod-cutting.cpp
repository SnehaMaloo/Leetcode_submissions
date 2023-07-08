//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int solve(int n,int price[],vector<int>&dp)
    {
        if(n==0)
        {
            return 0;
        }
        else if(dp[n]!=-1)
        {
            return dp[n];
        }
        else
        {
            int ans=0;
            for(int i=0;i<n;i++)
            {
                ans=max(ans,solve(n-i-1,price,dp)+price[i]);
            }
            return dp[n]=ans;
        }
    }
    int cutRod(int price[], int n) {
        vector<int>dp(n+1,-1);
        return solve(n,price,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends