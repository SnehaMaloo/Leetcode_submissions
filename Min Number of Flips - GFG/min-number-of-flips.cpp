//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int minFlips (string S)
{
    int n=S.length();
    int prev=0,cnt1=0,cnt2=0;
    for(int i=0;i<n;i++)
    {
        if(prev!=(S[i]-'0'))
        {
            cnt1++;
        }
        prev=1-prev;
    }
    prev=1;
    for(int i=0;i<n;i++)
    {
         if(prev!=(S[i]-'0'))
        {
            cnt2++;
        }
        prev=1-prev;
    }
    return min(cnt1,cnt2);
}