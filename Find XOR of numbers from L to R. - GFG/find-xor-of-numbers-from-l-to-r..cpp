//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int getf(int num)
    {
        if(num%4==0)
        {
            return num;
        }
        else if(num%4==1)
        {
            return 1;
        }
        else if(num%4==2)
        {
            return num+1;
        }
        else
        {
            return 0;
        }
    }
    int findXOR(int l, int r) {
        int xor1=0;
        int xor2=0;
        xor1=getf(l-1);
        xor2=getf(r);
        return xor2^xor1;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        // Input

        int l, r;
        cin >> l >> r;

        Solution obj;
        cout << obj.findXOR(l, r) << endl;
    }
}
// } Driver Code Ends