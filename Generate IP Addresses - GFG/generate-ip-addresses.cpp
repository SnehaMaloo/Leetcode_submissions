//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    void solve(int i,string &s,int n,string &curr,int k,vector<string>&res)
    {
        if(i==n)
        {
            if(k==0)
            {
                res.push_back(curr);
            }
            return;
        }
        int sum=0;
        string temp=curr;
        if(s[i]=='0')
        {
            curr.push_back('0');
            
                if(k-1!=0)
                {
                     curr.push_back('.');
                }
                solve(i+1,s,n,curr,k-1,res);
                if(k-1!=0)
                {
                     curr.pop_back();
                }
            
        }
        else
        {
        for(int j=i;j<n;j++)
        {
            sum=sum*10+s[j]-'0';
            curr.push_back(s[j]);
            if(sum<=255)
            {
                if(k-1!=0)
                {
                     curr.push_back('.');
                }
                solve(j+1,s,n,curr,k-1,res);
                if(k-1!=0)
                {
                     curr.pop_back();
                }
            }
            else
            {
                break;
            }
        }
        }
        curr=temp;
    }
    vector<string> genIp(string &s) {
       vector<string>res;
       int n=s.length();
       string curr="";
        solve(0,s,n,curr,4,res);
        return res;
    }

};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}
// } Driver Code Ends