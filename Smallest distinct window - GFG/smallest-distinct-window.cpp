//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        unordered_map<char,int>mp,copy;
        int n=str.size(),len=n;
        for(int i=0;i<n;i++)
        {
            mp[str[i]]++;
        }
        int i=0,j=0;
        while(j<n)
        {
            copy[str[j]]++;
            if(copy.size()==mp.size())
            {
                //len=min(len,j-i+1);
                while(i<=j && copy.size()==mp.size())
                {
                    len=min(len,j-i+1);
                    copy[str[i]]--;
                    if(copy[str[i]]==0)
                    {
                        copy.erase(str[i]);
                    }
                    i++;
                }
            }
            j++;
        }
        return len;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends