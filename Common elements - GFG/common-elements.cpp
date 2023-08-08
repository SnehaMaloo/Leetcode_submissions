//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            vector<int>res;
            int i=0,j=0,k=0;
            while(i<n1 && j<n2 && k<n3)
            {
                int max_ele=max(A[i],max(B[j],C[k]));
                while(i<n1 && A[i]<max_ele)
                {
                    i++;
                }
                while(j<n2 && B[j]<max_ele)
                {
                    j++;
                }
                while(k<n3 && C[k]<max_ele)
                {
                    k++;
                }
                if(A[i]==B[j]&& B[j]==C[k])
                {
                    if(res.size()==0 || A[i]!=res[res.size()-1])
                    {
                        res.push_back(A[i]);
                    }
                    i++;
                    j++;
                    k++;
                }
            }
            return res;
        }

};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}
// } Driver Code Ends