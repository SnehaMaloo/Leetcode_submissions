//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
    void solve(int i,char prev,string&res,string &S)
    {
        if(i==S.length())
        {
            return ;
        }
        if(S[i]==prev)
        {
            solve(i+1,prev,res,S);
        }
        else
        {
            res.push_back(S[i]);
            solve(i+1,S[i],res,S);
        }
    }
    string removeConsecutiveCharacter(string S)
    {
       string res="";
       char prev='&';
       solve(0,prev,res,S);
       return res;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 




// } Driver Code Ends