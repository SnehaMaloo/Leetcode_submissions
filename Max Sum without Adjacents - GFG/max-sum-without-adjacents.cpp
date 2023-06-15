//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int solve(int i,int n,int *arr,vector<int>&dp)
	{
	    if(i<=0)
	    {
	        return 0;
	    }
	    if(dp[i]!=-1)
	    {
	        return dp[i];
	    }
	    int taken=0;
	    int nottaken=0;
	    taken=arr[i-1]+solve(i-2,n,arr,dp);
	    nottaken=solve(i-1,n,arr,dp);
	    return dp[i]=max(taken,nottaken);
	}
	int findMaxSum(int *arr, int n) {
	    vector<int>dp(n+1,-1);
	    return solve(n,n,arr,dp);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends