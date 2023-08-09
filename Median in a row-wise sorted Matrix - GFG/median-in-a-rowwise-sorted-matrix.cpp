//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int R, int C){
       int lo=INT_MAX;
       int high=INT_MIN;
       for(int i=0;i<R;i++)
       {
           lo=min(lo,matrix[i][0]);
           high=max(high,matrix[i][C-1]);
       }
       int ans=0,ele=(R*C)/2;
       while(lo<=high)
       {
           int mid=lo+(high-lo)/2;
           int cnt=0;
           for(int i=0;i<R;i++)
           {
               cnt+=lower_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
           }
           if(cnt<=ele)
           {
               ans=mid;
               lo=mid+1;
           }
           else
           {
               high=mid-1;
           }
       }
       return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends