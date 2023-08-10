//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int minimumNumberOfSwaps(string S){
        int n=S.length();
        int cnt=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(S[i]==']')
            {
                cnt--;
            }
            else
            {
                if(cnt<0)
                {
                    ans+=abs(cnt);
                }
                    cnt++;
            }
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
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
} 
// } Driver Code Ends