//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int NumberofLIS(int n, vector<int>&arr) {
        vector<int>dp(n+1,1);
        vector<int>cnt(n+1,1);
        int maxval=0;
        for(int i=0;i<n;i++)
        {
       
            for(int j=0;j<i;j++)
            {
                if(arr[j]<arr[i] && dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                    cnt[i]=cnt[j];
                }
                else if(arr[j]<arr[i] && dp[j]+1==dp[i])
                {
                    cnt[i]+=cnt[j];
                }
            }
            maxval=max(maxval,dp[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(dp[i]==maxval)
            {
                ans+=cnt[i];
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        cout<<obj.NumberofLIS(n, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends