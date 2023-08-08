//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      int dp[100005]={0};
      for(int i=0;i<N;i++)
      {
          dp[arr[i]]++;
      }
      int cnt=1,ans=1;
      for(int i=0;i<100005;i++)
      {
          if(dp[i]>0 && dp[i+1]>0)
          {
              cnt++;
              ans=max(ans,cnt);
          }
          else
          {
              cnt=1;
          }
      }
      return ans;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends