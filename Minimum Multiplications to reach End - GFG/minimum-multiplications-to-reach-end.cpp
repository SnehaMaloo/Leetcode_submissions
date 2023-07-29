//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
int M=1e5;
class Solution {
  public:
    int minimumMultiplications(vector<int>& a, int start, int end) {
        // vector<int>dp(100006,-1);
        // queue<long long int>q;
        // q.push(start%M);
        // dp[start%M]=0;
        // int cnt=0;
        // end=end%M;
        // while(!q.empty())
        // {
        //     int size=q.size();
        //     while(size--)
        //     {
        //         long long int x=q.front();
        //         q.pop();
        //         dp[x]=cnt;
        //         if(x==end)
        //         {
        //             return cnt;
        //         }
        //         else
        //         {
        //             for(int i=0;i<arr.size();i++)
        //             {
        //                 long  long int mult=(x*arr[i])%M;
        //                 if(mult<=end)
        //                 {
        //                     if(dp[mult]==-1)
        //                     {
        //                         dp[mult]=dp[x]+1;
        //                         q.push(mult);
                                
        //                     }
        //                 }
        //             }
        //         }
        //     }
        //     cnt++;
        // }
        // return -1;
         int ans[100001];
 
    // -1 indicated the state has not been visited
    memset(ans, -1, sizeof(ans));
    int mod = 100000;
 
 int n=a.size();
    // queue to store all possible states
    queue<int> q;
 
    // initially push the start
    q.push(start % mod);
 
    // to reach start we require 0 steps
    ans[start] = 0;
 
    // till all states are visited
    while (!q.empty()) {
 
        // get the topmost element in the queue
        int top = q.front();
 
        // pop the topmost element
        q.pop();
 
        // if the topmost element is end
        if (top == end)
            return ans[end];
 
        // perform multiplication with all array elements
        for (int i = 0; i < n; i++) {
            int pushed = top * a[i];
            pushed = pushed % mod;
 
            // if not visited, then push it to queue
            if (ans[pushed] == -1) {
                ans[pushed] = ans[top] + 1;
                q.push(pushed);
            }
        }
    }
    return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends