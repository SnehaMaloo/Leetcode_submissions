//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    int dp[501][501];
public:

    int f(int row, int col,vector<vector<int>>&m,int n ){ //row and col is the index
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        if(row==(n-1)){
            
            return dp[row][col]=m[row][col];
        }
        
        int left_down=0;
        int right_down=0;
        int down=0;
        if((row+1 )<n ){
            if((col-1)>=0){
                left_down=f(row+1,col-1,m,n)+m[row][col];
            }
            if((col+1)<n){
                right_down=f(row+1,col+1,m,n)+m[row][col];
            }
            down=f(row+1,col,m,n)+m[row][col];
        }
        return dp[row][col]=max(left_down, max(right_down, down));
    }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        int ans=0;
        int maxi=0;
        memset(dp,-1,sizeof(dp));
        for(int col=0;col<N;col++){
            ans=f(0,col,Matrix,N);
            maxi=max(ans,maxi);
            
        }
        return maxi;
    }

};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends