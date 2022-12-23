//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int perfectSum(int nums[], int n, int s)
	{   //int sum=0;
	    int M=1e9+7;
        // for(auto i:nums){
        //     sum+=i;
        // }
        // int s=(sum+target)/2;
        // if((sum+target)%2==1)return 0;
        // if(sum<abs(target))
        // {
        //     return 0;
        // }
        // int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(s+1,0));
        // 1)initialisation
        for(int col=1;col<s+1;col++){
            dp[0][col]=0;
        }
        dp[0][0]=1;
        for(int row=1;row<n+1;row++){
                dp[row][0]=1;
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=0;j<s+1;j++){
                // 2)choices
                if(nums[i-1]<=j){
                    dp[i][j]=(dp[i-1][j-nums[i-1]]+dp[i-1][j])%M;
                }
                else{
                    dp[i][j]=dp[i-1][j]%M;
                }
            }
        }
        return dp[n][s]%M;
    
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