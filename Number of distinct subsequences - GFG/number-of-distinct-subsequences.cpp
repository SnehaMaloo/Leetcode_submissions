//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
  
	int distinctSubsequences(string str)
	{
	    int n=str.length();
	    int M=1e9+7;
	    vector<int>dp(n+1,0);
	    vector<int>last(256,-1);
	    dp[0]=1;
	    for(int i=1;i<=n;i++)
	    {
	        dp[i]=(2*dp[i-1])%M;
	        if(last[str[i-1]]!=-1)
	        {
	            dp[i]=(dp[i]-dp[last[str[i-1]]]+M)%M;
	        }
	        last[str[i-1]]=i-1;
	    }
	    return (dp[n]+M)%M;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends