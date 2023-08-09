//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    int n=s.length();
    if(n%2!=0)
    {
        return -1;
    }
    int count=0,ans=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='}')
        {
            count--;
            if(count<0)
            {
                count=1;
                ans++;
            }
        }
        else
        {
            count++;
        }
    }
    return ans+(count/2);
}