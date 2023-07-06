//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string str1, string str2) 
	{ 
	   int n1=str1.length();
	   int n2=str2.length();
	   vector<vector<int>>dp(n1+1,vector<int>(n2+1,n1+n2));
	   for(int j=0;j<=n2;j++)
	   {
	       dp[n1][j]=n2-j;
	   }
	   for(int i=0;i<=n1;i++)
	   {
	       dp[i][n2]=n1-i;
	   }
	   for(int i=n1-1;i>=0;i--)
	   {
	       for(int j=n2-1;j>=0;j--)
	       {
	           if(str1[i]==str2[j])
	           {
	               dp[i][j]=dp[i+1][j+1];
	           }
	           else
	           {
	               dp[i][j]=1+min(dp[i+1][j],dp[i][j+1]);
	           }
	       }
	   }
	   return dp[0][0];
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends