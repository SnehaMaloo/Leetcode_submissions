//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> LargestSubset(int n, vector<int>& arr) {
        vector<int>dp(n+1,1);
        vector<int>hash(n+1,-1);
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
            for(int j=0;j<i;j++)
            {
                if(((arr[i]%arr[j]==0) || (arr[j]%arr[i]==0)) && dp[i]<(dp[j]+1))
                {
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
        }
        int ans=-1;
        int lastidx=-1;
        for(int i=0;i<n;i++)
        {
            if(dp[i]>ans)
            {
                ans=dp[i];
                lastidx=i;
            }
        }
        vector<int>res;
        res.push_back(arr[lastidx]);
        while(lastidx!=hash[lastidx])
        {
            lastidx=hash[lastidx];
            res.push_back(arr[lastidx]);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        vector<int> res = obj.LargestSubset(n, arr);
        int isValidSeq = 1, sz = res.size();
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                if ((res[i] % res[j]) == 0 || (res[j] % res[i]) == 0)
                    continue;
                else {
                    isValidSeq = 0;
                    break;
                }
            }
        }
        cout << isValidSeq << " " << sz << endl;
    }
    return 0;
}
// } Driver Code Ends