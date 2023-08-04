//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int m=1e9+7;
    int countFriendsPairings(int n) 
    { 
        long long int a=1;
        long long int b=1;
        long long int ans=1;
        for(int i=2;i<=n;i++)
        {
            ans=(b%m+(i-1)*a%m)%m;
            a=b;
            b=ans;
        }
        return ans;
    }
};    
 

//{ Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends