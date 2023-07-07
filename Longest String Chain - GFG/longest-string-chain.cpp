//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  bool ischeck(string &a,string &b)
    {
        if(a.length()==(b.length()-1))
        {
            int cnt=0;
            int j=0;
           for(int i=0;i<a.length() && j<b.length();i++)
           {
               if(a[i]!=b[j])
               {
                   i--;
                   cnt++;
               }
               j++;
           }
           return cnt<=1;
        }
        return false;
    }
    static bool compare(string &a,string &b)
    {
        return a.length()<b.length();
    }
    int longestChain(int n, vector<string>& words) {
        sort(words.begin(),words.end(),compare);
        vector<int>dp(n+1,1);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(ischeck(words[j],words[i]) && (dp[j]+1)>dp[i])
                {
                    //cout<<words[j]<<" "<<words[i]<<endl;
                    dp[i]=dp[j]+1;
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> words(N);
        for (int i = 0; i < N; i++) {
            cin >> words[i];
        }
        Solution obj;
        cout << obj.longestChain(N, words) << "\n";
    }
    return 0;
}
// } Driver Code Ends