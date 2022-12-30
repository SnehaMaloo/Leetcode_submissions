//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[201][2005];
    int rec(int nums[],int sum,int i,int N){
    if(i==N)
    {
        if(sum==0)
        {
            return dp[i][sum]=1;
        }
        return dp[i][sum]=0;
    }
    if(dp[i][sum]!=-1) return dp[i][sum];
    if(nums[i]<=sum)
    {return dp[i][sum]=rec(nums,sum-nums[i],i+1,N)||rec(nums,sum,i+1,N) ;}
    else {return dp[i][sum]=rec(nums,sum,i+1,N) ;}
}

   
    int equalPartition(int N, int nums[])
    {
        // code here
         memset(dp,-1,sizeof(dp));
        int target=0;
        for(int i=0;i<N;i++){
            target+=nums[i];
        }
      
        if(target%2!=0) return 0;
        return rec(nums,target/2,0,N);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends