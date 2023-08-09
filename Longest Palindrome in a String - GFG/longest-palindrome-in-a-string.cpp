//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
        int n=S.length();
        vector<int>p(2*n+1,0);
        string str="#";
        for(int i=0;i<n;i++)
        {
            str.push_back(S[i]);
            str.push_back('#');
        }
        //cout<<str<<endl;
        int center=0,right=0,left=0,longestcenterleft=0,longestpalindrome=0,longestcenterright=0;
        for(int i=0;i<2*n+1;i++)
        {
            int mirror=2*center-i;
            if(right>i)
            {
                p[i]=min(p[mirror],right-i);
            }
            int a=i+(p[i]+1);
            int b=i-(p[i]+1);
            while(b>=0 && a<(2*n+1) && str[a]==str[b])
            {
                b--;
                a++;
                p[i]++;
            }
            if(i+p[i]>right)
            {
                center=i;
                right=i+p[i];
                left=i-p[i];
            }
             if(p[i]>longestpalindrome)
            {
                longestpalindrome=p[i];
                longestcenterleft=left;
                longestcenterright=right;
            }
        }
        string res="";
        for(int i=longestcenterleft;i<=longestcenterright;i++)
        {
            if(str[i]!='#')
            {
                res+=str[i];
            }
        }
        return res;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends