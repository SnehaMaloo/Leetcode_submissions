//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int n,vector<int>&height,vector<int>&dp)
    {
        if(n==1)
        {
            return 0;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        int one=INT_MAX;
        int two=INT_MAX;
        if(n>=2)
        {
            one=abs(height[n-2]-height[n-1])+solve(n-1,height,dp);
        }
        if(n>=3)
        {
            two=abs(height[n-3]-height[n-1])+solve(n-2,height,dp);
        }
        //cout<<one<<" "<<two<<endl;
        return dp[n]=min(one,two);
    }
    int minimumEnergy(vector<int>& height, int n) {
        vector<int>dp(n+1,-1);
        return solve(n,height,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends