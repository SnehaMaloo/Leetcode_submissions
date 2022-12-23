//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int perfectSum(int nums[], int n, int target)
	{
        // for(auto i:nums){
        //     sum+=i;
        // }
        // int s=(sum+target)/2;
        // if((sum+target)%2==1)return 0;
        // if(sum<abs(target))
        // {
        //     return 0;
        // }
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        // 1)initialisation
        int mod=1e9+7;
        for(int col=1;col<target+1;col++){
            dp[0][col]=0;
        }
        dp[0][0]=1;
        for(int row=1;row<n+1;row++){
                dp[row][0]=1;
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=0;j<target+1;j++){
                // 2)choices
                if(nums[i-1]<=j){
                    dp[i][j]=(dp[i-1][j-nums[i-1]]+dp[i-1][j])%mod;
                }
                else{
                    dp[i][j]=dp[i-1][j]%mod;
                }
            }
        }
        return dp[n][target];
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends