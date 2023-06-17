//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<int>dp(W+1,0);
       for(int i=n-1;i>=0;i--)
       {
           vector<int>curr(W+1,0);
           for(int j=0;j<=W;j++)
           {
               int taken=0;
               int nottaken=0;
               if(j>=wt[i])
               {
                   taken=val[i]+dp[j-wt[i]];
               }
               nottaken=dp[j];
               curr[j]=max(taken,nottaken);
           }
           dp=curr;
       }
       return dp[W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends