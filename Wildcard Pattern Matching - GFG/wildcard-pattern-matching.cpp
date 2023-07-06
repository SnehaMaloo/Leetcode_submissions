//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/

    // bool solve(int i,int j,string &pat,string &str,vector<vector<int>>&dp)
    // {
    //     if(j==0)
    //     {
    //         while(i!=0)
    //         {
    //             if(pat[i-1]!='*')
    //             {
    //                 return false;
    //             }
    //             i--;
    //         }
    //         return true;
    //     }
    //     else if(i==0)
    //     {
    //         return false;
    //     }
    //     else if(dp[i][j]!=-1)
    //     {
    //         return dp[i][j];
    //     }
    //     else if(pat[i-1]==str[j-1])
    //     {
    //         return dp[i][j]=solve(i-1,j-1,pat,str,dp);
    //     }
    //     else if(pat[i-1]=='?')
    //     {
    //         return dp[i][j]=solve(i-1,j-1,pat,str);
    //     }
    //     else if(pat[i-1]=='*')
    //     {
    //         for(int k=j;k>=0;k--)
    //         {
    //             dp[i][j]=dp[i][j]||solve(i-1,k-1,pat,str);
    //         }
    //         return dp[i][j];
    //     }
    //     else
    //     {
    //         return dp[i][j]=false;
    //     }
    // }
    int wildCard(string pat,string str)
    {
        int n=str.length();
        int m=pat.length();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        dp[0][0]=true;
        for(int j=1;j<=m;j++)
        {
            if(pat[j-1]=='*')
            {
                dp[0][j]=true;
            }
            else
            {break;}
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(str[i-1]==pat[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(pat[j-1]=='?')
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(pat[j-1]=='*')
                {
                    for(int k=i;k>=1;k--)
                    {
                        dp[i][j]=dp[i][j]||(dp[k-1][j-1]);
                    }
                    dp[i][j]=dp[i][j]||dp[i][j-1];
                }
                else
                {
                    dp[i][j]=false;
                }
            }
        }
        return dp[n][m];
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends