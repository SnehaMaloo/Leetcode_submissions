//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int solve(int M[MAX],int m)
    {
        stack<int>st;
        int i,area=0;
        for(int i=0;i<m;i++)
        {
            while(!st.empty()&&M[st.top()]>=M[i])
            {
                int x=st.top();
                st.pop();
                int y=st.empty()?-1:st.top();
                area=max(area,(i-y-1)*M[x]);
            }
            st.push(i);
        }
        while(!st.empty())
        {
            int x=st.top();
            st.pop();
            int y=st.empty()?-1:st.top();
            area=max(area,(m-y-1)*M[x]);
        }
        return area;
    }
    int maxArea(int M[MAX][MAX], int n, int m) {
        int ans=0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(M[i][j]!=0)
                {
                    M[i][j]+=M[i-1][j];
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            ans=max(ans,solve(M[i],m));
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends