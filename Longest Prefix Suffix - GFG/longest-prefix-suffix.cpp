//{ Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++

class Solution{
  public:		
	int lps(string s) {
	    int n=s.length();
	    vector<int>lps(n,0);
	    int j=0;
	    for(int i=1;i<n;)
	    {
	        if(s[i]==s[j])
	        {
	            lps[i]=j+1;
	            j++;
	            i++;
	        }
	        else
	        {
	            if(j!=0)
	            {
	                j=lps[j-1];
	            }
	            else
	            {
	                i++;
	            }
	        }
	    }
	    return lps[n-1];
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
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}

// } Driver Code Ends