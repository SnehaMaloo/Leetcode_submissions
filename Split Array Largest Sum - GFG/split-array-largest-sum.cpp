//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool ischeck(int arr[],int N,int K,int mid)
    {
        int sum=0;
        int cnt=1;
        for(int i=0;i<N;i++)
        {
            if(sum+arr[i]>mid)
            {
                sum=0;
                cnt++;
            }
            sum+=arr[i];
        }
        return cnt<=K;
    }
    int splitArray(int arr[] ,int N, int K) {
        int low=*max_element(arr,arr+N),high=accumulate(arr,arr+N,0);
        int ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(ischeck(arr,N,K,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends