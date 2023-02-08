//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) cin >> a[i];
        cout << findElement(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends


int findElement(int arr[], int n) {
    vector<int>arr1(n,-1);
    int max_ele=-1,min_ele=INT_MAX;
    for(int i=0;i<n;i++)
    {
        max_ele=max(max_ele,arr[i]);
        if(arr[i]==max_ele)
        {
            arr1[i]=1;
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        min_ele=min(min_ele,arr[i]);
        if(min_ele==arr[i])
        {
            arr1[i]++;
        }
    }
    for(int i=1;i<n-1;i++)
    {
        if(arr1[i]==2)
        {
            return arr[i];
        }
    }
    return -1;
}