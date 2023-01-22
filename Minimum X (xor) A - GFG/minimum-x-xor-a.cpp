//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        int cnt=0;
        while(b!=0)
        {
            cnt++;
            b=b&(b-1);
        }
        vector<int>A(32,0),X(32,0);
        for(int i=0;i<32;i++)
        {
            if(a&(1<<i))
            {
                A[i]=1;
            }
        }
        for(int i=31;i>=0&&cnt!=0;i--)
        {
            if(A[i]==1)
            {
                X[i]=1;
                cnt--;
            }
        }
        if(cnt!=0)
        {
            for(int i=0;i<32&&cnt!=0;i++)
            {
                if(X[i]==0)
                {
                    X[i]=1;
                    cnt--;
                }
            }
        }
        int num=0;
        for(int i=32;i>=0;i--)
        {
            num<<=1;
            if(X[i]==1)
            {
                num|=1;
            }
        }
        return num;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends