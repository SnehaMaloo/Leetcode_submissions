//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int dp[1005][1005];
    long long int solve(int i,int N,int coins[],int sum)
    {
        if(i==N)
        {
            if(sum==0)
            {
                return 1;
            }
            return 0;
        }
        else if(dp[i][sum]!=-1)
        {
            return dp[i][sum];
        }
        else if(coins[i]<=sum)
        {
            dp[i][sum]=solve(i+1,N,coins,sum)+solve(i,N,coins,sum-coins[i]);
        }
        else
        {
            dp[i][sum]=solve(i+1,N,coins,sum);
        }
        return dp[i][sum];
    }
    long long int count(int coins[], int N, int sum) {

        memset(dp,-1,sizeof(dp));
        return solve(0,N,coins,sum);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends