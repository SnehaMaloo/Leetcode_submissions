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
        for(auto i:arr){
            sum+=i;
        }
        int s=(sum+d)/2;
        if((sum+d)%2==1){
            return 0;
        }
        

        int mod=1e9+7;
        
        vector<vector<int>>dp(n+1,vector<int>(s+1,0));
        //1)inititalisation
        for(int col=1;col<s+1;col++){
            dp[0][col]=0;
        }
        dp[0][0]=1;
        for(int row=1;row<n+1;row++){
            if(arr[row-1]==0)
            {
                dp[row][0]=2*dp[row-1][0];
            }
            else{dp[row][0]=1;}
        }
       
        for(int i=1;i<n+1;i++){
            for(int j=0;j<s+1;j++){
                if(arr[i-1]<=j){
                    dp[i][j]=(dp[i-1][j-arr[i-1]]+dp[i-1][j])%mod;
                }
                else{dp[i][j]=(dp[i-1][j])%mod;}
            }
        }
        return (dp[n][s])%mod;
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