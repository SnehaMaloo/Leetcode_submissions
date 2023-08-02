//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


bool compare(pair<int,pair<int,int>>&a,pair<int,pair<int,int>>&b)
{
    if(a.first==b.first)
    {
        return a.second.first<b.second.first;
    }
    return a.first>b.first;
}

int countbits(int n)
{
    int cnt=0;
    while(n!=0)
    {
        n=n&(n-1);
        cnt++;
    }
    return cnt;
}
class Solution{
    public:
    void sortBySetBitCount(int arr[], int n)
    {
        vector<pair<int,pair<int,int>>>vc;
        for(int i=0;i<n;i++)
        {
            int cnt=countbits(arr[i]);
            vc.push_back({cnt,{i,arr[i]}});
        }
        sort(vc.begin(),vc.end(),compare);
        for(int i=0;i<n;i++)
        {
            arr[i]=vc[i].second.second;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends