//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
//   int dp[105][1005];
//     bool rec(vector<int> &arr, int sum,int i){
//         if(sum==0) return true;
//         if(i>=arr.size()){
//             return false;
//         }
//         // if(i==arr.size())
//         // {
//         //     if(sum==0)
//         //     {
//         //         return true;
//         //     }
//         //     return false;
//         // }
//         if (dp[i][sum] != -1)
//         {   
//             return dp[i][sum];
            
//         }
//         if(arr[i]>sum)
//       { 
//         return dp[i][sum]=rec(arr,sum,i+1);
//       }
//         return dp[i][sum]=rec(arr,sum-arr[i],i+1)||rec(arr,sum,i+1);
// }
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<vector<bool>>dp(2,vector<bool>(sum+1,false));
        dp[n%2][0]=true;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=sum;j++)
            {
                 if(arr[i]>j)
                { 
                    dp[i%2][j]=dp[(i+1)%2][j];
                }
                else {dp[i%2][j]=dp[(i+1)%2][j-arr[i]]||dp[(i+1)%2][j];}
            }
        }
        return dp[0][sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends