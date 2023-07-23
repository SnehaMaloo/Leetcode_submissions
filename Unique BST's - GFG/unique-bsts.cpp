//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the total number of possible unique BST. 
    long long int dp[1002];
    long long int M=1e9+7;
    long long int solve(int N)
    {
        if(N==0)
        {
            return 1;
        }
        else if(N<=2)
        {
            return N;
        }
        else if(dp[N]!=-1)
        {
            return dp[N];
        }
        else
        {
            long long int ans=0;
            for(int i=1;i<=N;i++)
            {
                long long int left=solve(i-1);
                long long int right=solve(N-i);
                ans=ans%M+((left%M)*(right%M)%M);
                ans=ans%M;
            }
            return dp[N]=ans;
        }
    }
    int numTrees(int N) 
    {
       memset(dp,-1,sizeof(dp));
       return solve(N);
    }
};

//{ Driver Code Starts.
#define mod (int)(1e9+7)
int main(){
    
    //taking total testcases
    int t;
    cin>>t;
    while(t--){
        
        //taking total number of elements
        int n;
        cin>>n;
        Solution ob;
        //calling function numTrees()
        cout<<ob.numTrees(n)<<"\n";
    }
}	
// } Driver Code Ends