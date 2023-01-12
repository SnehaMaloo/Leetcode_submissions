//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++



class Solution{
  public:
  int carAssembly(vector<vector<int>>& a, vector<vector<int>>& T, vector<int>& e, vector<int>& x){
      pair<int,int>p1,p2;
      p1={e[0]+a[0][0],e[0]+a[0][0]};
      p2={e[1]+a[1][0],e[1]+a[1][0]};
      int n=a[0].size();
      for(int i=1;i<n;i++)
      {
          pair<int,int>temp1,temp2;
          temp1={min(p1.first,p1.second)+a[0][i],min(p2.first,p2.second)+T[1][i]+a[0][i]};
          temp2={min(p2.first,p2.second)+a[1][i],min(p1.first,p1.second)+T[0][i]+a[1][i]};
          //cout<<temp1.first<<" "<<temp1.second<<" "<<temp2.first<<" "<<temp2.second<<endl;
          p1=temp1;
          p2=temp2;  //19 28 24 31
      }
      int x1=min(p1.first,p1.second)+x[0];
      int y1=min(p2.first,p2.second)+x[1];
      return min(x1,y1);
  }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> a(2,vector<int>(n)), T(2,vector<int>(n));
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin>>T[i][j];
            }
        }   
        vector<int> e(2), x(2);
        for(int i=0;i<2;i++){
            cin>>e[i];
        }
        for(int i=0;i<2;i++){
            cin>>x[i];
        }
        
        Solution ob;
        int ans = ob.carAssembly(a,T,e,x);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends