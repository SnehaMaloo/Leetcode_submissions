//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int dp[505];
    int solve(int i,vector<int>&nums,int k)
    {   int n=nums.size();
        if(i==n)
        {
            return 0;
        }
        else if(dp[i]!=-1)
        {
            return dp[i];
        }
        int ans=INT_MAX,sum=0;
        for(int j=i;j<nums.size();j++)
        {
            sum+=nums[j];
            if(j!=n-1 && sum<=k)
            {
                ans=min(ans,(k-sum)*(k-sum)+solve(j+1,nums,k));
            }
            else if(sum<=k)
            {
                ans=min(ans,solve(j+1,nums,k));
            }
            sum++;
        }
        return dp[i]=ans;
    }
    int solveWordWrap(vector<int>nums, int k) 
    { 
        memset(dp,-1,sizeof(dp));
        return solve(0,nums,k);
    } 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends