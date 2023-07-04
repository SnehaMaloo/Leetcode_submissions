//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        long long int xor0=0,xor1=0,xor2=0;
        for(int i=0;i<N;i++)
        {
            xor0^=Arr[i];
        }
        long long int bitset=xor0&(~(xor0-1));
        for(int i=0;i<N;i++)
        {
            if(bitset&Arr[i])
            {
                xor1^=Arr[i];
            }
            else
            {
                xor2^=Arr[i];
            }
        }
      if(xor1>xor2)
      {
          return {xor1,xor2};
      }
      else
      {
          return {xor2,xor1};
      }
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends