//{ Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int transform (string A, string B)
    {
       int n=A.size();
       int m=B.size();
       vector<int>curr(256,0);
       for(int i=0;i<n;i++)
       {
           curr[A[i]]++;
       }
       for(int j=0;j<m;j++)
       {
           curr[B[j]]--;
       }
       for(int i=0;i<256;i++)
       {
           if(curr[i]!=0)
           {
               return -1;
           }
       }
       int res=0;
       int i=n-1,j=m-1;
       while(j>=0 && i>=0)
       {
           if(A[i]==B[j])
           {
               i--;
               j--;
           }
           else
           {
               i--;
               res++;
           }
       }
       return res;
    }
};


//{ Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}
// } Driver Code Ends