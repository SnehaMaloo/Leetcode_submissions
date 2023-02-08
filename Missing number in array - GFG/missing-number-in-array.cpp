//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;




// } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int MissingNumber(vector<int>& array, int n) {
        int m=array.size();
        int xor1=0;
        if(n%4==0)
        {
            xor1=n;
        }
        else if(n%4==1)
        {
            xor1=1;
        }
        else if(n%4==2)
        {
            xor1=n+1;
        }
        else
        {
            xor1=0;
        }
        for(int i=0;i<m;i++)
        {
            xor1^=array[i];
        }
        return xor1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        Solution obj;
        cout << obj.MissingNumber(array, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends