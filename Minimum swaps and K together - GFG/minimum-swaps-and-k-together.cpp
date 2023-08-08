//{ Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        int i=0,j=0;
        int cnt=0;
        while(j<n)
        {
            if(arr[j]<=k)
            {
                cnt++;
            }
            j++;
        }
        i=0,j=0;
        int ans=INT_MAX;
        int lu=cnt;
        cnt=0;
        while(j<n)
        {
            if(arr[j]<=k)
            {
                cnt++;
            }
            if(j-i+1<lu)
            {
                j++;
            }
            else
            {
                ans=min(ans,lu-cnt);
                if(arr[i]<=k)
                {
                    cnt--;
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}

// } Driver Code Ends