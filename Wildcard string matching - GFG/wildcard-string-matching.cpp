//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    bool match(string wild, string pattern)
    {
        int n=wild.size();
        int m=pattern.size();
        vector<bool>dp(m+1,false);
        dp[0]=true;
        for(int j=0;j<n;j++)
        {
           if(wild[j]!='*')
           {
               break;
           }
            dp[j]=true;
        }
        for(int i=1;i<=n;i++)
        {
            vector<bool>curr(m+1,false);
            for(int j=1;j<=m;j++)
            {
                if(wild[i-1]==pattern[j-1])
                {
                    curr[j]=dp[j-1];
                }
                else if(wild[i-1]=='?')
                {
                   curr[j]=dp[j-1];
                }
                else if(wild[i-1]=='*')
                {
                    curr[j]=dp[j-1]||curr[j-1]||dp[j];
                }
            }
            dp=curr;
        }
        return dp[m];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends