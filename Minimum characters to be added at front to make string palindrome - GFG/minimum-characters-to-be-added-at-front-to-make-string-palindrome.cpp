//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int minChar(string str){
        string s=str;
        reverse(s.begin(),s.end());
        str=str+"&"+s;
       int n=str.length();
       int lps[n]={0};
       int j=0;
       int max_le=0;
       for(int i=1;i<n;)
       {
           if(str[i]==str[j])
           {
               lps[i]=j+1;
               j++;
               i++;
           }
           else if(j!=0)
           {
               j=lps[j-1];
           }
           else
           {
               i++;
           }
       }
       return (n/2)-lps[n-1];
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends